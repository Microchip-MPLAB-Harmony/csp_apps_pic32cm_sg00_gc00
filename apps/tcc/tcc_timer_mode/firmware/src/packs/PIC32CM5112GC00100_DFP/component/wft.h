/*
 * Component description for WFT
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
#ifndef _PIC32CMGC00_WFT_COMPONENT_H_
#define _PIC32CMGC00_WFT_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR WFT                                          */
/* ************************************************************************** */

/* -------- WFT_WFCON1 : (WFT Offset: 0x00) (R/W 16) Wafer Flash Test Control Register -------- */
#define WFT_WFCON1_RESETVALUE                 _UINT16_(0x00)                                       /*  (WFT_WFCON1) Wafer Flash Test Control Register  Reset Value */

#define WFT_WFCON1_ADDRINC_Pos                _UINT16_(0)                                          /* (WFT_WFCON1) Address Auto-Increment Enable bit Position */
#define WFT_WFCON1_ADDRINC_Msk                (_UINT16_(0x1) << WFT_WFCON1_ADDRINC_Pos)            /* (WFT_WFCON1) Address Auto-Increment Enable bit Mask */
#define WFT_WFCON1_ADDRINC(value)             (WFT_WFCON1_ADDRINC_Msk & (_UINT16_(value) << WFT_WFCON1_ADDRINC_Pos)) /* Assigment of value for ADDRINC in the WFT_WFCON1 register */
#define WFT_WFCON1_DATAINV_Pos                _UINT16_(1)                                          /* (WFT_WFCON1) Data Invert Enable bit Position */
#define WFT_WFCON1_DATAINV_Msk                (_UINT16_(0x1) << WFT_WFCON1_DATAINV_Pos)            /* (WFT_WFCON1) Data Invert Enable bit Mask */
#define WFT_WFCON1_DATAINV(value)             (WFT_WFCON1_DATAINV_Msk & (_UINT16_(value) << WFT_WFCON1_DATAINV_Pos)) /* Assigment of value for DATAINV in the WFT_WFCON1 register */
#define WFT_WFCON1_DAT2ADR_Pos                _UINT16_(2)                                          /* (WFT_WFCON1) Compare golden data (WFRDATA) will use the address of data being rea Position */
#define WFT_WFCON1_DAT2ADR_Msk                (_UINT16_(0x1) << WFT_WFCON1_DAT2ADR_Pos)            /* (WFT_WFCON1) Compare golden data (WFRDATA) will use the address of data being rea Mask */
#define WFT_WFCON1_DAT2ADR(value)             (WFT_WFCON1_DAT2ADR_Msk & (_UINT16_(value) << WFT_WFCON1_DAT2ADR_Pos)) /* Assigment of value for DAT2ADR in the WFT_WFCON1 register */
#define WFT_WFCON1_RMODE_Pos                  _UINT16_(3)                                          /* (WFT_WFCON1) Data Read Mode bits Position */
#define WFT_WFCON1_RMODE_Msk                  (_UINT16_(0x3) << WFT_WFCON1_RMODE_Pos)              /* (WFT_WFCON1) Data Read Mode bits Mask */
#define WFT_WFCON1_RMODE(value)               (WFT_WFCON1_RMODE_Msk & (_UINT16_(value) << WFT_WFCON1_RMODE_Pos)) /* Assigment of value for RMODE in the WFT_WFCON1 register */
#define WFT_WFCON1_DBG_EN_Pos                 _UINT16_(6)                                          /* (WFT_WFCON1) Debug Status Enable Bit   (See Note 1 - VALID in Pin Mode ONLY) Position */
#define WFT_WFCON1_DBG_EN_Msk                 (_UINT16_(0x1) << WFT_WFCON1_DBG_EN_Pos)             /* (WFT_WFCON1) Debug Status Enable Bit   (See Note 1 - VALID in Pin Mode ONLY) Mask */
#define WFT_WFCON1_DBG_EN(value)              (WFT_WFCON1_DBG_EN_Msk & (_UINT16_(value) << WFT_WFCON1_DBG_EN_Pos)) /* Assigment of value for DBG_EN in the WFT_WFCON1 register */
#define WFT_WFCON1_FP_CLK_EN_Pos              _UINT16_(7)                                          /* (WFT_WFCON1) Flash Panel Clock Enable Bit Position */
#define WFT_WFCON1_FP_CLK_EN_Msk              (_UINT16_(0x1) << WFT_WFCON1_FP_CLK_EN_Pos)          /* (WFT_WFCON1) Flash Panel Clock Enable Bit Mask */
#define WFT_WFCON1_FP_CLK_EN(value)           (WFT_WFCON1_FP_CLK_EN_Msk & (_UINT16_(value) << WFT_WFCON1_FP_CLK_EN_Pos)) /* Assigment of value for FP_CLK_EN in the WFT_WFCON1 register */
#define WFT_WFCON1_WIDTH16_Pos                _UINT16_(8)                                          /* (WFT_WFCON1) Wafer Test Data Out Bus Width  (See Note 1 - VALID in Pin Mode ONLY) Position */
#define WFT_WFCON1_WIDTH16_Msk                (_UINT16_(0x1) << WFT_WFCON1_WIDTH16_Pos)            /* (WFT_WFCON1) Wafer Test Data Out Bus Width  (See Note 1 - VALID in Pin Mode ONLY) Mask */
#define WFT_WFCON1_WIDTH16(value)             (WFT_WFCON1_WIDTH16_Msk & (_UINT16_(value) << WFT_WFCON1_WIDTH16_Pos)) /* Assigment of value for WIDTH16 in the WFT_WFCON1 register */
#define WFT_WFCON1_LAS_EN_Pos                 _UINT16_(9)                                          /* (WFT_WFCON1) Logical Address Scrambling Enable bit Position */
#define WFT_WFCON1_LAS_EN_Msk                 (_UINT16_(0x1) << WFT_WFCON1_LAS_EN_Pos)             /* (WFT_WFCON1) Logical Address Scrambling Enable bit Mask */
#define WFT_WFCON1_LAS_EN(value)              (WFT_WFCON1_LAS_EN_Msk & (_UINT16_(value) << WFT_WFCON1_LAS_EN_Pos)) /* Assigment of value for LAS_EN in the WFT_WFCON1 register */
#define WFT_WFCON1_VREFOE_Pos                 _UINT16_(10)                                         /* (WFT_WFCON1) Voltage Reference Output Enable bit Position */
#define WFT_WFCON1_VREFOE_Msk                 (_UINT16_(0x1) << WFT_WFCON1_VREFOE_Pos)             /* (WFT_WFCON1) Voltage Reference Output Enable bit Mask */
#define WFT_WFCON1_VREFOE(value)              (WFT_WFCON1_VREFOE_Msk & (_UINT16_(value) << WFT_WFCON1_VREFOE_Pos)) /* Assigment of value for VREFOE in the WFT_WFCON1 register */
#define WFT_WFCON1_EXTVREF_VREFDIS_Pos        _UINT16_(11)                                         /* (WFT_WFCON1) Voltage Reference Source Selection bit ) Position */
#define WFT_WFCON1_EXTVREF_VREFDIS_Msk        (_UINT16_(0x1) << WFT_WFCON1_EXTVREF_VREFDIS_Pos)    /* (WFT_WFCON1) Voltage Reference Source Selection bit ) Mask */
#define WFT_WFCON1_EXTVREF_VREFDIS(value)     (WFT_WFCON1_EXTVREF_VREFDIS_Msk & (_UINT16_(value) << WFT_WFCON1_EXTVREF_VREFDIS_Pos)) /* Assigment of value for EXTVREF_VREFDIS in the WFT_WFCON1 register */
#define WFT_WFCON1_STP_ERR_Pos                _UINT16_(12)                                         /* (WFT_WFCON1) Stop on Compare Error Enable bit Position */
#define WFT_WFCON1_STP_ERR_Msk                (_UINT16_(0x1) << WFT_WFCON1_STP_ERR_Pos)            /* (WFT_WFCON1) Stop on Compare Error Enable bit Mask */
#define WFT_WFCON1_STP_ERR(value)             (WFT_WFCON1_STP_ERR_Msk & (_UINT16_(value) << WFT_WFCON1_STP_ERR_Pos)) /* Assigment of value for STP_ERR in the WFT_WFCON1 register */
#define WFT_WFCON1_CNT_ERR_Pos                _UINT16_(13)                                         /* (WFT_WFCON1) Compare Error Counting enable bit. Position */
#define WFT_WFCON1_CNT_ERR_Msk                (_UINT16_(0x1) << WFT_WFCON1_CNT_ERR_Pos)            /* (WFT_WFCON1) Compare Error Counting enable bit. Mask */
#define WFT_WFCON1_CNT_ERR(value)             (WFT_WFCON1_CNT_ERR_Msk & (_UINT16_(value) << WFT_WFCON1_CNT_ERR_Pos)) /* Assigment of value for CNT_ERR in the WFT_WFCON1 register */
#define WFT_WFCON1_TM01OE_Pos                 _UINT16_(14)                                         /* (WFT_WFCON1) TM0 and TM1 Output Enable Position */
#define WFT_WFCON1_TM01OE_Msk                 (_UINT16_(0x1) << WFT_WFCON1_TM01OE_Pos)             /* (WFT_WFCON1) TM0 and TM1 Output Enable Mask */
#define WFT_WFCON1_TM01OE(value)              (WFT_WFCON1_TM01OE_Msk & (_UINT16_(value) << WFT_WFCON1_TM01OE_Pos)) /* Assigment of value for TM01OE in the WFT_WFCON1 register */
#define WFT_WFCON1_VPPDIVOE_Pos               _UINT16_(15)                                         /* (WFT_WFCON1) VPPDIV Output Enable Position */
#define WFT_WFCON1_VPPDIVOE_Msk               (_UINT16_(0x1) << WFT_WFCON1_VPPDIVOE_Pos)           /* (WFT_WFCON1) VPPDIV Output Enable Mask */
#define WFT_WFCON1_VPPDIVOE(value)            (WFT_WFCON1_VPPDIVOE_Msk & (_UINT16_(value) << WFT_WFCON1_VPPDIVOE_Pos)) /* Assigment of value for VPPDIVOE in the WFT_WFCON1 register */
#define WFT_WFCON1_Msk                        _UINT16_(0xFFDF)                                     /* (WFT_WFCON1) Register Mask  */

