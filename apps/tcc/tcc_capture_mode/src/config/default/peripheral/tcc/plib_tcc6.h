/*******************************************************************************
  Timer/Counter(TCC6) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_tcc6.h

  Summary
    TCC6 PLIB Header File.

  Description
    This file defines the interface to the TCC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

#ifndef PLIB_TCC6_H       // Guards against multiple inclusion
#define PLIB_TCC6_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "device.h"
#include "plib_tcc_common.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/* The following data type definitions are used by the functions in this
    interface and should be considered part it.
*/

/* TCC Channel numbers

   Summary:
    Identifies channel number within TCC module

   Description:
    This enumeration identifies TCC channel number.

   Remarks:
    None.
*/
typedef enum
{
    TCC6_CHANNEL0,
    TCC6_CHANNEL1,
}TCC6_CHANNEL_NUM;

typedef enum
{
    TCC6_CAPTURE_STATUS_OVF = TCC_INTFLAG_OVF_Msk,
    TCC6_CAPTURE_STATUS_ERR = TCC_INTFLAG_ERR_Msk,
    TCC6_CAPTURE_STATUS_MC_0 = TCC_INTFLAG_MC0_Msk,
    TCC6_CAPTURE_STATUS_MC_1 = TCC_INTFLAG_MC1_Msk,
}TCC6_CAPTURE_STATUS;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
/* The following functions make up the methods (set of possible operations) of
   this interface.
*/


void TCC6_CaptureInitialize ( void );

void TCC6_CaptureStart ( void );

void TCC6_CaptureStop ( void );

uint32_t TCC6_CaptureFrequencyGet( void );

uint16_t TCC6_Capture16bitValueGet( TCC6_CHANNEL_NUM channel );
uint16_t TCC6_Capture16bitCounterGet( void );


void TCC6_CaptureCommandSet(TCC_COMMAND command);

void TCC6_CaptureCallbackRegister( TCC_CALLBACK callback, uintptr_t context );


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END

#endif /* PLIB_TCC6_H */
