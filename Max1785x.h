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
  @file           MAX17852.h
  @brief          Contains the register definition of MAX17852. ( For more details refer to MAX17852 datsheet )
  @version        1.0
  @notes          Complies in arduino IDE complier. Tested using Ardunio 1.8.12.
*****************************************************************************/
/*
  MAX17843 LIBRARY REGITER AND COMMANDS
*/

#define DATA_CHECK             0x00   //Data check variable
#define ALIVE_COUNTER          0x00   //Alive counter
#define NULL_XX                0x00  //Null or Don't care value for SPI protocol

#define HELLOALL                  0x57
#define ALERTPACKET               0x21
#define WRITEDEVICE               0x04
#define WRITEALL                  0x02
#define READDEVICE                0x05
#define READALL                   0x03
#define READBLOCK                 0x06
#define DOWNHOST                  0x09
#define UPHOST                    0x08


// Status Registers
#define ADDR_VERSION               0x00
#define DEVICE_ADDRESS             0x01
#define ADDR_STATUS1               0x02
#define ADDR_STATUS2               0x03
#define ADDR_STATUS3               0x04
#define ADDR_FMEA1                 0x05
#define ADDR_FMEA2                 0x06
#define ALRTSUM                    0x07
#define ADDR_ALRTOVCELL            0x08
#define ADDR_ALRTUVCELL            0x09
#define ADDR_MINMAXCELL            0x0A
#define ADDR_ALRTAUPRTCTREG        0x0B
#define ADDR_ALRTAUXOVREG          0x0C
#define ADDR_ALRTAUXUVREG          0x0D
#define ADDR_ALRTCOMPOVREG         0x0E
#define ADDR_ALRTCOMPUVREG         0x0F
#define ADDR_ALRTCOMPAUXOVREG      0x10
#define ADDR_ALRTCOMPAUXUVREG      0x11
#define ADDR_ALRTBALSWREG          0x12
#define ADDR_SWACTION              0x13

//General configuration registers
#define ADDR_DEVCFG1               0x14
#define ADDR_DEVCFG2               0x15
#define ADDR_AUXGPIOCFG            0x16
#define ADDR_GPIOCFG               0x17
#define ADDR_PACKCFG               0x18

//Alert configuration registers
#define ADDR_ALRTIRQEN             0x19
#define ADDR_ALRTOVEN              0x1A
#define ADDR_ALRTUVEN              0x1B
#define ADDR_ALRTAUXOVEN           0x1C
#define ADDR_ALRTAUXUVEN           0x1D
#define ADDR_ALRTCALTST            0x1E

//THRESHOLD registers
#define ADDR_OVTHCLRREG            0x1F
#define ADDR_OVTHSETREG            0x20
#define ADDR_UVTHCLRREG            0x21
#define ADDR_UVTHSETREG            0x22
#define ADDR_MSMTCHREG             0x23
#define ADDR_BIPOVTHCLRREG         0x24
#define ADDR_BIPOVTHSETREG         0x25
#define ADDR_BIPUVTHCLRREG         0x26
#define ADDR_BIPUVTHSETREG         0x27
#define ADDR_BLKOVTHCLRREG         0x28
#define ADDR_BLKOVTHSETREG         0x29
#define ADDR_BLKUVTHCLRREG         0x2A
#define ADDR_BLKUVTHSETREG         0x2B
#define ADDR_CSAOVTHCLRREG         0x2C
#define ADDR_CSAOVTHSETREG         0x2D
#define ADDR_CSAUVTHCLRREG         0x2E
#define ADDR_CSAUVTHSETREG         0x2F
#define ADDR_AUXROVTHCLRREG        0x30
#define ADDR_AUXROVTHSETREG        0x31
#define ADDR_AUXRUVTHCLRREG        0x32
#define ADDR_AUXRUVTHSETREG        0x33
#define ADDR_AUXAOVTHCLRREG        0x34
#define ADDR_AUXOVTHSET            0x35
#define ADDR_AUXAUVTHCLRREG        0x36
#define ADDR_AUXAUVTHSETREG        0x37
#define COMPOVTHREG                0x38
#define COMPUVTHREG                0x39
#define COMPAUXROVTHREG            0x3A
#define COMPAUXRUVTHREG            0X3B
#define COMPAUXAOVTHREG            0X3C
#define COMPAUXAUVTHREG            0X3D


//DIAGNOSTIC threshold registers

