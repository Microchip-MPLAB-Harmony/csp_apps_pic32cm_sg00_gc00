/*******************************************************************************
  Controller Area Network (CAN) Peripheral Library Source File

  Company:
    Microchip Technology Inc.

  File Name:
    plib_can0.c

  Summary:
    CAN peripheral library interface.

  Description:
    This file defines the interface to the CAN peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2024 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END
// *****************************************************************************
// *****************************************************************************
// Header Includes
// *****************************************************************************
// *****************************************************************************

#include "device.h"
#include "interrupts.h"
#include "plib_can0.h"

// *****************************************************************************
// *****************************************************************************
// Global Data
// *****************************************************************************
// *****************************************************************************
#define CAN_STD_ID_Msk        0x7FFU

static volatile CAN_TX_FIFO_CALLBACK_OBJ can0TxFifoCallbackObj;
static volatile CAN_TX_EVENT_FIFO_CALLBACK_OBJ can0TxEventFifoCallbackObj;
static volatile CAN_TXRX_BUFFERS_CALLBACK_OBJ can0RxBufferCallbackObj;
static volatile CAN_RX_FIFO_CALLBACK_OBJ can0RxFifoCallbackObj[2];
static volatile CAN_CALLBACK_OBJ can0CallbackObj;
static volatile CAN_OBJ can0Obj;

static const can_mram_sidfe_registers_t can0StdFilter[] =
{
    {
        .CAN_S0 = CAN_S0_SFT(0UL) |
                  CAN_S0_SFID1(0x469UL) |
                  CAN_S0_SFID2(0x469UL) |
                  CAN_S0_SFEC(1UL)
    },
    {
        .CAN_S0 = CAN_S0_SFT(0UL) |
                  CAN_S0_SFID1(0x45aUL) |
                  CAN_S0_SFID2(0x0UL) |
                  CAN_S0_SFEC(7UL)
    },
};

static const can_mram_xidfe_registers_t can0ExtFilter[] =
{
    {
        .CAN_F0 = CAN_F0_EFID1(0x100000a5UL) | CAN_F0_EFEC(7UL),
        .CAN_F1 = CAN_F1_EFID2(0x0UL) | CAN_F1_EFT(0UL),
    },
    {
        .CAN_F0 = CAN_F0_EFID1(0x10000096UL) | CAN_F0_EFEC(2UL),
        .CAN_F1 = CAN_F1_EFID2(0x10000096UL) | CAN_F1_EFT(0UL),
    },
};

static inline void CAN0_ZeroInitialize(volatile void* pData, size_t dataSize)
{
    volatile uint8_t* data = (volatile uint8_t*)pData;
    for (uint32_t index = 0; index < dataSize; index++)
    {
        data[index] = 0U;
    }
}

// *****************************************************************************
// *****************************************************************************
// CAN0 PLib Interface Routines
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Function:
    void CAN0_Initialize(void)

   Summary:
    Initializes given instance of the CAN peripheral.

   Precondition:
    None.

   Parameters:
    None.

   Returns:
    None
*/
void CAN0_Initialize(void)
{
    /* Start CAN initialization */
    CAN0_REGS->CAN_CCCR = CAN_CCCR_INIT_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) != CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }

    /* Set CCE to unlock the configuration registers */
    CAN0_REGS->CAN_CCCR |= CAN_CCCR_CCE_Msk;

    /* Set Data Bit Timing and Prescaler Register */
    CAN0_REGS->CAN_DBTP = CAN_DBTP_DTSEG2(4UL) | CAN_DBTP_DTSEG1(11UL) | CAN_DBTP_DBRP(0UL) | CAN_DBTP_DSJW(4UL);

    /* Set Nominal Bit timing and Prescaler Register */
    CAN0_REGS->CAN_NBTP  = CAN_NBTP_NTSEG2(17UL) | CAN_NBTP_NTSEG1(52UL) | CAN_NBTP_NBRP(0UL) | CAN_NBTP_NSJW(17UL);

    /* Receive Buffer / FIFO Element Size Configuration Register */
    CAN0_REGS->CAN_RXESC = 0UL  | CAN_RXESC_F0DS(7UL) | CAN_RXESC_F1DS(7UL) | CAN_RXESC_RBDS(7UL);
    /*lint -e{9048} PC lint incorrectly reports a missing 'U' Suffix */
    CAN0_REGS->CAN_NDAT1 = CAN_NDAT1_Msk;
    /*lint -e{9048} PC lint incorrectly reports a missing 'U' Suffix */
    CAN0_REGS->CAN_NDAT2 = CAN_NDAT2_Msk;

    /* Transmit Buffer/FIFO Element Size Configuration Register */
    CAN0_REGS->CAN_TXESC = CAN_TXESC_TBDS(7UL);

    /* Global Filter Configuration Register */
    CAN0_REGS->CAN_GFC = CAN_GFC_ANFS_REJECT | CAN_GFC_ANFE_REJECT;

    /* Extended ID AND Mask Register */
    CAN0_REGS->CAN_XIDAM = CAN_XIDAM_Msk;

    /* Timestamp Counter Configuration Register */
    CAN0_REGS->CAN_TSCC = CAN_TSCC_TCP(0UL) | CAN_TSCC_TSS_INC;

    /* Set the operation mode */
    CAN0_REGS->CAN_CCCR |= CAN_CCCR_FDOE_Msk | CAN_CCCR_BRSE_Msk;


    CAN0_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }

    /* Select interrupt line */
    CAN0_REGS->CAN_ILS = 0x0U;

    /* Enable interrupt line */
    CAN0_REGS->CAN_ILE = CAN_ILE_EINT0_Msk;

    /* Enable CAN interrupts */
    CAN0_REGS->CAN_IE = CAN_IE_BOE_Msk | CAN_IE_ARAE_Msk | CAN_IE_PEDE_Msk | CAN_IE_PEAE_Msk | CAN_IE_WDIE_Msk
                                      | CAN_IE_EWE_Msk | CAN_IE_EPE_Msk | CAN_IE_ELOE_Msk
                                       | CAN_IE_TSWE_Msk | CAN_IE_TFEE_Msk
                                       | CAN_IE_TEFNE_Msk | CAN_IE_TEFLE_Msk | CAN_IE_TEFFE_Msk | CAN_IE_TCFE_Msk | CAN_IE_HPME_Msk
                                       | CAN_IE_RF0NE_Msk | CAN_IE_RF0LE_Msk | CAN_IE_RF0FE_Msk
                                       | CAN_IE_RF1NE_Msk | CAN_IE_RF1LE_Msk | CAN_IE_RF1FE_Msk
                                       | CAN_IE_DRXE_Msk
                                      | CAN_IE_MRAFE_Msk;

    CAN0_ZeroInitialize(&can0Obj.msgRAMConfig, sizeof(CAN_MSG_RAM_CONFIG));
}


