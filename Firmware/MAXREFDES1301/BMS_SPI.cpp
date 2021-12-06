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

#include "BMS_SPI.h"

int return_value[ARRAY_SIZE_15];
int CS;

/**
  @brief      Function is used for BMS SPI communication.
  @details    The variable arguments are received and sent in "for loop"  to complete the SPI transaction.
              The chip select is pulled low till completion of entire SPI command sequence in the transaction.
  @param[in]  "Arg_num" Gives the number of variable list of arguments.
  @param[in]  "..." Variable list of arguments for SPI communication.
  @return     returns "return_value" (pointer address) SPI array recived after SPI communication.
*/

int* BMS_SPI::SPI_commands(int Arg_num, ...)
{

  CS = SS1; //Connecting chip select of MAX17841 to SS1 of Arduino Mega.
  va_list arguments;
  va_start ( arguments, Arg_num );
  digitalWrite(CS, LOW);
  for ( int SPI_arg = 0; SPI_arg < Arg_num; SPI_arg++ )
  {
    return_value[SPI_arg] = SPI.transfer(va_arg(arguments, int));
  }
  digitalWrite(CS, HIGH);
  va_end ( arguments );
  delay(5);
  return return_value;

}
