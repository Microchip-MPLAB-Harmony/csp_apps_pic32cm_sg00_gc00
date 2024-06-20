/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include <string.h>
#include <stdio.h>

#define DAC_OUTPUT_INITIAL_VAL  40      // Configured in MHC

volatile bool ac_comparator_output_level = false;
volatile bool ac_comparison_done = false;
uint8_t console_input = 0;
volatile bool read_done = false;
uint8_t dac_out = DAC_OUTPUT_INITIAL_VAL;
char printbuffer[100];

void usart_read_callback(uintptr_t context)
{    
    read_done = true;
}

void ac_callBack(uint8_t int_flag, uintptr_t ac_context)
{
    ac_comparison_done = true;
    
    /* Check the comparator output state */
    if(int_flag & AC_STATUSA_STATE0_Msk)
    {
        ac_comparator_output_level  = 1;
    }
    else
    {
        ac_comparator_output_level = 0;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
float DAC_OutputVol(uint8_t dac_out)
{
    return (3.3 * dac_out)/128.0;
}

int main ( void )
{
    uint8_t n = 0;
    
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    RTC_Timer32Start();

    AC_CallbackRegister(ac_callBack, 0);
    
    SERCOM4_USART_ReadCallbackRegister(usart_read_callback, 0);

    SERCOM4_USART_Write("Press U to increment and D to decrement the DAC output connected to Comparator0 Positive Input\r\n", 
            strlen("Press U to increment and D to decrement the DAC output connected to Comparator0 Positive Input\r\n"));
    
    while (SERCOM4_USART_WriteIsBusy());
    
    n = sprintf(printbuffer, "DAC Output = %.5fV\r\n", DAC_OutputVol(dac_out));                
    SERCOM4_USART_Write(printbuffer, n);
    
    while (SERCOM4_USART_WriteIsBusy());
    
    SERCOM4_USART_Read(&console_input, 1);        
    
    while ( true )
    {
        PM_StandbyModeEnter();
        
        if (read_done == true)
        {
            read_done = false;            
            
            if (console_input == 'U' || console_input == 'u')
            {
                // Increment DAC output by about 0.1V
                dac_out += 4;
                if (dac_out >= 127)
                {
                    dac_out = 127;
                }                     
            }
            else if (console_input == 'D' || console_input == 'd')
            {            
                // Decrement DAC output by about 0.1V
                if (dac_out >= 4)
                {
                    dac_out -= 4;
                }    
                else
                {
                    dac_out = 0;
                }
            }

            AC_SetDACOutput(AC_CHANNEL0, dac_out);

            n = sprintf(printbuffer, "DAC Output = %.5fV\r\n", DAC_OutputVol(dac_out));

            SERCOM4_USART_Write(printbuffer, n);
            
            while (SERCOM4_USART_WriteIsBusy());
            
            SERCOM4_USART_Read(&console_input, 1);
        }
        if(ac_comparison_done == true)
        {   
            ac_comparison_done = false;                        

            if(ac_comparator_output_level == 1)
            {
                SERCOM4_USART_Write("Voltage is above detect level\r\n", strlen("Voltage is above detect level\r\n"));
            }
            else
            {
                SERCOM4_USART_Write("Voltage is below detect level\r\n", strlen("Voltage is below detect level\r\n"));
            }
            while (SERCOM4_USART_WriteIsBusy());
        }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