#define WFT_WFCON1_WIDTH_Pos                  _UINT16_(8)                                          /* (WFT_WFCON1 Position) Wafer Test Data Out Bus Width  (See Note x - VALID in Pin Mode ONLY) */
#define WFT_WFCON1_WIDTH_Msk                  (_UINT16_(0x1) << WFT_WFCON1_WIDTH_Pos)              /* (WFT_WFCON1 Mask) WIDTH */
#define WFT_WFCON1_WIDTH(value)               (WFT_WFCON1_WIDTH_Msk & (_UINT16_(value) << WFT_WFCON1_WIDTH_Pos)) 

/* -------- WFT_WFCON2 : (WFT Offset: 0x02) (R/W 16) Wafer Flash Test Control Register -------- */
#define WFT_WFCON2_RESETVALUE                 _UINT16_(0x00)                                       /*  (WFT_WFCON2) Wafer Flash Test Control Register  Reset Value */

#define WFT_WFCON2_INC_VALA_Pos               _UINT16_(0)                                          /* (WFT_WFCON2) Increment value for WFADRx  WFWDATx register andUsed whenever ADR_INCA or WDAT_INCA command is executed Position */
#define WFT_WFCON2_INC_VALA_Msk               (_UINT16_(0xFFF) << WFT_WFCON2_INC_VALA_Pos)         /* (WFT_WFCON2) Increment value for WFADRx  WFWDATx register andUsed whenever ADR_INCA or WDAT_INCA command is executed Mask */
#define WFT_WFCON2_INC_VALA(value)            (WFT_WFCON2_INC_VALA_Msk & (_UINT16_(value) << WFT_WFCON2_INC_VALA_Pos)) /* Assigment of value for INC_VALA in the WFT_WFCON2 register */
#define WFT_WFCON2_Msk                        _UINT16_(0x0FFF)                                     /* (WFT_WFCON2) Register Mask  */


/* -------- WFT_WFCON3 : (WFT Offset: 0x04) (R/W 16) Wafer Flash Test Control Register -------- */
#define WFT_WFCON3_RESETVALUE                 _UINT16_(0x00)                                       /*  (WFT_WFCON3) Wafer Flash Test Control Register  Reset Value */

#define WFT_WFCON3_INC_VALB_Pos               _UINT16_(0)                                          /* (WFT_WFCON3) Increment value for WFADRx,  WFWDATx register and Used whenever ADR_INCB or WDAT_INCB command is executed and is automatically used under certain conditions Position */
#define WFT_WFCON3_INC_VALB_Msk               (_UINT16_(0xFFF) << WFT_WFCON3_INC_VALB_Pos)         /* (WFT_WFCON3) Increment value for WFADRx,  WFWDATx register and Used whenever ADR_INCB or WDAT_INCB command is executed and is automatically used under certain conditions Mask */
#define WFT_WFCON3_INC_VALB(value)            (WFT_WFCON3_INC_VALB_Msk & (_UINT16_(value) << WFT_WFCON3_INC_VALB_Pos)) /* Assigment of value for INC_VALB in the WFT_WFCON3 register */
#define WFT_WFCON3_Msk                        _UINT16_(0x0FFF)                                     /* (WFT_WFCON3) Register Mask  */


/* -------- WFT_WFCON4 : (WFT Offset: 0x06) (R/W 16) Wafer Flash Test Control Register -------- */
#define WFT_WFCON4_RESETVALUE                 _UINT16_(0x0F)                                       /*  (WFT_WFCON4) Wafer Flash Test Control Register  Reset Value */

#define WFT_WFCON4_WFCEB_Pos                  _UINT16_(0)                                          /* (WFT_WFCON4) Controls active low Chip Enable Signal for each panel (equivalent to TSMC XE) Position */
#define WFT_WFCON4_WFCEB_Msk                  (_UINT16_(0xF) << WFT_WFCON4_WFCEB_Pos)              /* (WFT_WFCON4) Controls active low Chip Enable Signal for each panel (equivalent to TSMC XE) Mask */
#define WFT_WFCON4_WFCEB(value)               (WFT_WFCON4_WFCEB_Msk & (_UINT16_(value) << WFT_WFCON4_WFCEB_Pos)) /* Assigment of value for WFCEB in the WFT_WFCON4 register */
#define WFT_WFCON4_PS_Pos                     _UINT16_(4)                                          /* (WFT_WFCON4) Panel Select Bits Position */
#define WFT_WFCON4_PS_Msk                     (_UINT16_(0xF) << WFT_WFCON4_PS_Pos)                 /* (WFT_WFCON4) Panel Select Bits Mask */
#define WFT_WFCON4_PS(value)                  (WFT_WFCON4_PS_Msk & (_UINT16_(value) << WFT_WFCON4_PS_Pos)) /* Assigment of value for PS in the WFT_WFCON4 register */
#define WFT_WFCON4_Msk                        _UINT16_(0x00FF)                                     /* (WFT_WFCON4) Register Mask  */


/* -------- WFT_WFCON5 : (WFT Offset: 0x08) (R/W 16) Wafer Flash Test Control Register -------- */
#define WFT_WFCON5_RESETVALUE                 _UINT16_(0x80)                                       /*  (WFT_WFCON5) Wafer Flash Test Control Register  Reset Value */

#define WFT_WFCON5_WFRETRY_Pos                _UINT16_(0)                                          /* (WFT_WFCON5) Erase Retry Control Position */
#define WFT_WFCON5_WFRETRY_Msk                (_UINT16_(0x3) << WFT_WFCON5_WFRETRY_Pos)            /* (WFT_WFCON5) Erase Retry Control Mask */
#define WFT_WFCON5_WFRETRY(value)             (WFT_WFCON5_WFRETRY_Msk & (_UINT16_(value) << WFT_WFCON5_WFRETRY_Pos)) /* Assigment of value for WFRETRY in the WFT_WFCON5 register */
#define WFT_WFCON5_WFVREAD1_Pos               _UINT16_(2)                                          /* (WFT_WFCON5) Verify Read for Erased cells Position */
#define WFT_WFCON5_WFVREAD1_Msk               (_UINT16_(0x1) << WFT_WFCON5_WFVREAD1_Pos)           /* (WFT_WFCON5) Verify Read for Erased cells Mask */
#define WFT_WFCON5_WFVREAD1(value)            (WFT_WFCON5_WFVREAD1_Msk & (_UINT16_(value) << WFT_WFCON5_WFVREAD1_Pos)) /* Assigment of value for WFVREAD1 in the WFT_WFCON5 register */
#define WFT_WFCON5_WFSRHT_Pos                 _UINT16_(5)                                          /* (WFT_WFCON5) Slow Read for 150 degree C high temperature enable bit Position */
#define WFT_WFCON5_WFSRHT_Msk                 (_UINT16_(0x1) << WFT_WFCON5_WFSRHT_Pos)             /* (WFT_WFCON5) Slow Read for 150 degree C high temperature enable bit Mask */
#define WFT_WFCON5_WFSRHT(value)              (WFT_WFCON5_WFSRHT_Msk & (_UINT16_(value) << WFT_WFCON5_WFSRHT_Pos)) /* Assigment of value for WFSRHT in the WFT_WFCON5 register */
#define WFT_WFCON5_WFRDEN_Pos                 _UINT16_(6)                                          /* (WFT_WFCON5) Controls FLASH input RDEN Signal Position */
#define WFT_WFCON5_WFRDEN_Msk                 (_UINT16_(0x1) << WFT_WFCON5_WFRDEN_Pos)             /* (WFT_WFCON5) Controls FLASH input RDEN Signal Mask */
#define WFT_WFCON5_WFRDEN(value)              (WFT_WFCON5_WFRDEN_Msk & (_UINT16_(value) << WFT_WFCON5_WFRDEN_Pos)) /* Assigment of value for WFRDEN in the WFT_WFCON5 register */
#define WFT_WFCON5_RECALL_Pos                 _UINT16_(7)                                          /* (WFT_WFCON5) Wafer Test Recall Enable bit Position */
#define WFT_WFCON5_RECALL_Msk                 (_UINT16_(0x1) << WFT_WFCON5_RECALL_Pos)             /* (WFT_WFCON5) Wafer Test Recall Enable bit Mask */
#define WFT_WFCON5_RECALL(value)              (WFT_WFCON5_RECALL_Msk & (_UINT16_(value) << WFT_WFCON5_RECALL_Pos)) /* Assigment of value for RECALL in the WFT_WFCON5 register */
#define WFT_WFCON5_ADR_DAT_Pos                _UINT16_(8)                                          /* (WFT_WFCON5) Use byte address WFADRx as the word programming data WFWDAT enable bit. Position */
#define WFT_WFCON5_ADR_DAT_Msk                (_UINT16_(0x1) << WFT_WFCON5_ADR_DAT_Pos)            /* (WFT_WFCON5) Use byte address WFADRx as the word programming data WFWDAT enable bit. Mask */
#define WFT_WFCON5_ADR_DAT(value)             (WFT_WFCON5_ADR_DAT_Msk & (_UINT16_(value) << WFT_WFCON5_ADR_DAT_Pos)) /* Assigment of value for ADR_DAT in the WFT_WFCON5 register */
#define WFT_WFCON5_WFNVR_Pos                  _UINT16_(12)                                         /* (WFT_WFCON5) Controls NVR Space Select Signal (equivalent to TSMC IFREN) Position */
#define WFT_WFCON5_WFNVR_Msk                  (_UINT16_(0x1) << WFT_WFCON5_WFNVR_Pos)              /* (WFT_WFCON5) Controls NVR Space Select Signal (equivalent to TSMC IFREN) Mask */
#define WFT_WFCON5_WFNVR(value)               (WFT_WFCON5_WFNVR_Msk & (_UINT16_(value) << WFT_WFCON5_WFNVR_Pos)) /* Assigment of value for WFNVR in the WFT_WFCON5 register */
#define WFT_WFCON5_Msk                        _UINT16_(0x11E7)                                     /* (WFT_WFCON5) Register Mask  */