// *****************************************************************************
/* Function:
    bool CAN0_MessageTransmitFifo(uint8_t numberOfMessage, CAN_TX_BUFFER *txBuffer)

   Summary:
    Transmit multiple messages into CAN bus from Tx FIFO.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    numberOfMessage - Total number of message.
    txBuffer        - Pointer to Tx buffer

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_MessageTransmitFifo(uint8_t numberOfMessage, CAN_TX_BUFFER *txBuffer)
{
    uint8_t  *txFifo = NULL;
    uint8_t  *txBuf = (uint8_t *)txBuffer;
    uint32_t bufferNumber = 0U;
    uint8_t  tfqpi = 0U;
    uint8_t  count = 0U;
    bool transmitFifo_event = false;

    if (!(((numberOfMessage < 1U) || (numberOfMessage > 1U)) || (txBuffer == NULL)))
    {
        tfqpi = (uint8_t)((CAN0_REGS->CAN_TXFQS & CAN_TXFQS_TFQPI_Msk) >> CAN_TXFQS_TFQPI_Pos);

        for (count = 0U; count < numberOfMessage; count++)
        {
            txFifo = (uint8_t *)((uint8_t*)can0Obj.msgRAMConfig.txBuffersAddress + ((uint32_t)tfqpi * CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE));

            (void) memcpy(txFifo, txBuf, CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE);

            txBuf += CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE;
            bufferNumber |= (1UL << tfqpi);
            tfqpi++;
            if (tfqpi == 1U)
            {
                tfqpi = 0U;
            }
        }

        __DSB();

        /* Set Transmission request */
        CAN0_REGS->CAN_TXBAR = bufferNumber;

        transmitFifo_event = true;
    }
    return transmitFifo_event;
}

// *****************************************************************************
/* Function:
    uint8_t CAN0_TxFifoFreeLevelGet(void)

   Summary:
    Returns Tx FIFO Free Level.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    Tx FIFO Free Level.
*/
uint8_t CAN0_TxFifoFreeLevelGet(void)
{
    return (uint8_t)(CAN0_REGS->CAN_TXFQS & CAN_TXFQS_TFFL_Msk);
}

// *****************************************************************************
/* Function:
    bool CAN0_TxBufferIsBusy(uint8_t bufferNumber)

   Summary:
    Check if Transmission request is pending for the specific Tx buffer.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    true  - Transmission request is pending.
    false - Transmission request is not pending.
*/
bool CAN0_TxBufferIsBusy(uint8_t bufferNumber)
{
    return ((CAN0_REGS->CAN_TXBRP & (1UL << bufferNumber)) != 0U);
}

// *****************************************************************************
/* Function:
    bool CAN0_TxEventFifoRead(uint8_t numberOfTxEvent, CAN_TX_EVENT_FIFO *txEventFifo)

   Summary:
    Read Tx Event FIFO for the transmitted messages.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    numberOfTxEvent - Total number of Tx Event
    txEventFifo     - Pointer to Tx Event FIFO

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_TxEventFifoRead(uint8_t numberOfTxEvent, CAN_TX_EVENT_FIFO *txEventFifo)
{
    uint8_t txefgi     = 0U;
    uint8_t count      = 0U;
    uint8_t *txEvent   = NULL;
    uint8_t *txEvtFifo = (uint8_t *)txEventFifo;
    bool txFifo_event = false;

    if (txEventFifo != NULL)
    {
        /* Read data from the Rx FIFO0 */
        txefgi = (uint8_t)((CAN0_REGS->CAN_TXEFS & CAN_TXEFS_EFGI_Msk) >> CAN_TXEFS_EFGI_Pos);
        for (count = 0U; count < numberOfTxEvent; count++)
        {
            txEvent = (uint8_t *) ((uint8_t *)can0Obj.msgRAMConfig.txEventFIFOAddress + ((uint32_t)txefgi * sizeof(CAN_TX_EVENT_FIFO)));

            (void) memcpy(txEvtFifo, txEvent, sizeof(CAN_TX_EVENT_FIFO));

            if ((count + 1U) == numberOfTxEvent)
            {
                break;
            }
            txEvtFifo += sizeof(CAN_TX_EVENT_FIFO);
            txefgi++;
            if (txefgi == 1U)
            {
                txefgi = 0U;
            }
        }

        /* Ack the Tx Event FIFO position */
        CAN0_REGS->CAN_TXEFA = CAN_TXEFA_EFAI((uint32_t)txefgi);

        txFifo_event = true;
    }
    return txFifo_event;
}

