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

#include "V_measure.h"

/**
   @brief      Voltage measuremnt sequence.
   @details    Function is voltage measurment sequence for sending Single scan, cell voltage calculation and block voltage calculation for all devices in daisy chain.
   @param[in]  "Device_count" Number of Devices in the daisy chain.
   @return     None.
*/
void V_measure::V_measure_sequence(int Device_count)
{
  for (int DAx = 0; DAx < Device_count; DAx++)
  {
    Serial.print("DEVICE :");
    Serial.print(DAx);
    Serial.println(" VOLTAGE MEASUREMENTS");
    single_scan(write_add[DAx]);// Request new measurement sequence (scan) and initiate a data transfer.
    delay(HUNDRED_MILLISECOND);
    cell_V_cal(read_add[DAx]); //Reads each cell register and converts the raw value to cell voltage.
    block_V_cal(read_add[DAx]); //Reads Block voltage register and converts the raw value to Block voltage.
  }

}

/**
   @brief      Single scan sequence
   @details    Function is used to request a new measurement sequence (scan) and initiate a data transfer.
   @param[in]  "Device_add" Device address.
   @return     None.
*/
void V_measure::single_scan(int Write_Device_add)
{
  //SPI TRANSACTION : Writing ADDR_SCANCTRL
  PEC_VALUE = pec.pec_code(ARGUMENT_LEN_4, Write_Device_add, ADDR_SCANCTRL, lowByte(SCANCTRL), highByte(SCANCTRL));
  bms_SPI.SPI_commands(ARGUMENT_LEN_7, WR_LD_Q0, MESSAGE_LEN_5, Write_Device_add, ADDR_SCANCTRL, lowByte(SCANCTRL), highByte(SCANCTRL), PEC_VALUE);
  bms_SPI.SPI_commands(ARGUMENT_LEN_1, WR_NXT_LD_Q0);
  SPI_return = bms_SPI.SPI_commands(ARGUMENT_LEN_6, RD_NXT_MSG, NULL_XX, NULL_XX, NULL_XX, NULL_XX, NULL_XX);
  PEC_check_status = pec.PEC_Check(1, 5, SPI_return); //Checks the calculated and hardware returned PEC
  bms_SPI.SPI_commands(ARGUMENT_LEN_2, READ_RX_INTERRUPT_FLAGS, NULL_XX);
  bms_SPI.SPI_commands(ARGUMENT_LEN_2, 0x01, NULL_XX);

}

/**
   @brief      Cell Voltage calculation.
   @details    Function is for individual voltage measurement. Reads each cell register and converts the raw value to cell voltage.
   @param[in]  "Device_add" Device address.
   @return     None.
*/
void V_measure::cell_V_cal(int Read_Device_add)
{
  Serial.println("Cell Voltages");
  for (int cell_pointer = ADDR_CELL1REG ; cell_pointer <= ADDR_CELL14REG  ; cell_pointer++)
  {
    //SPI TRANSACTION : READ CELL REGISTERS

    PEC_VALUE = pec.pec_code(ARGUMENT_LEN_3, Read_Device_add, cell_pointer, DATA_CHECK); 
    bms_SPI.SPI_commands(ARGUMENT_LEN_7, WR_LD_Q0, MESSAGE_LEN_6, Read_Device_add, cell_pointer, DATA_CHECK, PEC_VALUE, ALIVE_COUNTER);
    bms_SPI.SPI_commands(ARGUMENT_LEN_1, WR_NXT_LD_Q0);
    SPI_return = bms_SPI.SPI_commands(ARGUMENT_LEN_8, RD_NXT_MSG, NULL_XX, NULL_XX, NULL_XX, NULL_XX, NULL_XX, NULL_XX, NULL_XX); 
    PEC_VALUE = pec.PEC_Check(PEC_START_ARG_1, PEC_END_ARG_5, SPI_return); //Checks the calculated and hardware returned PEC
    int CELL_VGE_MSB = SPI_return[4];
    int CELL_VGE_LSB = SPI_return[3];
    unsigned int raw = (CELL_VGE_LSB) + (CELL_VGE_MSB << SHIFT_BY_EIGHT); // local variable
    float CELL_VGE = (raw >> SHIFT_BY_TWO) * VOLTAGE_REF / VOLTAGE_REF_HEX ;
    Serial.print("Cell ");
    Serial.print(cell_pointer - ADDR_CELL1REG + 1);
    Serial.print(" HEX value : ");
    Serial.print(CELL_VGE_MSB, HEX);
    Serial.print(CELL_VGE_LSB, HEX);
    Serial.print(" Decimal value : ");
    Serial.println(CELL_VGE, SERIAL_DEC_PLACE_3);
  }
}

/**
   @brief      Block voltage measurment.
   @details    Function is for reading block voltage register and converts raw value to Block voltage.
   @param[in]  "Device_add" Device address.
   @return     None.
*/
void V_measure::block_V_cal(int Read_Device_add)
{
  //SPI TRANSACTION : BLOCK VOLTAGE REGISTERS

  PEC_VALUE = pec.pec_code(ARGUMENT_LEN_3, Read_Device_add, ADDR_BLOCKREG, DATA_CHECK); 
  bms_SPI.SPI_commands(ARGUMENT_LEN_7, WR_LD_Q0, MESSAGE_LEN_6, Read_Device_add, ADDR_BLOCKREG, DATA_CHECK, PEC_VALUE, ALIVE_COUNTER);
  bms_SPI.SPI_commands(ARGUMENT_LEN_1, WR_NXT_LD_Q0);
  SPI_return = bms_SPI.SPI_commands(ARGUMENT_LEN_8, RD_NXT_MSG, NULL_XX, NULL_XX, NULL_XX, NULL_XX, NULL_XX, NULL_XX, NULL_XX);
  PEC_VALUE = pec.PEC_Check(PEC_START_ARG_1, PEC_END_ARG_5, SPI_return); //Checks the calculated and hardware returned PEC
  int BLOCK_VGE_MSB = SPI_return[3];
  int BLOCK_VGE_LSB = SPI_return[4];
  unsigned int raw = (BLOCK_VGE_MSB) + ( BLOCK_VGE_LSB << SHIFT_BY_EIGHT); // local variable
  float BLOCK_VGE = (raw >> SHIFT_BY_TWO) * FULL_SCALE_DCIN / FULL_SCALE_DCIN_HEX;
  Serial.println();
  Serial.print("Block Voltage Hex Value: ");
  Serial.print(BLOCK_VGE_LSB, HEX);
  Serial.print(BLOCK_VGE_MSB, HEX);
  Serial.print("Decimal Value:");
  Serial.println(BLOCK_VGE, SERIAL_DEC_PLACE_3);
  Serial.println();
}