#define WFT_WFCON5_WFVREAD_Pos                _UINT16_(2)                                          /* (WFT_WFCON5 Position) Verify Read for Erased cells */
#define WFT_WFCON5_WFVREAD_Msk                (_UINT16_(0x1) << WFT_WFCON5_WFVREAD_Pos)            /* (WFT_WFCON5 Mask) WFVREAD */
#define WFT_WFCON5_WFVREAD(value)             (WFT_WFCON5_WFVREAD_Msk & (_UINT16_(value) << WFT_WFCON5_WFVREAD_Pos)) 

/* -------- WFT_WFCON6 : (WFT Offset: 0x0A) (R/W 16) Wafer Flash Test Control Register -------- */
#define WFT_WFCON6_RESETVALUE                 _UINT16_(0x00)                                       /*  (WFT_WFCON6) Wafer Flash Test Control Register  Reset Value */

#define WFT_WFCON6_WFARRDN_Pos                _UINT16_(0)                                          /* (WFT_WFCON6) Controls Access to Redundant Array Space Signals (ARRDN[7:0]) Position */
#define WFT_WFCON6_WFARRDN_Msk                (_UINT16_(0x3) << WFT_WFCON6_WFARRDN_Pos)            /* (WFT_WFCON6) Controls Access to Redundant Array Space Signals (ARRDN[7:0]) Mask */
#define WFT_WFCON6_WFARRDN(value)             (WFT_WFCON6_WFARRDN_Msk & (_UINT16_(value) << WFT_WFCON6_WFARRDN_Pos)) /* Assigment of value for WFARRDN in the WFT_WFCON6 register */
#define WFT_WFCON6_Msk                        _UINT16_(0x0003)                                     /* (WFT_WFCON6) Register Mask  */


/* -------- WFT_WFCON7 : (WFT Offset: 0x0C) (R/W 16) Wafer Flash Test Control Register -------- */
#define WFT_WFCON7_RESETVALUE                 _UINT16_(0x04)                                       /*  (WFT_WFCON7) Wafer Flash Test Control Register  Reset Value */

#define WFT_WFCON7_WFCHIP_Pos                 _UINT16_(0)                                          /* (WFT_WFCON7) Controls Chip Erase Cycle Definition Signal (similar to TSMC MAS1) Position */
#define WFT_WFCON7_WFCHIP_Msk                 (_UINT16_(0x1) << WFT_WFCON7_WFCHIP_Pos)             /* (WFT_WFCON7) Controls Chip Erase Cycle Definition Signal (similar to TSMC MAS1) Mask */
#define WFT_WFCON7_WFCHIP(value)              (WFT_WFCON7_WFCHIP_Msk & (_UINT16_(value) << WFT_WFCON7_WFCHIP_Pos)) /* Assigment of value for WFCHIP in the WFT_WFCON7 register */
#define WFT_WFCON7_WFTMEN_Pos                 _UINT16_(1)                                          /* (WFT_WFCON7) Controls Flash IP Test Mode Entry and Test Code Write Position */
#define WFT_WFCON7_WFTMEN_Msk                 (_UINT16_(0x1) << WFT_WFCON7_WFTMEN_Pos)             /* (WFT_WFCON7) Controls Flash IP Test Mode Entry and Test Code Write Mask */
#define WFT_WFCON7_WFTMEN(value)              (WFT_WFCON7_WFTMEN_Msk & (_UINT16_(value) << WFT_WFCON7_WFTMEN_Pos)) /* Assigment of value for WFTMEN in the WFT_WFCON7 register */
#define WFT_WFCON7_WFWEB_Pos                  _UINT16_(2)                                          /* (WFT_WFCON7) Controls Non-volatile Store Cycle Definition Signal (similar to TSMC NVSTR) Position */
#define WFT_WFCON7_WFWEB_Msk                  (_UINT16_(0x1) << WFT_WFCON7_WFWEB_Pos)              /* (WFT_WFCON7) Controls Non-volatile Store Cycle Definition Signal (similar to TSMC NVSTR) Mask */
#define WFT_WFCON7_WFWEB(value)               (WFT_WFCON7_WFWEB_Msk & (_UINT16_(value) << WFT_WFCON7_WFWEB_Pos)) /* Assigment of value for WFWEB in the WFT_WFCON7 register */
#define WFT_WFCON7_WFPROG2_Pos                _UINT16_(3)                                          /* (WFT_WFCON7) Controls Y MUX Signal (similar to TSMC YE - only used during programming) Position */
#define WFT_WFCON7_WFPROG2_Msk                (_UINT16_(0x1) << WFT_WFCON7_WFPROG2_Pos)            /* (WFT_WFCON7) Controls Y MUX Signal (similar to TSMC YE - only used during programming) Mask */
#define WFT_WFCON7_WFPROG2(value)             (WFT_WFCON7_WFPROG2_Msk & (_UINT16_(value) << WFT_WFCON7_WFPROG2_Pos)) /* Assigment of value for WFPROG2 in the WFT_WFCON7 register */
#define WFT_WFCON7_WFERASE_Pos                _UINT16_(4)                                          /* (WFT_WFCON7) Controls Erase Cycle Definition Signal (similar to TSMC ERASE) Position */
#define WFT_WFCON7_WFERASE_Msk                (_UINT16_(0x1) << WFT_WFCON7_WFERASE_Pos)            /* (WFT_WFCON7) Controls Erase Cycle Definition Signal (similar to TSMC ERASE) Mask */
#define WFT_WFCON7_WFERASE(value)             (WFT_WFCON7_WFERASE_Msk & (_UINT16_(value) << WFT_WFCON7_WFERASE_Pos)) /* Assigment of value for WFERASE in the WFT_WFCON7 register */
#define WFT_WFCON7_WFPROG_Pos                 _UINT16_(5)                                          /* (WFT_WFCON7) Controls Program Cycle Definition Signal (similar to TSMC PROG) Position */
#define WFT_WFCON7_WFPROG_Msk                 (_UINT16_(0x1) << WFT_WFCON7_WFPROG_Pos)             /* (WFT_WFCON7) Controls Program Cycle Definition Signal (similar to TSMC PROG) Mask */
#define WFT_WFCON7_WFPROG(value)              (WFT_WFCON7_WFPROG_Msk & (_UINT16_(value) << WFT_WFCON7_WFPROG_Pos)) /* Assigment of value for WFPROG in the WFT_WFCON7 register */
#define WFT_WFCON7_WFNVR_CER_Pos              _UINT16_(6)                                          /* (WFT_WFCON7) Controls NVR Chip Erase Signal Position */
#define WFT_WFCON7_WFNVR_CER_Msk              (_UINT16_(0x1) << WFT_WFCON7_WFNVR_CER_Pos)          /* (WFT_WFCON7) Controls NVR Chip Erase Signal Mask */
#define WFT_WFCON7_WFNVR_CER(value)           (WFT_WFCON7_WFNVR_CER_Msk & (_UINT16_(value) << WFT_WFCON7_WFNVR_CER_Pos)) /* Assigment of value for WFNVR_CER in the WFT_WFCON7 register */
#define WFT_WFCON7_WFPREPG_Pos                _UINT16_(7)                                          /* (WFT_WFCON7) Pre-Program indicator Position */
#define WFT_WFCON7_WFPREPG_Msk                (_UINT16_(0x1) << WFT_WFCON7_WFPREPG_Pos)            /* (WFT_WFCON7) Pre-Program indicator Mask */
#define WFT_WFCON7_WFPREPG(value)             (WFT_WFCON7_WFPREPG_Msk & (_UINT16_(value) << WFT_WFCON7_WFPREPG_Pos)) /* Assigment of value for WFPREPG in the WFT_WFCON7 register */
#define WFT_WFCON7_Msk                        _UINT16_(0x00FF)                                     /* (WFT_WFCON7) Register Mask  */


/* -------- WFT_WFCON8 : (WFT Offset: 0x0E) (R/W 16) Wafer Flash Test Control Register -------- */
#define WFT_WFCON8_RESETVALUE                 _UINT16_(0x00)                                       /*  (WFT_WFCON8) Wafer Flash Test Control Register  Reset Value */