#define ADDR_COMPOPNTHREG          0x3E
#define ADDR_COMPAUXROPNTHRE       0x3F
#define ADDR_COMPAUXAOPNTHRE       0x40
#define ADDR_COMPACCOVTHREG        0X41
#define ADDR_COMPACCUVTHREG        0X42
#define ADDR_BALSHRTTHRREG         0x43
#define ADDR_BALLOWTHRREG          0X44
#define ADDR_BALHIGHTHRREG         0X45

//CELL DATA REGISTER
#define ADDR_CSAREG                0x46
#define ADDR_CELL1REG              0x47
#define ADDR_CELL2REG              0x48
#define ADDR_CELL3REG              0x49
#define ADDR_CELL4REG              0x4A
#define ADDR_CELL5REG              0x4B
#define ADDR_CELL6REG              0x4C
#define ADDR_CELL7REG              0x4D
#define ADDR_CELL8REG              0x4E
#define ADDR_CELL9REG              0x4F
#define ADDR_CELL10REG             0x50
#define ADDR_CELL11REG             0x51
#define ADDR_CELL12REG             0x52
#define ADDR_CELL13REG             0x53
#define ADDR_CELL14REG             0x54
#define ADDR_BLOCKREG              0x55

// Total diag aux data register

#define ADDR_TOTALREG              0x56
#define ADDR_DIAG1REG              0x57
#define ADDR_DIAG2REG              0x58
#define ADDR_AUX0REG               0x59
#define ADDR_AUX1REG               0x5A
#define ADDR_AUX2REG               0x5B
#define ADDR_AUX3REG               0x5C

//SCAN SETTINGS REGISTERS
#define ADDR_POLARITYCTRL          0x5F
#define ADDR_AUXREFCTRL            0x60
#define ADDR_AUXTIMERREG           0x61
#define ADDR_ACQCFG                0x62
#define ADDR_BALSWDLY              0x63

//SCAN control registers

#define ADDR_MEASUREEN1            0x64
#define ADDR_MEASUREEN2            0x65
#define ADDR_SCANCTRL              0x66

//DIAGNOSTIC SETTING REGISTERS

#define ADDR_ADCTEST1AREG          0x67
#define ADDR_ADCTEST1BREG          0x68
#define ADDR_ADCTEST2AREG          0x69
#define ADDR_ADCTEST2BREG          0x6A

//DIAGNOSTIC CONTROL REGISTERS

#define ADDR_DIAGCFG               0x6B
#define ADDR_CTSTCFG               0x6C
#define ADDR_AUXTSTCFG             0x6D
#define ADDR_DIAGGENCFG            0x6E

//CELL BALANCING REGISTERS

#define ADDR_BALSWCTRL             0x6F
#define ADDR_BALEXP1               0x70
#define ADDR_BALEXP2               0x71
#define ADDR_BALEXP3               0x72
#define ADDR_BALEXP4               0x73
#define ADDR_BALEXP5               0x74
#define ADDR_BALEXP6               0x75
#define ADDR_BALEXP7               0x76
#define ADDR_BALEXP8               0x77
#define ADDR_BALEXP9               0x78
#define ADDR_BALEXP10              0x79
#define ADDR_BALEXP11              0x7A
#define ADDR_BALEXP12              0x7B
#define ADDR_BALEXP13              0x7C
#define ADDR_BALEXP14              0x7D
#define ADDR_BALAUTOUVTHR          0x7E
#define ADDR_BALDLYCTRL            0x7F
#define ADDR_BALCTRL               0x80
#define ADDR_BALSTAT               0x81
#define ADDR_BALUVSTAT             0x82
#define ADDR_BALDATA               0x83

//I2C master register
#define ADDR_I2CPNTR               0x84
#define ADDR_I2CWDATA1             0x85
#define ADDR_I2CWDATA2             0x86
#define ADDR_I2CRDATA1             0x87
#define ADDR_I2CRDATA2             0x88
#define ADDR_I2CCFG                0x89
#define ADDR_I2CSTAT               0x8A
#define ADDR_I2CSEND               0x8B

//ROM support register
#define ADDR_ID1                   0x8C
#define ADDR_ID2                   0x8D
#define ADDR_OTP2                  0x8E
#define ADDR_OTP3                  0x8F
#define ADDR_OTP4                  0x90
#define ADDR_OTP5                  0x91
#define ADDR_OTP6                  0x92
#define ADDR_OTP7                  0x93
#define ADDR_OTP8                  0x94
#define ADDR_OTP9                  0x95
#define ADDR_OTP10                 0x96
#define ADDR_OTP11                 0x97
#define ADDR_OTP12                 0x98

//MEASUREEN1 register
#define BLOCKEN               0b1   // Block Voltage Measureent enable
#define CELLEN                0b11111111111111   // Cell Voltage measurement enable

