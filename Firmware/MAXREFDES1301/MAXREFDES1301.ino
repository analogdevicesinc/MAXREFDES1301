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
#include "MAXREFDES1301.h"

/**
  @brief        The standard Arduino setup and configuration.It runs the intialization of arduino and MAX1785X ICs.
  @return       None
****************************************************************************/
void setup()
{
  initialization.Arduino_Mega_init();//Initializes pins,pheripherals of Arduino Mega
  initialization.MAX1785X_init_sequence();//Initializes MAX1785x
}
/**
  @brief        The standard Arduino loop function used for repeating tasks. It executes voltage measurement functions in while loop with 1 seconds delay.
  @return       None
****************************************************************************/
void loop()
{
  /*
    The voltage measurement sequence is excecuted and the device count is passed to measure individual IC voltages in for loop.
    The Number of device "Device_count" is obtained from the Hello all command from the Initialization sequence.
  */
  v_measure.V_measure_sequence(Device_count);
  delay(ONE_SECOND);
}
