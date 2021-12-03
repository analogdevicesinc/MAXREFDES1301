/*******************************************************************************
* Copyright (C) 2021 Maxim Integrated Products, Inc., All rights Reserved.
* 
* This software is protected by copyright laws of the United States and
* of foreign countries. This material may also be protected by patent laws
* and technology transfer regulations of the United States and of foreign
* countries. This software is furnished under a license agreement and/or a
* nondisclosure agreement and may only be used or reproduced in accordance
* with the terms of those agreements. Dissemination of this information to
* any party or parties not specified in the license agreement and/or
* nondisclosure agreement is expressly prohibited.
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
*******************************************************************************
*/
/**
  @file           MAX17841.h
  @brief          Contains the register definition of MAX17841. ( For more details refer to MAX17841 datsheet )
  @version        1.0
  @notes          Complies in arduino IDE complier. Tested using Ardunio 1.8.12.
*****************************************************************************/

/*
  MAX17841 LIBRARY REGITER AND COMMANDS
*/
#define CLR_TX_BUF     0x20 // Resets the transmit buffer to its default state and clears 

#define RX_RD_POINTER  0x91
#define RD_NXT_MSG     0x93
//
#define WR_NXT_LD_Q0   0xB0
#define WR_NXT_LD_Q1   0xB2
#define WR_NXT_LD_Q2   0xB4
#define WR_NXT_LD_Q3   0xB6
#define WR_NXT_LD_Q4   0xB8
#define WR_NXT_LD_Q5   0xBA
#define WR_NXT_LD_Q6   0xBC
//
#define WR_LD_Q0       0xC0
#define WR_LD_Q1       0xC2
#define WR_LD_Q2       0xC4
#define WR_LD_Q3       0xC6
#define WR_LD_Q4       0xC8
#define WR_LD_Q5       0xCA
#define WR_LD_Q6       0xCC
//
#define RD_LD_Q0       0xC1
#define RD_LD_Q1       0xC3
#define RD_LD_Q2       0xC5
#define RD_LD_Q3       0xC7
#define RD_LD_Q4       0xC9
#define RD_LD_Q5       0xCB
#define RD_LD_Q6       0xCD
//
#define CLR_RX_BUF     0xE0

#define READ_RX_STATUS                 0x01 // Reads RX_Status
#define READ_TX_STATUS                 0x03 //Reads TX_Status
#define WRITE_RX_INTERRUPT_ENABLE      0x04 //Write RX_Interrupt_Enable
#define READ_RX_INTERRUPT_ENABLE       0x05 //Read RX_Interrupt_Enable
#define WRITE_TX_INTERRUPT_ENABLE      0x06 //Write TX_Interrupt_Enable
#define READ_TX_INTERRUPT_ENABLE       0x07 //Read TX_Interrupt_Enable
#define WRITE_RX_INTERRUPT_FLAGS       0x08 //Write RX_Interrupt_Flags
#define READ_RX_INTERRUPT_FLAGS        0x09 //Read RX_Interrupt_Flags
#define WRITE_TX_INTERRUPT_FLAGS       0x0A //Write TX_Interrupt_Flags
#define READ_TX_INTERRUPT_FLAGS        0x0B //Read TX_Interrupt_Flags
#define WRITE_CONFIGURATION_1          0xOC //Write Configuration1
#define READ_CONFIGURATION_1           0x0D //Read Configuration1
#define WRITE_CONFIGURATION_2          0x0E //Write Configuration2
#define READ_CONFIGURATION_2           0x0F //Read Configuration2
#define WRITE_CONFIGURATION_3          0x10 //Write Configuration3
#define READ_CONFIGURATION_3           0x11 //Read Configuration3
#define READ_FMEA                      0x13 //Read FMEA
#define READ_MODEL                     0x15 //Read Model
#define READ_VERSION                   0x17 //Read Version
#define READ_RX_BYTE                   0x19 //Read RX_bte
#define READ_RX_SPACE                  0x1B //Read RX_space
#define READ_TX_QUEUE_SELECTS          0x95 //Read TX_queue_selects
#define READ_RX_READ_POINTER           0x97 //Read RX_Read_pointer
#define READ_RX_WRITE_POINTER          0x99 //Read RX_write_pointer
#define READ_RX_NEXT_MESSAGE           0x9B //Read RX_Next_message

#define KEEP_ALIVE_160_MICRO_SEC       0x05// Keep alive 160us

#define RX_ERROR_INT_ENABLE            0b1 //Interrupt enable for RX_Error_Status
#define RX_BUSY_INT_ENABLE             0b0 //Interrupt enable for RX_Busy_Status
#define RX_IDLE_INT_ENABLE             0b0 //Interrupt enable for RX_Idle_Status
#define RX_OVERFLOW_INT_ENABLE         0b1 //Interrupt enable for RX_Overflow_Status
#define RX_FULL_INT_ENABLE             0b0 //Interrupt enable for RX_Full_Status
#define RX_STOP_INT_ENABLE             0b0 //Interrupt enable for RX_Stop_Status
#define RX_EMPTY_INT_ENABLE            0b0 //Interrupt enable for RX_Empty_Status

#define CONF_2_ENB_TRAMS_PREAMBLE      0x30 //Enable transmit preambles mode
#define CONF_2_DIS_TRAMS_PREAMBLE      0x10 //Disable transmit preambles mode

extern unsigned int RX_INTERRUPT_ENABLE;