// *****************************************************************************
/* Function:
    bool CAN0_MessageReceive(uint8_t bufferNumber, CAN_RX_BUFFER *rxBuffer)

   Summary:
    Read a message from the specific Rx Buffer.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    bufferNumber - Rx buffer number
    rxBuffer     - Pointer to Rx buffer

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_MessageReceive(uint8_t bufferNumber, CAN_RX_BUFFER *rxBuffer)
{
    uint8_t *rxBuf = NULL;
    bool message_receive_event = false;

    if((rxBuffer != NULL) && (bufferNumber < 1U))
    {
        rxBuf = (uint8_t *) ((uint8_t *)can0Obj.msgRAMConfig.rxBuffersAddress + ((uint32_t)bufferNumber * CAN0_RX_BUFFER_ELEMENT_SIZE));

        (void)memcpy((uint8_t *)rxBuffer, rxBuf, CAN0_RX_BUFFER_ELEMENT_SIZE);

        /* Clear new data flag */
        CAN0_REGS->CAN_NDAT1 = (1UL << bufferNumber);
        message_receive_event = true;
    }
    return message_receive_event;
}

// *****************************************************************************
/* Function:
    bool CAN0_MessageReceiveFifo(CAN_RX_FIFO_NUM rxFifoNum, uint8_t numberOfMessage, CAN_RX_BUFFER *rxBuffer)

   Summary:
    Read messages from Rx FIFO0/FIFO1.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    rxFifoNum       - Rx FIFO number
    numberOfMessage - Total number of message
    rxBuffer        - Pointer to Rx buffer

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_MessageReceiveFifo(CAN_RX_FIFO_NUM rxFifoNum, uint8_t numberOfMessage, CAN_RX_BUFFER *rxBuffer)
{
    uint8_t rxgi = 0U;
    uint8_t count = 0U;
    uint8_t *rxFifo = NULL;
    uint8_t *rxBuf = (uint8_t *)rxBuffer;
    bool status = false;

    if (rxBuffer != NULL)
    {
        switch (rxFifoNum)
        {
            case CAN_RX_FIFO_0:
                /* Read data from the Rx FIFO0 */
                rxgi = (uint8_t)((CAN0_REGS->CAN_RXF0S & CAN_RXF0S_F0GI_Msk) >> CAN_RXF0S_F0GI_Pos);
                for (count = 0U; count < numberOfMessage; count++)
                {
                    rxFifo = (uint8_t *) ((uint8_t *)can0Obj.msgRAMConfig.rxFIFO0Address + ((uint32_t)rxgi * CAN0_RX_FIFO0_ELEMENT_SIZE));

                    (void) memcpy(rxBuf, rxFifo, CAN0_RX_FIFO0_ELEMENT_SIZE);

                    if ((count + 1U) == numberOfMessage)
                    {
                        break;
                    }
                    rxBuf += CAN0_RX_FIFO0_ELEMENT_SIZE;
                    rxgi++;
                    if (rxgi == 1U)
                    {
                        rxgi = 0U;
                    }
                }

                /* Ack the fifo position */
                CAN0_REGS->CAN_RXF0A = CAN_RXF0A_F0AI((uint32_t)rxgi);

                status = true;
                break;
            case CAN_RX_FIFO_1:
                /* Read data from the Rx FIFO1 */
                rxgi = (uint8_t)((CAN0_REGS->CAN_RXF1S & CAN_RXF1S_F1GI_Msk) >> CAN_RXF1S_F1GI_Pos);
                for (count = 0U; count < numberOfMessage; count++)
                {
                    rxFifo = (uint8_t *) ((uint8_t *)can0Obj.msgRAMConfig.rxFIFO1Address + ((uint32_t)rxgi * CAN0_RX_FIFO1_ELEMENT_SIZE));

                    (void) memcpy(rxBuf, rxFifo, CAN0_RX_FIFO1_ELEMENT_SIZE);

                    if ((count + 1U) == numberOfMessage)
                    {
                        break;
                    }
                    rxBuf += CAN0_RX_FIFO1_ELEMENT_SIZE;
                    rxgi++;
                    if (rxgi == 1U)
                    {
                        rxgi = 0U;
                    }
                }
                /* Ack the fifo position */
                CAN0_REGS->CAN_RXF1A = CAN_RXF1A_F1AI((uint32_t)rxgi);

                status = true;
                break;
            default:
                /* Do nothing */
                break;
        }
    }
    return status;
}

