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

#ifndef INITIALIZATION_H
#define INITIALIZATION_H
#include "Arduino.h"
#include "PEC.h"
#include "BMS_SPI.h"
#include "Max17841.h"
#include "Max1785x.h"

#define BAUDRATE               115200 // Baud rate for Serial UART communication PC to Microcontroller
#define SPI_FREQUENCY          400000 //SPI frequency
#define SS1                    53    //Slave select in microcontroller for uno use 10 mega 53
#define SS2                    49    //Optional Slave select if Dual UART is used
#define SHDNL_MAX17841_1       48 //Shut down pin for MAX17841_1
#define SHDNL_MAX17841_2       46 //Optional Shut down pin for MAX17841_2 if Dual UART communication is used

#define PEC_START_1            1
#define PEC_START_2            2
#define PEC_START_3            3
#define PEC_START_4            4
#define PEC_START_5            5
#define PEC_START_6            6
#define PEC_START_7            7
#define PEC_START_8            8
#define PEC_START_9            9

#define ARGUMENT_LEN_1         1
#define ARGUMENT_LEN_2         2
#define ARGUMENT_LEN_3         3
#define ARGUMENT_LEN_4         4
#define ARGUMENT_LEN_5         5
#define ARGUMENT_LEN_6         6
#define ARGUMENT_LEN_7         7
#define ARGUMENT_LEN_8         8
#define ARGUMENT_LEN_9         9

#define MESSAGE_LEN_1          1
#define MESSAGE_LEN_2          2
#define MESSAGE_LEN_3          3
#define MESSAGE_LEN_4          4
#define MESSAGE_LEN_5          5
#define MESSAGE_LEN_6          6
#define MESSAGE_LEN_7          7
#define MESSAGE_LEN_8          8
#define MESSAGE_LEN_9          9

#define SHIFT_BY_THREE         3
#define SHIFT_BY_EIGHT         8
#define SHIFT_BY_TWO           2
#define PEC_START_ARG_1        1
#define PEC_END_ARG_5          5
#define ONE_SECOND             1000
#define HUNDRED_MILLISECOND    100

class Initialization
{
  public:
    void Arduino_Mega_init();
    void MAX1785X_init_sequence();
    void wakeup();
    int helloall();
    void init_address(int Device_count);
    void clear_status_fmea();
    void enable_measurement();
};
extern Initialization initialization;
extern int Device_count;
extern int read_add[32];
extern int write_add[32];
#endif
