/*
 * Instance header file for PIC32CM5112GC00100_FPGA
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version  */
#ifndef _PIC32CMGC00_HPB0_INSTANCE_
#define _PIC32CMGC00_HPB0_INSTANCE_


/* ========== Instance Parameter definitions for HPB0 peripheral ========== */
#define HPB0_BASE_MSB                            (13)       /* derived parameter */
#define HPB0_BRIDGE_ID                           (0)        /* H2PB Bridge ID */
#define HPB0_CLK_DIV_EN                          (0)        /* 1="n:1 clock"0="1:1 clock" */
#define HPB0_INSTANCE_ID                         (19)       /* Instance index for HPB0 */
#define HPB0_MCLK_ID_AHB                         (25)       /* Index for HPB0 AHB clock */
#define HPB0_MCLK_ID_APB                         (26)       /* Index for HPB0 APB clock */
#define HPB0_MST_MAX                             (1)        /* derived parameter */
#define HPB0_MST_N                               (2)        /* -- */
#define HPB0_NONSEC_INIT_VAL                     (0x00000001) /* -- */
#define HPB0_OWN_SFR_SLOT                        (25)       /* -- */
#define HPB0_PAC_ID                              (19)       /* Index for HPB0 registers write protection */
#define HPB0_PADDR_IDXB                          (5)        /* derived parameter */
#define HPB0_PADDR_LSB                           (13)       /* -- */
#define HPB0_PADDR_MSB                           (17)       /* derived local parameter */
#define HPB0_PADDR_SIZE                          (18)       /* local parameter */
#define HPB0_PAGE_SIZE                           (8192)     /* derived parameter */
#define HPB0_PERIPH_ID                           (25)       /* H2PB Peripheral ID */
#define HPB0_SLV_MAX                             (31)       /* derived parameter */
#define HPB0_SLV_N                               (32)       /* -- */
#define HPB0_TDM_ID                              (3)        /* TDM ID */
#define HPB0_USE_DPATH_PIPER                     (0)        /* 1="all pipelined"0="address pipelined" */
#define HPB0_USE_EARLY_PREAD                     (0)        /* -- */
#define HPB0_USE_HSEL                            (1)        /* -- */
#define HPB0_USE_PSTRB_FOR_READS                 (1)        /* -- */
#define HPB0_WPCTRL_IMPLEMENTED                  (0)        /* -- */
#define HPB0_WPCTRL_KEY                          (0x504230) /* -- */

#endif /* _PIC32CMGC00_HPB0_INSTANCE_ */
