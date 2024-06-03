/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
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

#define MINIMUM_DMA_BUFFER_SIZE              (32)
#define ADC_VREF                             (3.3f)

static __attribute__ ((aligned (32))) uint32_t adc_fifo_data[MINIMUM_DMA_BUFFER_SIZE];

static volatile bool DMA_transferDone = false;
static volatile bool ADC_EOS_Done = false;
float adc_inp_vol[2];
uint8_t chid;
uint16_t adc_result;
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
void ADC_EventHandler(ADC_CORE_INT status, uintptr_t context)
{
    if (status & ADC_CORE_INT_EOSRDY)
    {
        ADC_EOS_Done = true;
    }
}

void DMA_EventHandler (DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
    if (event == DMAC_TRANSFER_EVENT_COMPLETE)
    {        
        DMA_transferDone = true;        
    }       
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    printf("\r\n *********************************************** \r\n\n");
    printf("\r\n           ADC DMA SCAN DEMO \r\n ");
    printf("\r\n *********************************************** \r");
    
    ADC_CORE0CallbackRegister(ADC_EventHandler, 0);
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, DMA_EventHandler, 0);
    DMAC_ChannelTransfer(DMAC_CHANNEL_0, (const void *)&ADC_REGS->ADC_PFFDATA, adc_fifo_data, 8);  
    RTC_Timer32Start();
    printf("\n");
    
    while ( true )
    {
        if (DMA_transferDone == true && ADC_EOS_Done == true) 
        {
			DMA_transferDone = false;
            ADC_EOS_Done = false;
            
            /* Invalidate the cache lines before reading ADC FIFO data */
            DCACHE_INVALIDATE_BY_ADDR((uint32_t *)adc_fifo_data, sizeof(adc_fifo_data));
            
            chid = ADC_FIFO_CHNID_GET(adc_fifo_data[0]); 
            adc_result = ADC_FIFO_DATA_GET(adc_fifo_data[0]); 
            adc_inp_vol[chid] = (float)adc_result * ADC_VREF / 4095U;
            
            printf("\r\n ADC0_AIN%d: ADC Count: 0x%03x, ADC Input Voltage = %d.%02d V \r\n", 
                    chid, adc_result, (int)adc_inp_vol[chid], (int)((adc_inp_vol[chid] - (int)adc_inp_vol[chid])*100));
            
            chid = ADC_FIFO_CHNID_GET(adc_fifo_data[1]);            
            adc_result = ADC_FIFO_DATA_GET(adc_fifo_data[1]); 
            adc_inp_vol[chid] = (float)adc_result * ADC_VREF / 4095U;
            
            printf("\r\n ADC0_AIN%d: ADC Count: 0x%03x, ADC Input Voltage = %d.%02d V \r\n\r\n", 
                    chid, adc_result, (int)adc_inp_vol[chid], (int)((adc_inp_vol[chid] - (int)adc_inp_vol[chid])*100));
		
            DMAC_ChannelTransfer(DMAC_CHANNEL_0, (const void *)&ADC_REGS->ADC_PFFDATA, adc_fifo_data, 8);  
        }       
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/