#define WFT_WFCON8_PAGE_SZ_Pos                _UINT16_(0)                                          /* (WFT_WFCON8) Page Size Control bits - Used to determine when a Page boundary has been crossed Position */
#define WFT_WFCON8_PAGE_SZ_Msk                (_UINT16_(0xF) << WFT_WFCON8_PAGE_SZ_Pos)            /* (WFT_WFCON8) Page Size Control bits - Used to determine when a Page boundary has been crossed Mask */
#define WFT_WFCON8_PAGE_SZ(value)             (WFT_WFCON8_PAGE_SZ_Msk & (_UINT16_(value) << WFT_WFCON8_PAGE_SZ_Pos)) /* Assigment of value for PAGE_SZ in the WFT_WFCON8 register */
#define WFT_WFCON8_ROW_SZ_Pos                 _UINT16_(4)                                          /* (WFT_WFCON8) Row Size Control bits - Used to determine when a data inversion skip should occur for checkerboard patterns. Position */
#define WFT_WFCON8_ROW_SZ_Msk                 (_UINT16_(0xF) << WFT_WFCON8_ROW_SZ_Pos)             /* (WFT_WFCON8) Row Size Control bits - Used to determine when a data inversion skip should occur for checkerboard patterns. Mask */
#define WFT_WFCON8_ROW_SZ(value)              (WFT_WFCON8_ROW_SZ_Msk & (_UINT16_(value) << WFT_WFCON8_ROW_SZ_Pos)) /* Assigment of value for ROW_SZ in the WFT_WFCON8 register */
#define WFT_WFCON8_Msk                        _UINT16_(0x00FF)                                     /* (WFT_WFCON8) Register Mask  */


/* -------- WFT_WFCON9 : (WFT Offset: 0x10) (R/W 16) Wafer Flash Test Control Register -------- */
#define WFT_WFCON9_RESETVALUE                 _UINT16_(0x00)                                       /*  (WFT_WFCON9) Wafer Flash Test Control Register  Reset Value */

#define WFT_WFCON9_WFLKCFG_Pos                _UINT16_(0)                                          /* (WFT_WFCON9) Lock Fuses : Used To latch configuration registers and disable fuse read circuitry. Position */
#define WFT_WFCON9_WFLKCFG_Msk                (_UINT16_(0x1) << WFT_WFCON9_WFLKCFG_Pos)            /* (WFT_WFCON9) Lock Fuses : Used To latch configuration registers and disable fuse read circuitry. Mask */
#define WFT_WFCON9_WFLKCFG(value)             (WFT_WFCON9_WFLKCFG_Msk & (_UINT16_(value) << WFT_WFCON9_WFLKCFG_Pos)) /* Assigment of value for WFLKCFG in the WFT_WFCON9 register */
#define WFT_WFCON9_WFPORB_Pos                 _UINT16_(4)                                          /* (WFT_WFCON9) Wafer Test Flash Voltage Domain Reset bit Position */
#define WFT_WFCON9_WFPORB_Msk                 (_UINT16_(0x1) << WFT_WFCON9_WFPORB_Pos)             /* (WFT_WFCON9) Wafer Test Flash Voltage Domain Reset bit Mask */
#define WFT_WFCON9_WFPORB(value)              (WFT_WFCON9_WFPORB_Msk & (_UINT16_(value) << WFT_WFCON9_WFPORB_Pos)) /* Assigment of value for WFPORB in the WFT_WFCON9 register */
#define WFT_WFCON9_WFDPD_Pos                  _UINT16_(14)                                         /* (WFT_WFCON9) Controls Flash IP Deep Power Down signal Position */
#define WFT_WFCON9_WFDPD_Msk                  (_UINT16_(0x1) << WFT_WFCON9_WFDPD_Pos)              /* (WFT_WFCON9) Controls Flash IP Deep Power Down signal Mask */
#define WFT_WFCON9_WFDPD(value)               (WFT_WFCON9_WFDPD_Msk & (_UINT16_(value) << WFT_WFCON9_WFDPD_Pos)) /* Assigment of value for WFDPD in the WFT_WFCON9 register */
#define WFT_WFCON9_Msk                        _UINT16_(0x4011)                                     /* (WFT_WFCON9) Register Mask  */


/* -------- WFT_WFSTAT1 : (WFT Offset: 0x12) (R/W 16) Wafer Flash Test Status Register -------- */
#define WFT_WFSTAT1_RESETVALUE                _UINT16_(0x00)                                       /*  (WFT_WFSTAT1) Wafer Flash Test Status Register  Reset Value */

#define WFT_WFSTAT1_Fail_status_Pos           _UINT16_(0)                                          /* (WFT_WFSTAT1) Read Mode Fail Status for flash read data comparison Position */
#define WFT_WFSTAT1_Fail_status_Msk           (_UINT16_(0xFF) << WFT_WFSTAT1_Fail_status_Pos)      /* (WFT_WFSTAT1) Read Mode Fail Status for flash read data comparison Mask */
#define WFT_WFSTAT1_Fail_status(value)        (WFT_WFSTAT1_Fail_status_Msk & (_UINT16_(value) << WFT_WFSTAT1_Fail_status_Pos)) /* Assigment of value for Fail_status in the WFT_WFSTAT1 register */
#define WFT_WFSTAT1_DOUT_RDY_Pos              _UINT16_(8)                                          /* (WFT_WFSTAT1) The Flash Panel Data Out Ready Output status Position */
#define WFT_WFSTAT1_DOUT_RDY_Msk              (_UINT16_(0x1) << WFT_WFSTAT1_DOUT_RDY_Pos)          /* (WFT_WFSTAT1) The Flash Panel Data Out Ready Output status Mask */
#define WFT_WFSTAT1_DOUT_RDY(value)           (WFT_WFSTAT1_DOUT_RDY_Msk & (_UINT16_(value) << WFT_WFSTAT1_DOUT_RDY_Pos)) /* Assigment of value for DOUT_RDY in the WFT_WFSTAT1 register */
#define WFT_WFSTAT1_FUSE_EN_Pos               _UINT16_(9)                                          /* (WFT_WFSTAT1) The flash Panel Fuse Enable Output Status. Position */
#define WFT_WFSTAT1_FUSE_EN_Msk               (_UINT16_(0x1) << WFT_WFSTAT1_FUSE_EN_Pos)           /* (WFT_WFSTAT1) The flash Panel Fuse Enable Output Status. Mask */
#define WFT_WFSTAT1_FUSE_EN(value)            (WFT_WFSTAT1_FUSE_EN_Msk & (_UINT16_(value) << WFT_WFSTAT1_FUSE_EN_Pos)) /* Assigment of value for FUSE_EN in the WFT_WFSTAT1 register */
#define WFT_WFSTAT1_RDx_DONE_Pos              _UINT16_(14)                                         /* (WFT_WFSTAT1) Current RDx_NVM command has completed Position */
#define WFT_WFSTAT1_RDx_DONE_Msk              (_UINT16_(0x1) << WFT_WFSTAT1_RDx_DONE_Pos)          /* (WFT_WFSTAT1) Current RDx_NVM command has completed Mask */
#define WFT_WFSTAT1_RDx_DONE(value)           (WFT_WFSTAT1_RDx_DONE_Msk & (_UINT16_(value) << WFT_WFSTAT1_RDx_DONE_Pos)) /* Assigment of value for RDx_DONE in the WFT_WFSTAT1 register */
#define WFT_WFSTAT1_GFAIL_Pos                 _UINT16_(15)                                         /* (WFT_WFSTAT1) Global Fail Status Position */
#define WFT_WFSTAT1_GFAIL_Msk                 (_UINT16_(0x1) << WFT_WFSTAT1_GFAIL_Pos)             /* (WFT_WFSTAT1) Global Fail Status Mask */
#define WFT_WFSTAT1_GFAIL(value)              (WFT_WFSTAT1_GFAIL_Msk & (_UINT16_(value) << WFT_WFSTAT1_GFAIL_Pos)) /* Assigment of value for GFAIL in the WFT_WFSTAT1 register */
#define WFT_WFSTAT1_Msk                       _UINT16_(0xC3FF)                                     /* (WFT_WFSTAT1) Register Mask  */


/* -------- WFT_WFPRO1 : (WFT Offset: 0x14) (R/W 16) Wafer Flash Test NVR Protect Register -------- */
#define WFT_WFPRO1_RESETVALUE                 _UINT16_(0xFFF)                                      /*  (WFT_WFPRO1) Wafer Flash Test NVR Protect Register  Reset Value */

#define WFT_WFPRO1_WFNVR_PRO_Pos              _UINT16_(0)                                          /* (WFT_WFPRO1) Controls NVR Space Write Protect Signals Position */
#define WFT_WFPRO1_WFNVR_PRO_Msk              (_UINT16_(0xFFF) << WFT_WFPRO1_WFNVR_PRO_Pos)        /* (WFT_WFPRO1) Controls NVR Space Write Protect Signals Mask */
#define WFT_WFPRO1_WFNVR_PRO(value)           (WFT_WFPRO1_WFNVR_PRO_Msk & (_UINT16_(value) << WFT_WFPRO1_WFNVR_PRO_Pos)) /* Assigment of value for WFNVR_PRO in the WFT_WFPRO1 register */
#define WFT_WFPRO1_Msk                        _UINT16_(0x0FFF)                                     /* (WFT_WFPRO1) Register Mask  */