// *****************************************************************************
/* Function:
    CAN_ERROR CAN0_ErrorGet(void)

   Summary:
    Returns the error during transfer.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    Error during transfer.
*/
CAN_ERROR CAN0_ErrorGet(void)
{
    CAN_ERROR error;
    uint32_t   errorStatus = CAN0_REGS->CAN_PSR;

    error = (CAN_ERROR) ((errorStatus & CAN_PSR_LEC_Msk) | (errorStatus & CAN_PSR_EP_Msk) | (errorStatus & CAN_PSR_EW_Msk)
            | (errorStatus & CAN_PSR_BO_Msk) | (errorStatus & CAN_PSR_DLEC_Msk) | (errorStatus & CAN_PSR_PXE_Msk));

    if ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        CAN0_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
        while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
        {
            /* Wait for initialization complete */
        }
    }

    return error;
}

// *****************************************************************************
/* Function:
    void CAN0_ErrorCountGet(uint8_t *txErrorCount, uint8_t *rxErrorCount)

   Summary:
    Returns the transmit and receive error count during transfer.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    txErrorCount - Transmit Error Count to be received
    rxErrorCount - Receive Error Count to be received

   Returns:
    None.
*/
void CAN0_ErrorCountGet(uint8_t *txErrorCount, uint8_t *rxErrorCount)
{
    *txErrorCount = (uint8_t)(CAN0_REGS->CAN_ECR & CAN_ECR_TEC_Msk);
    *rxErrorCount = (uint8_t)((CAN0_REGS->CAN_ECR & CAN_ECR_REC_Msk) >> CAN_ECR_REC_Pos);
}

// *****************************************************************************
/* Function:
    void CAN0_MessageRAMConfigSet(uint8_t *msgRAMConfigBaseAddress)

   Summary:
    Set the Message RAM Configuration.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    msgRAMConfigBaseAddress - Pointer to application allocated buffer base address.
                              Application must allocate buffer from non-cached
                              contiguous memory and buffer size must be
                              CAN0_MESSAGE_RAM_CONFIG_SIZE

   Returns:
    None
*/
/* MISRA C-2012 Rule 11.3 violated 7 times below. Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1*/
void CAN0_MessageRAMConfigSet(uint8_t *msgRAMConfigBaseAddress)
{
    uint32_t offset = 0U;
    uint32_t msgRAMConfigBaseAddr = (uint32_t)msgRAMConfigBaseAddress;

    (void) memset(msgRAMConfigBaseAddress, 0x00, CAN0_MESSAGE_RAM_CONFIG_SIZE);

    /* Set CAN CCCR Init for Message RAM Configuration */
    CAN0_REGS->CAN_CCCR |= CAN_CCCR_INIT_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) != CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }

    /* Set CCE to unlock the configuration registers */
    CAN0_REGS->CAN_CCCR |= CAN_CCCR_CCE_Msk;

    can0Obj.msgRAMConfig.rxFIFO0Address = (can_mram_rxbe_registers_t *)msgRAMConfigBaseAddr;
    offset = CAN0_RX_FIFO0_SIZE;
    /* Receive FIFO 0 Configuration Register */
    CAN0_REGS->CAN_RXF0C = CAN_RXF0C_F0S(1UL) | CAN_RXF0C_F0WM(0UL) | CAN_RXF0C_F0OM_Msk |
            CAN_RXF0C_F0SA(((uint32_t)can0Obj.msgRAMConfig.rxFIFO0Address >> 2));

    can0Obj.msgRAMConfig.rxFIFO1Address = (can_mram_rxbe_registers_t *)(msgRAMConfigBaseAddr + offset);
    offset += CAN0_RX_FIFO1_SIZE;
    /* Receive FIFO 1 Configuration Register */
    CAN0_REGS->CAN_RXF1C = CAN_RXF1C_F1S(1UL) | CAN_RXF1C_F1WM(0UL) | CAN_RXF1C_F1OM_Msk |
            CAN_RXF1C_F1SA(((uint32_t)can0Obj.msgRAMConfig.rxFIFO1Address >> 2));

    can0Obj.msgRAMConfig.rxBuffersAddress = (can_mram_rxbe_registers_t *)(msgRAMConfigBaseAddr + offset);
    offset += CAN0_RX_BUFFER_SIZE;
    CAN0_REGS->CAN_RXBC = CAN_RXBC_RBSA(((uint32_t)can0Obj.msgRAMConfig.rxBuffersAddress >> 2));

    can0Obj.msgRAMConfig.txBuffersAddress = (can_mram_txbe_registers_t *)(msgRAMConfigBaseAddr + offset);
    offset += CAN0_TX_FIFO_BUFFER_SIZE;
    /* Transmit Buffer/FIFO Configuration Register */
    CAN0_REGS->CAN_TXBC = CAN_TXBC_TFQS(1UL) |
            CAN_TXBC_TBSA(((uint32_t)can0Obj.msgRAMConfig.txBuffersAddress >> 2));

    can0Obj.msgRAMConfig.txEventFIFOAddress =  (can_mram_txefe_registers_t *)(msgRAMConfigBaseAddr + offset);
    offset += CAN0_TX_EVENT_FIFO_SIZE;
    /* Transmit Event FIFO Configuration Register */
    CAN0_REGS->CAN_TXEFC = CAN_TXEFC_EFWM(0UL) | CAN_TXEFC_EFS(1UL) |
            CAN_TXEFC_EFSA(((uint32_t)can0Obj.msgRAMConfig.txEventFIFOAddress >> 2));

    can0Obj.msgRAMConfig.stdMsgIDFilterAddress = (can_mram_sidfe_registers_t *)(msgRAMConfigBaseAddr + offset);
    (void) memcpy((void*)can0Obj.msgRAMConfig.stdMsgIDFilterAddress,
           (const void*)can0StdFilter,
           CAN0_STD_MSG_ID_FILTER_SIZE);
    offset += CAN0_STD_MSG_ID_FILTER_SIZE;
    /* Standard ID Filter Configuration Register */
    CAN0_REGS->CAN_SIDFC = CAN_SIDFC_LSS(2UL) |
            CAN_SIDFC_FLSSA(((uint32_t)can0Obj.msgRAMConfig.stdMsgIDFilterAddress >> 2));

    can0Obj.msgRAMConfig.extMsgIDFilterAddress = (can_mram_xidfe_registers_t *)(msgRAMConfigBaseAddr + offset);
    (void) memcpy((void*)can0Obj.msgRAMConfig.extMsgIDFilterAddress,
           (const void*)can0ExtFilter,
           CAN0_EXT_MSG_ID_FILTER_SIZE);
    /* Extended ID Filter Configuration Register */
    CAN0_REGS->CAN_XIDFC = CAN_XIDFC_LSE(2UL) |
            CAN_XIDFC_FLESA(((uint32_t)can0Obj.msgRAMConfig.extMsgIDFilterAddress >> 2));


    /* Reference offset variable once to remove warning about the variable not being used after increment */
    (void)offset;

    /* Complete Message RAM Configuration by clearing CAN CCCR Init */
    CAN0_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        /* Wait for configuration complete */
    }
}
/* MISRAC 2012 deviation block end for Rule 11.3*/