//STATUS1 register
#define ALRTSCAN              0b0   // SCAN DONE alert (Read Only) 
#define ALRTRST               0b0   // Reset Alert
#define ALRTMSMTCH            0b0   // Cell Voltage Mismatch Alert
#define ALRTCELLOVST          0b0   // Cell Overvoltage status summary alert
#define ALRTCELLUVST          0b0   // Cell Undervoltage status summary alert
#define ALRTBLKOVST           0b0   // Block Overvoltage status alert
#define ALRTBLKUVST           0b0   // Block Undervoltage status alert
#define ALRTAUXOVST           0b0   // Auxillary Overvoltage staus summary alert
#define ALRTAUXUVST           0b0   // Auxillary Undervoltage status summary alert
#define ALRTPEC               0b0   // Packet Error Check Alert
#define ALRTINTRFC            0b0   // Interface Specific Error Alert
#define ALRTCAL               0b0   // Calibration Fault Alert
#define ALRTCBAL              0b0   // Cell Balancing Status Alert
#define ALRTFMEA2             0b0   // FMEA2 Condition Summary Alert
#define ALRTFMEA1             0b0   // FMEA1 Condition Summary Alert

//FMEA1 register
#define ALRTOSC1              0b0   // 32KHz Oscillator fault alert 
#define ALRTOSC2              0b0   // 32 KHz Oscillator Fault alert (Redundant)
#define ALRTCOMMSEU1          0b0   // UART Upper Port Single Ended Alert
#define ALRTCOMMSEL1          0b0   // UART Lower Port Single Ended Alert
#define ALRTCOMMSEU2          0b0   // UART Upper Port Single Ended Alert (Redundant)
#define ALRTCOMMSEL2          0b0   // UART Lower Port Single Ended Alert (Redundant)
#define ALRTVDDL3             0b0   // VDDL3 Fault Alert
#define ALRTVDDL2             0b0   // VDDL2 Fault Alert
#define ALRTVDDL1             0b0   // VDDL1 Fault Alert
#define ALRTGNDL3             0b0   // GNDL3 Fault Alert
#define ALRTGNDL2             0b0   // GNDL2 Fault Alert
#define ALRTGNDL1             0b0   // GNDL1 Fault Alert
#define ALRTHVUV              0b0   // HV Undervoltage Fault Alert
#define ALRTHVHDRM            0b0   // HV Headroon Fault Alert
#define ALRTHVOV              0b0   // HV Overvoltage Fualt Alert
#define ALRTBALSWSUM          0b0   // Balance Switch Fault Alert Summary


//FMEA2 register
#define ALRTUSER              0b0   // User Defined Alert (Diagnostic) 
#define ALRTDCINMUX           0b0   // DCIN MUX-Fault Alert
#define ALRTAUXPRTCTSUM       0b0   // Auxiliary Protection Fault Alert Summary
#define ALRTTEMP              0b0   // Die Overtemperature Fault Alert
#define ALRTSCANTIMEOUT       0b0   // Scan Timeout Alert
#define ALRTADCZS             0b0   // ADC Zero Scale BIS Alert
#define ALRTADCFS             0b0   // ADC Full Scale BIST Alert
#define ALRTCOMPACCOV         0b0   // End of Sequence Comparator Accuracy Diagnostic Overvoltage Alert
#define ALRTCOMPACCUV         0b0   // End of Sequence Comparator Accuray Diagnostic Undervoltage Alert

//Scan control register
#define SCANDONE              0b0   // Acqusition complete indicator 
#define SCANTIMEOUT           0b0   // Scan Time Out Indicator Bit (Read only)
#define DATARDY               0b0   //Data Ready Indicatior (Read only)
#define AUTOBALSWDIS          0b1   //Enables automative suspension of active anual cell balancing operation during measurement sequences
#define ALRTFILTSEL           0b0   //Alert Issuance based on Raw sequencer Results (default)
#define AMENDFILT             0b0   //ADC result not inculded in the IIR accumulator (default)
#define RDFILT                0b0   //Unfiltered ADC data to the output data register (NO IIR Filter)(default)
#define SCANCFG               0b000 // Sampling ADC only
#define OVSAMPL               0b110 // 128x Oversampling
#define ALTUXSEL              0b0   //HVMUX signal Path (default)
#define SCANMODE              0b0   //Pyramid Scan mode (default)
#define SCAN                  0b1   // Request new measurement sequence

#define READDEVICE_LSB        5
#define WRITEDEVICE_LSB       4

extern unsigned int SCANCTRL;
extern unsigned int STATUS1;
extern unsigned int MEASUREEN1;
extern unsigned int FMEA1;
extern unsigned int FMEA2;