/* -------- WFT_WFLAS1 : (WFT Offset: 0x18) (R/W 16) Wafer Flash Test Logical Address Scramble Register -------- */
#define WFT_WFLAS1_RESETVALUE                 _UINT16_(0x3210)                                     /*  (WFT_WFLAS1) Wafer Flash Test Logical Address Scramble Register  Reset Value */

#define WFT_WFLAS1_Y0_LAS_Pos                 _UINT16_(0)                                          /* (WFT_WFLAS1) Y0 Address  Logical Address Scramble - Logical to Physical Remap Position */
#define WFT_WFLAS1_Y0_LAS_Msk                 (_UINT16_(0x7) << WFT_WFLAS1_Y0_LAS_Pos)             /* (WFT_WFLAS1) Y0 Address  Logical Address Scramble - Logical to Physical Remap Mask */
#define WFT_WFLAS1_Y0_LAS(value)              (WFT_WFLAS1_Y0_LAS_Msk & (_UINT16_(value) << WFT_WFLAS1_Y0_LAS_Pos)) /* Assigment of value for Y0_LAS in the WFT_WFLAS1 register */
#define WFT_WFLAS1_Y1_LAS_Pos                 _UINT16_(4)                                          /* (WFT_WFLAS1) Y1 Address  Logical Address Scramble - Logical to Physical Remap Position */
#define WFT_WFLAS1_Y1_LAS_Msk                 (_UINT16_(0x7) << WFT_WFLAS1_Y1_LAS_Pos)             /* (WFT_WFLAS1) Y1 Address  Logical Address Scramble - Logical to Physical Remap Mask */
#define WFT_WFLAS1_Y1_LAS(value)              (WFT_WFLAS1_Y1_LAS_Msk & (_UINT16_(value) << WFT_WFLAS1_Y1_LAS_Pos)) /* Assigment of value for Y1_LAS in the WFT_WFLAS1 register */
#define WFT_WFLAS1_Y2_LAS_Pos                 _UINT16_(8)                                          /* (WFT_WFLAS1) Y2 Address  Logical Address Scramble - Logical to Physical Remap Position */
#define WFT_WFLAS1_Y2_LAS_Msk                 (_UINT16_(0x7) << WFT_WFLAS1_Y2_LAS_Pos)             /* (WFT_WFLAS1) Y2 Address  Logical Address Scramble - Logical to Physical Remap Mask */
#define WFT_WFLAS1_Y2_LAS(value)              (WFT_WFLAS1_Y2_LAS_Msk & (_UINT16_(value) << WFT_WFLAS1_Y2_LAS_Pos)) /* Assigment of value for Y2_LAS in the WFT_WFLAS1 register */
#define WFT_WFLAS1_Y3_LAS_Pos                 _UINT16_(12)                                         /* (WFT_WFLAS1) Y3 Address  Logical Address Scramble - Logical to Physical Remap Position */
#define WFT_WFLAS1_Y3_LAS_Msk                 (_UINT16_(0x7) << WFT_WFLAS1_Y3_LAS_Pos)             /* (WFT_WFLAS1) Y3 Address  Logical Address Scramble - Logical to Physical Remap Mask */
#define WFT_WFLAS1_Y3_LAS(value)              (WFT_WFLAS1_Y3_LAS_Msk & (_UINT16_(value) << WFT_WFLAS1_Y3_LAS_Pos)) /* Assigment of value for Y3_LAS in the WFT_WFLAS1 register */
#define WFT_WFLAS1_Msk                        _UINT16_(0x7777)                                     /* (WFT_WFLAS1) Register Mask  */


/* -------- WFT_WFLAS2 : (WFT Offset: 0x1A) (R/W 16) Wafer Flash Test Logical Address Scramble Register -------- */
#define WFT_WFLAS2_RESETVALUE                 _UINT16_(0x7654)                                     /*  (WFT_WFLAS2) Wafer Flash Test Logical Address Scramble Register  Reset Value */

#define WFT_WFLAS2_Y4_LAS_Pos                 _UINT16_(0)                                          /* (WFT_WFLAS2) Y4 Address  Logical Address Scramble - Logical to Physical Remap Position */
#define WFT_WFLAS2_Y4_LAS_Msk                 (_UINT16_(0x7) << WFT_WFLAS2_Y4_LAS_Pos)             /* (WFT_WFLAS2) Y4 Address  Logical Address Scramble - Logical to Physical Remap Mask */
#define WFT_WFLAS2_Y4_LAS(value)              (WFT_WFLAS2_Y4_LAS_Msk & (_UINT16_(value) << WFT_WFLAS2_Y4_LAS_Pos)) /* Assigment of value for Y4_LAS in the WFT_WFLAS2 register */
#define WFT_WFLAS2_Y5_LAS_Pos                 _UINT16_(4)                                          /* (WFT_WFLAS2) Y5 Address  Logical Address Scramble - Logical to Physical Remap Position */
#define WFT_WFLAS2_Y5_LAS_Msk                 (_UINT16_(0x7) << WFT_WFLAS2_Y5_LAS_Pos)             /* (WFT_WFLAS2) Y5 Address  Logical Address Scramble - Logical to Physical Remap Mask */
#define WFT_WFLAS2_Y5_LAS(value)              (WFT_WFLAS2_Y5_LAS_Msk & (_UINT16_(value) << WFT_WFLAS2_Y5_LAS_Pos)) /* Assigment of value for Y5_LAS in the WFT_WFLAS2 register */
#define WFT_WFLAS2_Y6_LAS_Pos                 _UINT16_(8)                                          /* (WFT_WFLAS2) Y6 Address  Logical Address Scramble - Logical to Physical Remap Position */
#define WFT_WFLAS2_Y6_LAS_Msk                 (_UINT16_(0x7) << WFT_WFLAS2_Y6_LAS_Pos)             /* (WFT_WFLAS2) Y6 Address  Logical Address Scramble - Logical to Physical Remap Mask */
#define WFT_WFLAS2_Y6_LAS(value)              (WFT_WFLAS2_Y6_LAS_Msk & (_UINT16_(value) << WFT_WFLAS2_Y6_LAS_Pos)) /* Assigment of value for Y6_LAS in the WFT_WFLAS2 register */
#define WFT_WFLAS2_Y7_LAS_Pos                 _UINT16_(12)                                         /* (WFT_WFLAS2) Y7 Address  Logical Address Scramble - Logical to Physical Remap Position */
#define WFT_WFLAS2_Y7_LAS_Msk                 (_UINT16_(0x7) << WFT_WFLAS2_Y7_LAS_Pos)             /* (WFT_WFLAS2) Y7 Address  Logical Address Scramble - Logical to Physical Remap Mask */
#define WFT_WFLAS2_Y7_LAS(value)              (WFT_WFLAS2_Y7_LAS_Msk & (_UINT16_(value) << WFT_WFLAS2_Y7_LAS_Pos)) /* Assigment of value for Y7_LAS in the WFT_WFLAS2 register */
#define WFT_WFLAS2_Msk                        _UINT16_(0x7777)                                     /* (WFT_WFLAS2) Register Mask  */


/* -------- WFT_WFADDR : (WFT Offset: 0x1C) (R/W 32) Wafer Flash Test Address Register -------- */
#define WFT_WFADDR_RESETVALUE                 _UINT32_(0x00)                                       /*  (WFT_WFADDR) Wafer Flash Test Address Register  Reset Value */

#define WFT_WFADDR_WFADR_Pos                  _UINT32_(2)                                          /* (WFT_WFADDR) Flash Panel Address Position */
#define WFT_WFADDR_WFADR_Msk                  (_UINT32_(0x3FFFFF) << WFT_WFADDR_WFADR_Pos)         /* (WFT_WFADDR) Flash Panel Address Mask */
#define WFT_WFADDR_WFADR(value)               (WFT_WFADDR_WFADR_Msk & (_UINT32_(value) << WFT_WFADDR_WFADR_Pos)) /* Assigment of value for WFADR in the WFT_WFADDR register */
#define WFT_WFADDR_Msk                        _UINT32_(0x00FFFFFC)                                 /* (WFT_WFADDR) Register Mask  */


/* -------- WFT_WFWDAT : (WFT Offset: 0x22) (R/W 16) Wafer Flash Test Write DATA Register -------- */
#define WFT_WFWDAT_RESETVALUE                 _UINT16_(0x00)                                       /*  (WFT_WFWDAT) Wafer Flash Test Write DATA Register  Reset Value */

#define WFT_WFWDAT_WDAT_Pos                   _UINT16_(0)                                          /* (WFT_WFWDAT) Wafer Level Test Programming Data Position */
#define WFT_WFWDAT_WDAT_Msk                   (_UINT16_(0xFFFF) << WFT_WFWDAT_WDAT_Pos)            /* (WFT_WFWDAT) Wafer Level Test Programming Data Mask */
#define WFT_WFWDAT_WDAT(value)                (WFT_WFWDAT_WDAT_Msk & (_UINT16_(value) << WFT_WFWDAT_WDAT_Pos)) /* Assigment of value for WDAT in the WFT_WFWDAT register */
#define WFT_WFWDAT_Msk                        _UINT16_(0xFFFF)                                     /* (WFT_WFWDAT) Register Mask  */


/* -------- WFT_WFGPS : (WFT Offset: 0x2C) ( R/ 8) General Purpose Output -------- */
#define WFT_WFGPS_RESETVALUE                  _UINT8_(0x00)                                        /*  (WFT_WFGPS) General Purpose Output  Reset Value */