// *****************************************************************************
/* Function:
    bool CAN0_StandardFilterElementSet(uint8_t filterNumber, can_mram_sidfe_registers_t *stdMsgIDFilterElement)

   Summary:
    Set a standard filter element configuration.

   Precondition:
    CAN0_Initialize and CAN0_MessageRAMConfigSet must have been called
    for the associated CAN instance.

   Parameters:
    filterNumber          - Standard Filter number to be configured.
    stdMsgIDFilterElement - Pointer to Standard Filter Element configuration to be set on specific filterNumber.

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_StandardFilterElementSet(uint8_t filterNumber, can_mram_sidfe_registers_t *stdMsgIDFilterElement)
{
    bool retval = false;
    if (!((filterNumber > 2U) || (stdMsgIDFilterElement == NULL)))
    {
        can0Obj.msgRAMConfig.stdMsgIDFilterAddress[filterNumber - 1U].CAN_S0 = stdMsgIDFilterElement->CAN_S0;
        retval = true;
    }
    return retval;
}

// *****************************************************************************
/* Function:
    bool CAN0_StandardFilterElementGet(uint8_t filterNumber, can_mram_sidfe_registers_t *stdMsgIDFilterElement)

   Summary:
    Get a standard filter element configuration.

   Precondition:
    CAN0_Initialize and CAN0_MessageRAMConfigSet must have been called
    for the associated CAN instance.

   Parameters:
    filterNumber          - Standard Filter number to get filter configuration.
    stdMsgIDFilterElement - Pointer to Standard Filter Element configuration for storing filter configuration.

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_StandardFilterElementGet(uint8_t filterNumber, can_mram_sidfe_registers_t *stdMsgIDFilterElement)
{
    bool retval = false;
    if (!((filterNumber > 2U) || (stdMsgIDFilterElement == NULL)))
    {
        stdMsgIDFilterElement->CAN_S0 = can0Obj.msgRAMConfig.stdMsgIDFilterAddress[filterNumber - 1U].CAN_S0;
        retval = true;
    }
    return retval;
}

// *****************************************************************************
/* Function:
    bool CAN0_ExtendedFilterElementSet(uint8_t filterNumber, can_mram_xidfe_registers_t *extMsgIDFilterElement)

   Summary:
    Set a Extended filter element configuration.

   Precondition:
    CAN0_Initialize and CAN0_MessageRAMConfigSet must have been called
    for the associated CAN instance.

   Parameters:
    filterNumber          - Extended Filter number to be configured.
    extMsgIDFilterElement - Pointer to Extended Filter Element configuration to be set on specific filterNumber.

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_ExtendedFilterElementSet(uint8_t filterNumber, can_mram_xidfe_registers_t *extMsgIDFilterElement)
{
    bool retval = false;
    if (!((filterNumber > 2U) || (extMsgIDFilterElement == NULL)))
    {
        can0Obj.msgRAMConfig.extMsgIDFilterAddress[filterNumber - 1U].CAN_F0 = extMsgIDFilterElement->CAN_F0;
        can0Obj.msgRAMConfig.extMsgIDFilterAddress[filterNumber - 1U].CAN_F1 = extMsgIDFilterElement->CAN_F1;
        retval = true;
    }
    return retval;
}

// *****************************************************************************
/* Function:
    bool CAN0_ExtendedFilterElementGet(uint8_t filterNumber, can_mram_xidfe_registers_t *extMsgIDFilterElement)

   Summary:
    Get a Extended filter element configuration.

   Precondition:
    CAN0_Initialize and CAN0_MessageRAMConfigSet must have been called
    for the associated CAN instance.

   Parameters:
    filterNumber          - Extended Filter number to get filter configuration.
    extMsgIDFilterElement - Pointer to Extended Filter Element configuration for storing filter configuration.

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN0_ExtendedFilterElementGet(uint8_t filterNumber, can_mram_xidfe_registers_t *extMsgIDFilterElement)
{
    bool retval = false;
    if (!((filterNumber > 2U) || (extMsgIDFilterElement == NULL)))
    {
        extMsgIDFilterElement->CAN_F0 = can0Obj.msgRAMConfig.extMsgIDFilterAddress[filterNumber - 1U].CAN_F0;
        extMsgIDFilterElement->CAN_F1 = can0Obj.msgRAMConfig.extMsgIDFilterAddress[filterNumber - 1U].CAN_F1;
        retval = true;
    }
    return retval;
}

void CAN0_SleepModeEnter(void)
{
    CAN0_REGS->CAN_CCCR |=  CAN_CCCR_CSR_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_CSA_Msk) != CAN_CCCR_CSA_Msk)
    {
        /* Wait for clock stop request to complete */
    }
}

