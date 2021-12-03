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
#include "MAX1785x.h"

unsigned int SCANCTRL = SCAN + (SCANMODE << 1) + (ALTUXSEL << 2) + (OVSAMPL << 3) + (SCANCFG << 6) + (RDFILT << 9) + (AMENDFILT << 10) + ( ALRTFILTSEL << 11) + (AUTOBALSWDIS << 12) + (DATARDY << 13) + (SCANTIMEOUT << 14) + (SCANDONE << 15);
unsigned int STATUS1 = ALRTFMEA1 + (ALRTFMEA2 << 1) + (ALRTCBAL << 2) + (ALRTCAL << 3) + (ALRTINTRFC << 4) + (ALRTPEC << 5) + (ALRTAUXUVST << 7) + (ALRTAUXOVST << 8) + (ALRTBLKUVST << 9) + (ALRTBLKOVST << 10) + ( ALRTCELLUVST << 11) + (ALRTCELLOVST << 12) + (ALRTMSMTCH << 13) + (ALRTRST << 14) + (ALRTSCAN << 15);
unsigned int MEASUREEN1 = CELLEN + (BLOCKEN << 14);
unsigned int FMEA1 = ALRTBALSWSUM + (ALRTHVOV << 1) + (ALRTHVHDRM << 2) + (ALRTHVUV << 3) + (ALRTGNDL1 << 4) + (ALRTGNDL2 << 5) + (ALRTGNDL3 << 6) + (ALRTVDDL1 << 7) + (ALRTVDDL2 << 8) + (ALRTVDDL3 << 9) + (ALRTCOMMSEL2 << 10) + ( ALRTCOMMSEU2 << 11) + (ALRTCOMMSEL1 << 12) + (ALRTCOMMSEU1 << 13) + (ALRTOSC2 << 14) + (ALRTOSC1 < 15);
unsigned int FMEA2 = ALRTCOMPACCUV + (ALRTCOMPACCOV << 1) + (ALRTADCFS << 2) + (ALRTADCZS << 3) + ( ALRTSCANTIMEOUT << 11) + (ALRTTEMP << 12) + (ALRTAUXPRTCTSUM << 13) + (ALRTDCINMUX << 14) + (ALRTUSER << 15);