#define WFT_WFGPS_GPS_Pos                     _UINT8_(0)                                           /* (WFT_WFGPS) General Purpose Status Position */
#define WFT_WFGPS_GPS_Msk                     (_UINT8_(0xFF) << WFT_WFGPS_GPS_Pos)                 /* (WFT_WFGPS) General Purpose Status Mask */
#define WFT_WFGPS_GPS(value)                  (WFT_WFGPS_GPS_Msk & (_UINT8_(value) << WFT_WFGPS_GPS_Pos)) /* Assigment of value for GPS in the WFT_WFGPS register */
#define WFT_WFGPS_Msk                         _UINT8_(0xFF)                                        /* (WFT_WFGPS) Register Mask  */


/* -------- WFT_WFGPC : (WFT Offset: 0x2E) (R/W 8) General Purpose Output -------- */
#define WFT_WFGPC_RESETVALUE                  _UINT8_(0x00)                                        /*  (WFT_WFGPC) General Purpose Output  Reset Value */

#define WFT_WFGPC_GPC_Pos                     _UINT8_(0)                                           /* (WFT_WFGPC) General Purpose Output Position */
#define WFT_WFGPC_GPC_Msk                     (_UINT8_(0xFF) << WFT_WFGPC_GPC_Pos)                 /* (WFT_WFGPC) General Purpose Output Mask */
#define WFT_WFGPC_GPC(value)                  (WFT_WFGPC_GPC_Msk & (_UINT8_(value) << WFT_WFGPC_GPC_Pos)) /* Assigment of value for GPC in the WFT_WFGPC register */
#define WFT_WFGPC_Msk                         _UINT8_(0xFF)                                        /* (WFT_WFGPC) Register Mask  */


/* -------- WFT_WFRDAT : (WFT Offset: 0x30) (R/W 16) Wafer Test Read DATA Register -------- */
#define WFT_WFRDAT_RESETVALUE                 _UINT16_(0x00)                                       /*  (WFT_WFRDAT) Wafer Test Read DATA Register  Reset Value */

#define WFT_WFRDAT_RDAT_Pos                   _UINT16_(0)                                          /* (WFT_WFRDAT) Wafer Level Test Read Data from Flash Reads Position */
#define WFT_WFRDAT_RDAT_Msk                   (_UINT16_(0xFFFF) << WFT_WFRDAT_RDAT_Pos)            /* (WFT_WFRDAT) Wafer Level Test Read Data from Flash Reads Mask */
#define WFT_WFRDAT_RDAT(value)                (WFT_WFRDAT_RDAT_Msk & (_UINT16_(value) << WFT_WFRDAT_RDAT_Pos)) /* Assigment of value for RDAT in the WFT_WFRDAT register */
#define WFT_WFRDAT_Msk                        _UINT16_(0xFFFF)                                     /* (WFT_WFRDAT) Register Mask  */


/* -------- WFT_WFRCNT : (WFT Offset: 0x54) (R/W 32) Wafer Flash Test Read Count Register -------- */
#define WFT_WFRCNT_RESETVALUE                 _UINT32_(0x00)                                       /*  (WFT_WFRCNT) Wafer Flash Test Read Count Register  Reset Value */

#define WFT_WFRCNT_WFRCNT_Pos                 _UINT32_(0)                                          /* (WFT_WFRCNT) Read Count Value - Used by the RDN_NVM Command Position */
#define WFT_WFRCNT_WFRCNT_Msk                 (_UINT32_(0xFFFFFF) << WFT_WFRCNT_WFRCNT_Pos)        /* (WFT_WFRCNT) Read Count Value - Used by the RDN_NVM Command Mask */
#define WFT_WFRCNT_WFRCNT(value)              (WFT_WFRCNT_WFRCNT_Msk & (_UINT32_(value) << WFT_WFRCNT_WFRCNT_Pos)) /* Assigment of value for WFRCNT in the WFT_WFRCNT register */
#define WFT_WFRCNT_Msk                        _UINT32_(0x00FFFFFF)                                 /* (WFT_WFRCNT) Register Mask  */


/* -------- WFT_WFRERR : (WFT Offset: 0x58) (R/W 32) Wafer Flash Test Read ERROR Count Register -------- */
#define WFT_WFRERR_RESETVALUE                 _UINT32_(0x00)                                       /*  (WFT_WFRERR) Wafer Flash Test Read ERROR Count Register  Reset Value */

#define WFT_WFRERR_WFRERR_Pos                 _UINT32_(0)                                          /* (WFT_WFRERR) Read Error Count Value - Used by the RDN_NVM Command Position */
#define WFT_WFRERR_WFRERR_Msk                 (_UINT32_(0xFFFFFFFF) << WFT_WFRERR_WFRERR_Pos)      /* (WFT_WFRERR) Read Error Count Value - Used by the RDN_NVM Command Mask */
#define WFT_WFRERR_WFRERR(value)              (WFT_WFRERR_WFRERR_Msk & (_UINT32_(value) << WFT_WFRERR_WFRERR_Pos)) /* Assigment of value for WFRERR in the WFT_WFRERR register */
#define WFT_WFRERR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (WFT_WFRERR) Register Mask  */


/* -------- WFT_WFDOUTPIN : (WFT Offset: 0x5C) ( R/ 16) Wafer Flash Test Read DOUT PINS Register -------- */
#define WFT_WFDOUTPIN_RESETVALUE              _UINT16_(0x00)                                       /*  (WFT_WFDOUTPIN) Wafer Flash Test Read DOUT PINS Register  Reset Value */

#define WFT_WFDOUTPIN_P1_DOUT_PIN_Pos         _UINT16_(0)                                          /* (WFT_WFDOUTPIN) This register bit reflects the DOUT[x] Value of flash panel 1  where x=  READ_CAL_DOUT_BIT PARAMETER Position */
#define WFT_WFDOUTPIN_P1_DOUT_PIN_Msk         (_UINT16_(0x1) << WFT_WFDOUTPIN_P1_DOUT_PIN_Pos)     /* (WFT_WFDOUTPIN) This register bit reflects the DOUT[x] Value of flash panel 1  where x=  READ_CAL_DOUT_BIT PARAMETER Mask */
#define WFT_WFDOUTPIN_P1_DOUT_PIN(value)      (WFT_WFDOUTPIN_P1_DOUT_PIN_Msk & (_UINT16_(value) << WFT_WFDOUTPIN_P1_DOUT_PIN_Pos)) /* Assigment of value for P1_DOUT_PIN in the WFT_WFDOUTPIN register */
#define WFT_WFDOUTPIN_P2_DOUT_PIN_Pos         _UINT16_(2)                                          /* (WFT_WFDOUTPIN) This register bit reflects the DOUT[x] Value of flash panel 2 where x=  READ_CAL_DOUT_BIT PARAMETER Position */
#define WFT_WFDOUTPIN_P2_DOUT_PIN_Msk         (_UINT16_(0x1) << WFT_WFDOUTPIN_P2_DOUT_PIN_Pos)     /* (WFT_WFDOUTPIN) This register bit reflects the DOUT[x] Value of flash panel 2 where x=  READ_CAL_DOUT_BIT PARAMETER Mask */
#define WFT_WFDOUTPIN_P2_DOUT_PIN(value)      (WFT_WFDOUTPIN_P2_DOUT_PIN_Msk & (_UINT16_(value) << WFT_WFDOUTPIN_P2_DOUT_PIN_Pos)) /* Assigment of value for P2_DOUT_PIN in the WFT_WFDOUTPIN register */
#define WFT_WFDOUTPIN_P3_DOUT_PIN_Pos         _UINT16_(4)                                          /* (WFT_WFDOUTPIN) This register bit reflects the DOUT[x] Value of flash panel 3 where x=  READ_CAL_DOUT_BIT PARAMETER Position */
#define WFT_WFDOUTPIN_P3_DOUT_PIN_Msk         (_UINT16_(0x1) << WFT_WFDOUTPIN_P3_DOUT_PIN_Pos)     /* (WFT_WFDOUTPIN) This register bit reflects the DOUT[x] Value of flash panel 3 where x=  READ_CAL_DOUT_BIT PARAMETER Mask */
#define WFT_WFDOUTPIN_P3_DOUT_PIN(value)      (WFT_WFDOUTPIN_P3_DOUT_PIN_Msk & (_UINT16_(value) << WFT_WFDOUTPIN_P3_DOUT_PIN_Pos)) /* Assigment of value for P3_DOUT_PIN in the WFT_WFDOUTPIN register */
#define WFT_WFDOUTPIN_P4_DOUT_PIN_Pos         _UINT16_(6)                                          /* (WFT_WFDOUTPIN) This register bit reflects the DOUT[x] Value of flash panel 4 where x=  READ_CAL_DOUT_BIT PARAMETER Position */
#define WFT_WFDOUTPIN_P4_DOUT_PIN_Msk         (_UINT16_(0x1) << WFT_WFDOUTPIN_P4_DOUT_PIN_Pos)     /* (WFT_WFDOUTPIN) This register bit reflects the DOUT[x] Value of flash panel 4 where x=  READ_CAL_DOUT_BIT PARAMETER Mask */
#define WFT_WFDOUTPIN_P4_DOUT_PIN(value)      (WFT_WFDOUTPIN_P4_DOUT_PIN_Msk & (_UINT16_(value) << WFT_WFDOUTPIN_P4_DOUT_PIN_Pos)) /* Assigment of value for P4_DOUT_PIN in the WFT_WFDOUTPIN register */
#define WFT_WFDOUTPIN_Msk                     _UINT16_(0x0055)                                     /* (WFT_WFDOUTPIN) Register Mask  */