void CAN0_SleepModeExit(void)
{
    CAN0_REGS->CAN_CCCR &=  ~CAN_CCCR_CSR_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_CSA_Msk) == CAN_CCCR_CSA_Msk)
    {
        /* Wait for no clock stop */
    }
    CAN0_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
    while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
    {
        /* Wait for initialization complete */
    }
}

bool CAN0_BitTimingCalculationGet(CAN_BIT_TIMING_SETUP *setup, CAN_BIT_TIMING *bitTiming)
{
    bool status = false;
    uint32_t numOfTimeQuanta;
    uint8_t tseg1;
    float temp1;
    float temp2;

    if ((setup != NULL) && (bitTiming != NULL))
    {
        if (setup->nominalBitTimingSet == true)
        {
            numOfTimeQuanta = CAN0_CLOCK_FREQUENCY / (setup->nominalBitRate * ((uint32_t)setup->nominalPrescaler + 1U));
            if ((numOfTimeQuanta >= 4U) && (numOfTimeQuanta <= 385U))
            {
                if (setup->nominalSamplePoint < 50.0f)
                {
                    setup->nominalSamplePoint = 50.0f;
                }
                temp1 = (float)numOfTimeQuanta;
                temp2 = (temp1 * setup->nominalSamplePoint) / 100.0f;
                tseg1 = (uint8_t)temp2;
                bitTiming->nominalBitTiming.nominalTimeSegment2 = (uint8_t)(numOfTimeQuanta - tseg1 - 1U);
                bitTiming->nominalBitTiming.nominalTimeSegment1 = tseg1 - 2U;
                bitTiming->nominalBitTiming.nominalSJW = bitTiming->nominalBitTiming.nominalTimeSegment2;
                bitTiming->nominalBitTiming.nominalPrescaler = setup->nominalPrescaler;
                bitTiming->nominalBitTimingSet = true;
                status = true;
            }
            else
            {
                bitTiming->nominalBitTimingSet = false;
            }
        }
        if (setup->dataBitTimingSet == true)
        {
            numOfTimeQuanta = CAN0_CLOCK_FREQUENCY / (setup->dataBitRate * ((uint32_t)setup->dataPrescaler + 1U));
            if ((numOfTimeQuanta >= 4U) && (numOfTimeQuanta <= 49U))
            {
                if (setup->dataSamplePoint < 50.0f)
                {
                    setup->dataSamplePoint = 50.0f;
                }
                temp1 = (float)numOfTimeQuanta;
                temp2 = (temp1 * setup->dataSamplePoint) / 100.0f;
                tseg1 = (uint8_t)temp2;
                bitTiming->dataBitTiming.dataTimeSegment2 = (uint8_t)(numOfTimeQuanta - tseg1 - 1U);
                bitTiming->dataBitTiming.dataTimeSegment1 = tseg1 - 2U;
                bitTiming->dataBitTiming.dataSJW = bitTiming->dataBitTiming.dataTimeSegment2;
                bitTiming->dataBitTiming.dataPrescaler = setup->dataPrescaler;
                bitTiming->dataBitTimingSet = true;
                status = true;
            }
            else
            {
                bitTiming->dataBitTimingSet = false;
                status = false;
            }
        }
    }

    return status;
}

bool CAN0_BitTimingSet(CAN_BIT_TIMING *bitTiming)
{
    bool status = false;
    bool nominalBitTimingSet = false;
    bool dataBitTimingSet = false;

    if ((bitTiming->nominalBitTimingSet == true)
    && (bitTiming->nominalBitTiming.nominalTimeSegment1 >= 0x1U)
    && (bitTiming->nominalBitTiming.nominalTimeSegment2 <= 0x7FU)
    && (bitTiming->nominalBitTiming.nominalPrescaler <= 0x1FFU)
    && (bitTiming->nominalBitTiming.nominalSJW <= 0x7FU))
    {
        nominalBitTimingSet = true;
    }

    if  ((bitTiming->dataBitTimingSet == true)
    &&  ((bitTiming->dataBitTiming.dataTimeSegment1 >= 0x1U) && (bitTiming->dataBitTiming.dataTimeSegment1 <= 0x1FU))
    &&  (bitTiming->dataBitTiming.dataTimeSegment2 <= 0xFU)
    &&  (bitTiming->dataBitTiming.dataPrescaler <= 0x1FU)
    &&  (bitTiming->dataBitTiming.dataSJW <= 0xFU))
    {
        dataBitTimingSet = true;
    }

    if ((nominalBitTimingSet == true) || (dataBitTimingSet == true))
    {
        /* Start CAN initialization */
        CAN0_REGS->CAN_CCCR = CAN_CCCR_INIT_Msk;
        while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) != CAN_CCCR_INIT_Msk)
        {
            /* Wait for initialization complete */
        }

        /* Set CCE to unlock the configuration registers */
        CAN0_REGS->CAN_CCCR |= CAN_CCCR_CCE_Msk;

        if (dataBitTimingSet == true)
        {
            /* Set Data Bit Timing and Prescaler Register */
            CAN0_REGS->CAN_DBTP = CAN_DBTP_DTSEG2(bitTiming->dataBitTiming.dataTimeSegment2) | CAN_DBTP_DTSEG1(bitTiming->dataBitTiming.dataTimeSegment1) | CAN_DBTP_DBRP(bitTiming->dataBitTiming.dataPrescaler) | CAN_DBTP_DSJW(bitTiming->dataBitTiming.dataSJW);
        }
        if (nominalBitTimingSet == true)
        {
            /* Set Nominal Bit timing and Prescaler Register */
            CAN0_REGS->CAN_NBTP  = CAN_NBTP_NTSEG2(bitTiming->nominalBitTiming.nominalTimeSegment2) | CAN_NBTP_NTSEG1(bitTiming->nominalBitTiming.nominalTimeSegment1) | CAN_NBTP_NBRP(bitTiming->nominalBitTiming.nominalPrescaler) | CAN_NBTP_NSJW(bitTiming->nominalBitTiming.nominalSJW);
        }

        /* Set the operation mode */
        CAN0_REGS->CAN_CCCR |= CAN_CCCR_FDOE_Msk | CAN_CCCR_BRSE_Msk;


        CAN0_REGS->CAN_CCCR &= ~CAN_CCCR_INIT_Msk;
        while ((CAN0_REGS->CAN_CCCR & CAN_CCCR_INIT_Msk) == CAN_CCCR_INIT_Msk)
        {
            /* Wait for initialization complete */
        }
        status = true;
    }
    return status;
}


// *****************************************************************************
/* Function:
    void CAN0_TxFifoCallbackRegister(CAN_TX_FIFO_CALLBACK callback, uintptr_t contextHandle)

   Summary:
    Sets the pointer to the function (and it's context) to be called when the
    given CAN's transfer events occur.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    callback - A pointer to a function with a calling signature defined
    by the CAN_TX_FIFO_CALLBACK data type.

    contextHandle - A value (usually a pointer) passed (unused) into the function
    identified by the callback parameter.

   Returns:
    None.
*/
void CAN0_TxFifoCallbackRegister(CAN_TX_FIFO_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        can0TxFifoCallbackObj.callback = callback;
        can0TxFifoCallbackObj.context = contextHandle;
    }
}

// *****************************************************************************
/* Function:
    void CAN0_TxEventFifoCallbackRegister(CAN_TX_EVENT_FIFO_CALLBACK callback, uintptr_t contextHandle)

   Summary:
    Sets the pointer to the function (and it's context) to be called when the
    given CAN's transfer events occur.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    callback - A pointer to a function with a calling signature defined
    by the CAN_TX_EVENT_FIFO_CALLBACK data type.

    contextHandle - A value (usually a pointer) passed (unused) into the function
    identified by the callback parameter.

   Returns:
    None.
*/
void CAN0_TxEventFifoCallbackRegister(CAN_TX_EVENT_FIFO_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        can0TxEventFifoCallbackObj.callback = callback;
        can0TxEventFifoCallbackObj.context = contextHandle;

    }
}

// *****************************************************************************
/* Function:
    void CAN0_RxBuffersCallbackRegister(CAN_TXRX_BUFFERS_CALLBACK callback, uintptr_t contextHandle)

   Summary:
    Sets the pointer to the function (and it's context) to be called when the
    given CAN's transfer events occur.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    callback - A pointer to a function with a calling signature defined
    by the CAN_TXRX_BUFFERS_CALLBACK data type.

    contextHandle - A value (usually a pointer) passed (unused) into the function
    identified by the callback parameter.

   Returns:
    None.
*/
void CAN0_RxBuffersCallbackRegister(CAN_TXRX_BUFFERS_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        can0RxBufferCallbackObj.callback = callback;
        can0RxBufferCallbackObj.context = contextHandle;
    }
}

// *****************************************************************************
/* Function:
    void CAN0_RxFifoCallbackRegister(CAN_RX_FIFO_NUM rxFifoNum, CAN_RX_FIFO_CALLBACK callback, uintptr_t contextHandle)

   Summary:
    Sets the pointer to the function (and it's context) to be called when the
    given CAN's transfer events occur.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    rxFifoNum - Rx FIFO Number

    callback  - A pointer to a function with a calling signature defined
    by the CAN_RX_FIFO_CALLBACK data type.

    contextHandle - A value (usually a pointer) passed (unused) into the function
    identified by the callback parameter.

   Returns:
    None.
*/
void CAN0_RxFifoCallbackRegister(CAN_RX_FIFO_NUM rxFifoNum, CAN_RX_FIFO_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        can0RxFifoCallbackObj[rxFifoNum].callback = callback;
        can0RxFifoCallbackObj[rxFifoNum].context = contextHandle;
    }
}