/* -------- WFT_RD1_NVM : (WFT Offset: 0x70) (R/W 8) Command RD1_NVM -------- */
#define WFT_RD1_NVM_RESETVALUE                _UINT8_(0x00)                                        /*  (WFT_RD1_NVM) Command RD1_NVM  Reset Value */

#define WFT_RD1_NVM_Msk                       _UINT8_(0x00)                                        /* (WFT_RD1_NVM) Register Mask  */


/* -------- WFT_RDN_NVM : (WFT Offset: 0x71) (R/W 8) Command RDN_NVM -------- */
#define WFT_RDN_NVM_RESETVALUE                _UINT8_(0x00)                                        /*  (WFT_RDN_NVM) Command RDN_NVM  Reset Value */

#define WFT_RDN_NVM_Msk                       _UINT8_(0x00)                                        /* (WFT_RDN_NVM) Register Mask  */


/* -------- WFT_ADR_INCA : (WFT Offset: 0x72) (R/W 8) Command ADR_INCA -------- */
#define WFT_ADR_INCA_RESETVALUE               _UINT8_(0x00)                                        /*  (WFT_ADR_INCA) Command ADR_INCA  Reset Value */

#define WFT_ADR_INCA_Msk                      _UINT8_(0x00)                                        /* (WFT_ADR_INCA) Register Mask  */


/* -------- WFT_ADR_INCB : (WFT Offset: 0x73) (R/W 8) Command ADR_INCB -------- */
#define WFT_ADR_INCB_RESETVALUE               _UINT8_(0x00)                                        /*  (WFT_ADR_INCB) Command ADR_INCB  Reset Value */

#define WFT_ADR_INCB_Msk                      _UINT8_(0x00)                                        /* (WFT_ADR_INCB) Register Mask  */


/* -------- WFT_WDAT_INV : (WFT Offset: 0x74) (R/W 8) Command WDAT_INV -------- */
#define WFT_WDAT_INV_RESETVALUE               _UINT8_(0x00)                                        /*  (WFT_WDAT_INV) Command WDAT_INV  Reset Value */

#define WFT_WDAT_INV_Msk                      _UINT8_(0x00)                                        /* (WFT_WDAT_INV) Register Mask  */


/* -------- WFT_RDAT_INV : (WFT Offset: 0x75) (R/W 8) Command RDAT_INV -------- */
#define WFT_RDAT_INV_RESETVALUE               _UINT8_(0x00)                                        /*  (WFT_RDAT_INV) Command RDAT_INV  Reset Value */

#define WFT_RDAT_INV_Msk                      _UINT8_(0x00)                                        /* (WFT_RDAT_INV) Register Mask  */


/* -------- WFT_RST_SFR : (WFT Offset: 0x76) (R/W 8) Command RST_SFR -------- */
#define WFT_RST_SFR_RESETVALUE                _UINT8_(0x00)                                        /*  (WFT_RST_SFR) Command RST_SFR  Reset Value */

#define WFT_RST_SFR_Msk                       _UINT8_(0x00)                                        /* (WFT_RST_SFR) Register Mask  */


/* -------- WFT_CPY_ADR : (WFT Offset: 0x77) (R/W 8) Command CPY_ADR -------- */
#define WFT_CPY_ADR_RESETVALUE                _UINT8_(0x00)                                        /*  (WFT_CPY_ADR) Command CPY_ADR  Reset Value */

#define WFT_CPY_ADR_Msk                       _UINT8_(0x00)                                        /* (WFT_CPY_ADR) Register Mask  */


/* -------- WFT_WDAT_INCA : (WFT Offset: 0x78) (R/W 8) Command WDAT_INCA -------- */
#define WFT_WDAT_INCA_RESETVALUE              _UINT8_(0x00)                                        /*  (WFT_WDAT_INCA) Command WDAT_INCA  Reset Value */

#define WFT_WDAT_INCA_Msk                     _UINT8_(0x00)                                        /* (WFT_WDAT_INCA) Register Mask  */


/* -------- WFT_WDAT_INCB : (WFT Offset: 0x79) (R/W 8) Command WDAT_INCB -------- */
#define WFT_WDAT_INCB_RESETVALUE              _UINT8_(0x00)                                        /*  (WFT_WDAT_INCB) Command WDAT_INCB  Reset Value */

#define WFT_WDAT_INCB_Msk                     _UINT8_(0x00)                                        /* (WFT_WDAT_INCB) Register Mask  */


/* -------- WFT_DAT_SET : (WFT Offset: 0x7A) (R/W 8) Command DAT_SET -------- */
#define WFT_DAT_SET_RESETVALUE                _UINT8_(0x00)                                        /*  (WFT_DAT_SET) Command DAT_SET  Reset Value */

#define WFT_DAT_SET_Msk                       _UINT8_(0x00)                                        /* (WFT_DAT_SET) Register Mask  */


/* -------- WFT_DAT_CLR : (WFT Offset: 0x7B) (R/W 8) Command DAT_CLR -------- */
#define WFT_DAT_CLR_RESETVALUE                _UINT8_(0x00)                                        /*  (WFT_DAT_CLR) Command DAT_CLR  Reset Value */

#define WFT_DAT_CLR_Msk                       _UINT8_(0x00)                                        /* (WFT_DAT_CLR) Register Mask  */


/* -------- WFT_WNOP : (WFT Offset: 0x7C) (R/W 8) Command WNOP -------- */
#define WFT_WNOP_RESETVALUE                   _UINT8_(0x00)                                        /*  (WFT_WNOP) Command WNOP  Reset Value */

#define WFT_WNOP_Msk                          _UINT8_(0x00)                                        /* (WFT_WNOP) Register Mask  */


/* -------- WFT_EXT_CMD : (WFT Offset: 0x7F) (R/W 8) Command EXT_CMD -------- */
#define WFT_EXT_CMD_RESETVALUE                _UINT8_(0x00)                                        /*  (WFT_EXT_CMD) Command EXT_CMD  Reset Value */

#define WFT_EXT_CMD_Msk                       _UINT8_(0x00)                                        /* (WFT_EXT_CMD) Register Mask  */