// *****************************************************************************
/* Function:
    void CAN0_CallbackRegister(CAN_CALLBACK callback, uintptr_t contextHandle)

   Summary:
    Sets the pointer to the function (and it's context) to be called when the
    given CAN's transfer events occur.

   Precondition:
    CAN0_Initialize must have been called for the associated CAN instance.

   Parameters:
    callback  - A pointer to a function with a calling signature defined
    by the CAN_CALLBACK data type.

    contextHandle - A value (usually a pointer) passed (unused) into the function
    identified by the callback parameter.

   Returns:
    None.
*/
void CAN0_CallbackRegister(CAN_CALLBACK callback, uintptr_t contextHandle)
{
    if (callback != NULL)
    {
        can0CallbackObj.callback = callback;
        can0CallbackObj.context = contextHandle;
    }
}

// *****************************************************************************
/* Function:
    void CAN0_INT0_InterruptHandler(void)

   Summary:
    CAN0 Peripheral Interrupt Handler.

   Description:
    This function is CAN0 Peripheral Interrupt Handler and will
    called on every CAN0 interrupt.

   Precondition:
    None.

   Parameters:
    None.

   Returns:
    None.

   Remarks:
    The function is called as peripheral instance's interrupt handler if the
    instance interrupt is enabled. If peripheral instance's interrupt is not
    enabled user need to call it from the main while loop of the application.
*/
void __attribute__((used)) CAN0_INT0_InterruptHandler(void)
{
    uint32_t newData1 = 0U;
    uint8_t bufferNumber = 0U;
    uint8_t numberOfMessage = 0U;
    uint8_t numberOfTxEvent = 0U;

    uint32_t ir = CAN0_REGS->CAN_IR;
    /* Additional local variable to prevent MISRA violations (Rule 13.x) */
    uintptr_t context;

    if ((ir & (~(CAN_IR_RF0N_Msk | CAN_IR_RF1N_Msk | CAN_IR_DRX_Msk | CAN_IR_TFE_Msk | CAN_IR_TEFN_Msk))) != 0U)
    {
        CAN0_REGS->CAN_IR = (ir & (~(CAN_IR_RF0N_Msk | CAN_IR_RF1N_Msk | CAN_IR_DRX_Msk | CAN_IR_TFE_Msk | CAN_IR_TEFN_Msk)));
        if (can0CallbackObj.callback != NULL)
        {
            context = can0CallbackObj.context;
            can0CallbackObj.callback(ir, context);
        }
    }
    /* New Message in Rx FIFO 0 */
    if ((ir & CAN_IR_RF0N_Msk) != 0U)
    {
        CAN0_REGS->CAN_IR = CAN_IR_RF0N_Msk;

        numberOfMessage = (uint8_t)(CAN0_REGS->CAN_RXF0S & CAN_RXF0S_F0FL_Msk);

        if (can0RxFifoCallbackObj[CAN_RX_FIFO_0].callback != NULL)
        {
            context = can0RxFifoCallbackObj[CAN_RX_FIFO_0].context;
            can0RxFifoCallbackObj[CAN_RX_FIFO_0].callback(numberOfMessage, context);
        }
    }
    /* New Message in Rx FIFO 1 */
    if ((ir & CAN_IR_RF1N_Msk) != 0U)
    {
        CAN0_REGS->CAN_IR = CAN_IR_RF1N_Msk;

        numberOfMessage = (uint8_t)(CAN0_REGS->CAN_RXF1S & CAN_RXF1S_F1FL_Msk);

        if (can0RxFifoCallbackObj[CAN_RX_FIFO_1].callback != NULL)
        {
            context = can0RxFifoCallbackObj[CAN_RX_FIFO_1].context;
            can0RxFifoCallbackObj[CAN_RX_FIFO_1].callback(numberOfMessage, context);
        }
    }
    /* New Message in Dedicated Rx Buffer */
    if ((ir & CAN_IR_DRX_Msk) != 0U)
    {
        CAN0_REGS->CAN_IR = CAN_IR_DRX_Msk;

        newData1 = CAN0_REGS->CAN_NDAT1;
        if (newData1 != 0U)
        {
            for (bufferNumber = 0U; bufferNumber < 1U; bufferNumber++)
            {
                if ((newData1 & (1UL << bufferNumber)) == (1UL << bufferNumber))
                {
                    if (can0RxBufferCallbackObj.callback != NULL)
                    {
                        context = can0RxBufferCallbackObj.context;
                        can0RxBufferCallbackObj.callback(bufferNumber, context);
                    }
                }
            }
        }
    }

    /* TX FIFO is empty */
    if ((ir & CAN_IR_TFE_Msk) != 0U)
    {
        CAN0_REGS->CAN_IR = CAN_IR_TFE_Msk;
        if (can0TxFifoCallbackObj.callback != NULL)
        {
            context = can0TxFifoCallbackObj.context;
            can0TxFifoCallbackObj.callback(context);
        }
    }
    /* Tx Event FIFO new entry */
    if ((ir & CAN_IR_TEFN_Msk) != 0U)
    {
        CAN0_REGS->CAN_IR = CAN_IR_TEFN_Msk;

        numberOfTxEvent = (uint8_t)(CAN0_REGS->CAN_TXEFS & CAN_TXEFS_EFFL_Msk);

        if (can0TxEventFifoCallbackObj.callback != NULL)
        {
            context = can0TxEventFifoCallbackObj.context;
            can0TxEventFifoCallbackObj.callback(numberOfTxEvent, context);
        }
    }
}

/*******************************************************************************
 End of File
*/