/** \brief WFT register offsets definitions */
#define WFT_WFCON1_REG_OFST            _UINT32_(0x00)      /* (WFT_WFCON1) Wafer Flash Test Control Register Offset */
#define WFT_WFCON2_REG_OFST            _UINT32_(0x02)      /* (WFT_WFCON2) Wafer Flash Test Control Register Offset */
#define WFT_WFCON3_REG_OFST            _UINT32_(0x04)      /* (WFT_WFCON3) Wafer Flash Test Control Register Offset */
#define WFT_WFCON4_REG_OFST            _UINT32_(0x06)      /* (WFT_WFCON4) Wafer Flash Test Control Register Offset */
#define WFT_WFCON5_REG_OFST            _UINT32_(0x08)      /* (WFT_WFCON5) Wafer Flash Test Control Register Offset */
#define WFT_WFCON6_REG_OFST            _UINT32_(0x0A)      /* (WFT_WFCON6) Wafer Flash Test Control Register Offset */
#define WFT_WFCON7_REG_OFST            _UINT32_(0x0C)      /* (WFT_WFCON7) Wafer Flash Test Control Register Offset */
#define WFT_WFCON8_REG_OFST            _UINT32_(0x0E)      /* (WFT_WFCON8) Wafer Flash Test Control Register Offset */
#define WFT_WFCON9_REG_OFST            _UINT32_(0x10)      /* (WFT_WFCON9) Wafer Flash Test Control Register Offset */
#define WFT_WFSTAT1_REG_OFST           _UINT32_(0x12)      /* (WFT_WFSTAT1) Wafer Flash Test Status Register Offset */
#define WFT_WFPRO1_REG_OFST            _UINT32_(0x14)      /* (WFT_WFPRO1) Wafer Flash Test NVR Protect Register Offset */
#define WFT_WFLAS1_REG_OFST            _UINT32_(0x18)      /* (WFT_WFLAS1) Wafer Flash Test Logical Address Scramble Register Offset */
#define WFT_WFLAS2_REG_OFST            _UINT32_(0x1A)      /* (WFT_WFLAS2) Wafer Flash Test Logical Address Scramble Register Offset */
#define WFT_WFADDR_REG_OFST            _UINT32_(0x1C)      /* (WFT_WFADDR) Wafer Flash Test Address Register Offset */
#define WFT_WFWDAT_REG_OFST            _UINT32_(0x22)      /* (WFT_WFWDAT) Wafer Flash Test Write DATA Register Offset */
#define WFT_WFWDAT0_REG_OFST           _UINT32_(0x22)      /* (WFT_WFWDAT0) Wafer Flash Test Write DATA Register Offset */
#define WFT_WFWDAT1_REG_OFST           _UINT32_(0x24)      /* (WFT_WFWDAT1) Wafer Flash Test Write DATA Register Offset */
#define WFT_WFWDAT2_REG_OFST           _UINT32_(0x26)      /* (WFT_WFWDAT2) Wafer Flash Test Write DATA Register Offset */
#define WFT_WFGPS_REG_OFST             _UINT32_(0x2C)      /* (WFT_WFGPS) General Purpose Output Offset */
#define WFT_WFGPC_REG_OFST             _UINT32_(0x2E)      /* (WFT_WFGPC) General Purpose Output Offset */
#define WFT_WFRDAT_REG_OFST            _UINT32_(0x30)      /* (WFT_WFRDAT) Wafer Test Read DATA Register Offset */
#define WFT_WFRDAT0_REG_OFST           _UINT32_(0x30)      /* (WFT_WFRDAT0) Wafer Test Read DATA Register Offset */
#define WFT_WFRDAT1_REG_OFST           _UINT32_(0x32)      /* (WFT_WFRDAT1) Wafer Test Read DATA Register Offset */
#define WFT_WFRDAT2_REG_OFST           _UINT32_(0x34)      /* (WFT_WFRDAT2) Wafer Test Read DATA Register Offset */
#define WFT_WFRDAT3_REG_OFST           _UINT32_(0x36)      /* (WFT_WFRDAT3) Wafer Test Read DATA Register Offset */
#define WFT_WFRDAT4_REG_OFST           _UINT32_(0x38)      /* (WFT_WFRDAT4) Wafer Test Read DATA Register Offset */
#define WFT_WFRDAT5_REG_OFST           _UINT32_(0x3A)      /* (WFT_WFRDAT5) Wafer Test Read DATA Register Offset */
#define WFT_WFRDAT6_REG_OFST           _UINT32_(0x3C)      /* (WFT_WFRDAT6) Wafer Test Read DATA Register Offset */
#define WFT_WFRDAT7_REG_OFST           _UINT32_(0x3E)      /* (WFT_WFRDAT7) Wafer Test Read DATA Register Offset */
#define WFT_WFRDAT8_REG_OFST           _UINT32_(0x40)      /* (WFT_WFRDAT8) Wafer Test Read DATA Register Offset */
#define WFT_WFRCNT_REG_OFST            _UINT32_(0x54)      /* (WFT_WFRCNT) Wafer Flash Test Read Count Register Offset */
#define WFT_WFRERR_REG_OFST            _UINT32_(0x58)      /* (WFT_WFRERR) Wafer Flash Test Read ERROR Count Register Offset */
#define WFT_WFDOUTPIN_REG_OFST         _UINT32_(0x5C)      /* (WFT_WFDOUTPIN) Wafer Flash Test Read DOUT PINS Register Offset */
#define WFT_RD1_NVM_REG_OFST           _UINT32_(0x70)      /* (WFT_RD1_NVM) Command RD1_NVM Offset */
#define WFT_RDN_NVM_REG_OFST           _UINT32_(0x71)      /* (WFT_RDN_NVM) Command RDN_NVM Offset */
#define WFT_ADR_INCA_REG_OFST          _UINT32_(0x72)      /* (WFT_ADR_INCA) Command ADR_INCA Offset */
#define WFT_ADR_INCB_REG_OFST          _UINT32_(0x73)      /* (WFT_ADR_INCB) Command ADR_INCB Offset */
#define WFT_WDAT_INV_REG_OFST          _UINT32_(0x74)      /* (WFT_WDAT_INV) Command WDAT_INV Offset */
#define WFT_RDAT_INV_REG_OFST          _UINT32_(0x75)      /* (WFT_RDAT_INV) Command RDAT_INV Offset */
#define WFT_RST_SFR_REG_OFST           _UINT32_(0x76)      /* (WFT_RST_SFR) Command RST_SFR Offset */
#define WFT_CPY_ADR_REG_OFST           _UINT32_(0x77)      /* (WFT_CPY_ADR) Command CPY_ADR Offset */
#define WFT_WDAT_INCA_REG_OFST         _UINT32_(0x78)      /* (WFT_WDAT_INCA) Command WDAT_INCA Offset */
#define WFT_WDAT_INCB_REG_OFST         _UINT32_(0x79)      /* (WFT_WDAT_INCB) Command WDAT_INCB Offset */
#define WFT_DAT_SET_REG_OFST           _UINT32_(0x7A)      /* (WFT_DAT_SET) Command DAT_SET Offset */
#define WFT_DAT_CLR_REG_OFST           _UINT32_(0x7B)      /* (WFT_DAT_CLR) Command DAT_CLR Offset */
#define WFT_WNOP_REG_OFST              _UINT32_(0x7C)      /* (WFT_WNOP) Command WNOP Offset */
#define WFT_EXT_CMD_REG_OFST           _UINT32_(0x7F)      /* (WFT_EXT_CMD) Command EXT_CMD Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief WFT register API structure */
typedef struct
{  /* MCU32 Flash Wafer Test Controller */
  __IO  uint16_t                       WFT_WFCON1;         /**< Offset: 0x00 (R/W  16) Wafer Flash Test Control Register */
  __IO  uint16_t                       WFT_WFCON2;         /**< Offset: 0x02 (R/W  16) Wafer Flash Test Control Register */
  __IO  uint16_t                       WFT_WFCON3;         /**< Offset: 0x04 (R/W  16) Wafer Flash Test Control Register */
  __IO  uint16_t                       WFT_WFCON4;         /**< Offset: 0x06 (R/W  16) Wafer Flash Test Control Register */
  __IO  uint16_t                       WFT_WFCON5;         /**< Offset: 0x08 (R/W  16) Wafer Flash Test Control Register */
  __IO  uint16_t                       WFT_WFCON6;         /**< Offset: 0x0A (R/W  16) Wafer Flash Test Control Register */
  __IO  uint16_t                       WFT_WFCON7;         /**< Offset: 0x0C (R/W  16) Wafer Flash Test Control Register */
  __IO  uint16_t                       WFT_WFCON8;         /**< Offset: 0x0E (R/W  16) Wafer Flash Test Control Register */
  __IO  uint16_t                       WFT_WFCON9;         /**< Offset: 0x10 (R/W  16) Wafer Flash Test Control Register */
  __IO  uint16_t                       WFT_WFSTAT1;        /**< Offset: 0x12 (R/W  16) Wafer Flash Test Status Register */
  __IO  uint16_t                       WFT_WFPRO1;         /**< Offset: 0x14 (R/W  16) Wafer Flash Test NVR Protect Register */
  __I   uint8_t                        Reserved1[0x02];
  __IO  uint16_t                       WFT_WFLAS1;         /**< Offset: 0x18 (R/W  16) Wafer Flash Test Logical Address Scramble Register */
  __IO  uint16_t                       WFT_WFLAS2;         /**< Offset: 0x1A (R/W  16) Wafer Flash Test Logical Address Scramble Register */
  __IO  uint32_t                       WFT_WFADDR;         /**< Offset: 0x1C (R/W  32) Wafer Flash Test Address Register */
  __I   uint8_t                        Reserved2[0x02];
  __IO  uint16_t                       WFT_WFWDAT[3];      /**< Offset: 0x22 (R/W  16) Wafer Flash Test Write DATA Register */
  __I   uint8_t                        Reserved3[0x04];
  __I   uint8_t                        WFT_WFGPS;          /**< Offset: 0x2C (R/   8) General Purpose Output */
  __I   uint8_t                        Reserved4[0x01];
  __IO  uint8_t                        WFT_WFGPC;          /**< Offset: 0x2E (R/W  8) General Purpose Output */
  __I   uint8_t                        Reserved5[0x01];
  __IO  uint16_t                       WFT_WFRDAT[9];      /**< Offset: 0x30 (R/W  16) Wafer Test Read DATA Register */
  __I   uint8_t                        Reserved6[0x12];
  __IO  uint32_t                       WFT_WFRCNT;         /**< Offset: 0x54 (R/W  32) Wafer Flash Test Read Count Register */
  __IO  uint32_t                       WFT_WFRERR;         /**< Offset: 0x58 (R/W  32) Wafer Flash Test Read ERROR Count Register */
  __I   uint16_t                       WFT_WFDOUTPIN;      /**< Offset: 0x5C (R/   16) Wafer Flash Test Read DOUT PINS Register */
  __I   uint8_t                        Reserved7[0x12];
  __IO  uint8_t                        WFT_RD1_NVM;        /**< Offset: 0x70 (R/W  8) Command RD1_NVM */
  __IO  uint8_t                        WFT_RDN_NVM;        /**< Offset: 0x71 (R/W  8) Command RDN_NVM */
  __IO  uint8_t                        WFT_ADR_INCA;       /**< Offset: 0x72 (R/W  8) Command ADR_INCA */
  __IO  uint8_t                        WFT_ADR_INCB;       /**< Offset: 0x73 (R/W  8) Command ADR_INCB */
  __IO  uint8_t                        WFT_WDAT_INV;       /**< Offset: 0x74 (R/W  8) Command WDAT_INV */
  __IO  uint8_t                        WFT_RDAT_INV;       /**< Offset: 0x75 (R/W  8) Command RDAT_INV */
  __IO  uint8_t                        WFT_RST_SFR;        /**< Offset: 0x76 (R/W  8) Command RST_SFR */
  __IO  uint8_t                        WFT_CPY_ADR;        /**< Offset: 0x77 (R/W  8) Command CPY_ADR */
  __IO  uint8_t                        WFT_WDAT_INCA;      /**< Offset: 0x78 (R/W  8) Command WDAT_INCA */
  __IO  uint8_t                        WFT_WDAT_INCB;      /**< Offset: 0x79 (R/W  8) Command WDAT_INCB */
  __IO  uint8_t                        WFT_DAT_SET;        /**< Offset: 0x7A (R/W  8) Command DAT_SET */
  __IO  uint8_t                        WFT_DAT_CLR;        /**< Offset: 0x7B (R/W  8) Command DAT_CLR */
  __IO  uint8_t                        WFT_WNOP;           /**< Offset: 0x7C (R/W  8) Command WNOP */
  __I   uint8_t                        Reserved8[0x02];
  __IO  uint8_t                        WFT_EXT_CMD;        /**< Offset: 0x7F (R/W  8) Command EXT_CMD */
} wft_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CMGC00_WFT_COMPONENT_H_ */
