/**********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
 * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/***********************************************************************/
/*                                                                     */
/*  FILE        :m_led.c		                                       */
/*  DATE        :Tue, Oct 31, 2006                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#include "include.h"

/****************************************************************************/
/* 		setAllLed, etc														*/
#if 1
// Set all LEDs
void setAllLeds()
{
	unsigned short dmy;
	
	dmy = 0;
	
	// Power LED
	dmy |= uint16Tbl[L_LED_1G];
	
	
	// Check if LED display is changed
	if(dmy ^ ledState){
		outputAllLeds(dmy);
		ledState = dmy;
	}
	
}

// Output all LEDs
void outputAllLeds(unsigned short ledValue)
{
	LED_SW = 0;
	LED_1R = outputSingleLed(ledValue, L_LED_1R);
	LED_1G = outputSingleLed(ledValue, L_LED_1G);
	LED_2R = outputSingleLed(ledValue, L_LED_2R);
	LED_2G = outputSingleLed(ledValue, L_LED_2G);
	LED_3G = outputSingleLed(ledValue, L_LED_3G);
	LED_4G = outputSingleLed(ledValue, L_LED_4G);
	LED_5G = outputSingleLed(ledValue, L_LED_5G);
	LED_W = outputSingleLed(ledValue, L_LED_W);
	LED_TM = outputSingleLed(ledValue, L_LED_TM);
	LED_FM = outputSingleLed(ledValue, L_LED_FM);
	LED_AM = outputSingleLed(ledValue, L_LED_AM);
}

// Output single LED
unsigned char outputSingleLed(unsigned short ledValue, unsigned char ledIndex)
{
	if(ledValue & uint16Tbl[ledIndex]){
		return 1;
	} else {
		return 0;
	}
}

#endif
/*		End of setAllLed													*/
/****************************************************************************/


/****************************************************************************/
/* 		setLed7, etc														*/
#if 1
// Set LED 7
void setLed7()
{
	unsigned char buff[4];
	unsigned char flg;
	unsigned char i;
	
	/*** Get LED7 display content here ***/
	// [----]
	for(i=0;i<sizeof(buff);i++){
		buff[i] = LED7_BAR;
	}
	
	// Check if LED7 display content is changed
	flg = 0;
	for(i=0;i<sizeof(buff);i++){
		if(buff[i] ^ led7Buff[i]){
			flg = 1;
			break;
		}
	}
	if(flg){
		outputAllLed7(&buff[0]);
		for(i=0;i<sizeof(buff);i++){
			led7Buff[i] = buff[i];
		}
	}
}

#endif
/*		End of setLed7														*/
/****************************************************************************/


/****************************************************************************/
/* 		LED7 output 														*/
#if 1
// Output all LED7
void outputAllLed7(unsigned char* sPos)
{
	unsigned char buff[4];
	unsigned char i;
	
	// Set LED7 segment value
	for(i=0;i<sizeof(led7Buff);i++){
		outputSingleLed7(i,led7SegCharTbl[*(sPos + i)]);
	}
	
	// Get LED7 segment value
	i = 0;
	buff[i++] = led7Out.P1.BYTE;
	buff[i++] = led7Out.P2.BYTE;
	buff[i++] = led7Out.P3.BYTE;
	buff[i++] = led7Out.P4.BYTE;
	
	// Output LED7 segment value to driver IC
	for(i=0;i<sizeof(led7Buff);i++){
		writeLed7(i, buff[i]);
	}
	
	// Set LED7 driver to output mode
	setLed7Output();
}

// Output single LED7
void outputSingleLed7(unsigned char ledIndex, unsigned char data)
{
	if(ledIndex == L_LED7_1){
        LED71_A = outputSingleLed(data, LED_A);
        LED71_B = outputSingleLed(data, LED_B);
        LED71_C = outputSingleLed(data, LED_C);
        LED71_D = outputSingleLed(data, LED_D);
        LED71_E = outputSingleLed(data, LED_E);
        LED71_F = outputSingleLed(data, LED_F);
        LED71_G = outputSingleLed(data, LED_G);
        LED71_DP = outputSingleLed(data, LED_DP);		
	} else if(ledIndex == L_LED7_2){
        LED72_A = outputSingleLed(data, LED_A);
        LED72_B = outputSingleLed(data, LED_B);
        LED72_C = outputSingleLed(data, LED_C);
        LED72_D = outputSingleLed(data, LED_D);
        LED72_E = outputSingleLed(data, LED_E);
        LED72_F = outputSingleLed(data, LED_F);
        LED72_G = outputSingleLed(data, LED_G);
        LED72_DP = outputSingleLed(data, LED_DP);		
	} else if(ledIndex == L_LED7_3){
        LED73_A = outputSingleLed(data, LED_A);
        LED73_B = outputSingleLed(data, LED_B);
        LED73_C = outputSingleLed(data, LED_C);
        LED73_D = outputSingleLed(data, LED_D);
        LED73_E = outputSingleLed(data, LED_E);
        LED73_F = outputSingleLed(data, LED_F);
        LED73_G = outputSingleLed(data, LED_G);
        LED73_DP = outputSingleLed(data, LED_DP);		
	} else {
        LED74_A = outputSingleLed(data, LED_A);
        LED74_B = outputSingleLed(data, LED_B);
        LED74_C = outputSingleLed(data, LED_C);
        LED74_D = outputSingleLed(data, LED_D);
        LED74_E = outputSingleLed(data, LED_E);
        LED74_F = outputSingleLed(data, LED_F);
        LED74_G = outputSingleLed(data, LED_G);
        LED74_DP = outputSingleLed(data, LED_DP);		
	}
}

// Set LED7 Driver to output mode
void setLed7Output()
{
	unsigned char chipAddr;
	unsigned char regAddr;
	unsigned char data;
	
	// Set the first driver
	chipAddr = I2C_ADDR_TCA6416AR_H;
	regAddr = TCA6416A_CONFIG_BANK_0;
	data = 0;
	if(!writeLed7Driver(chipAddr, regAddr, data)){
		return;
	}
	
	waitNmc(100);
	
	chipAddr = I2C_ADDR_TCA6416AR_H;
	regAddr = TCA6416A_CONFIG_BANK_1;
	data = 0;
	if(!writeLed7Driver(chipAddr, regAddr, data)){
		return;
	}
	
	waitNmc(100);
	
	// Set the second driver
	chipAddr = I2C_ADDR_TCA6416AR_L;
	regAddr = TCA6416A_CONFIG_BANK_0;
	data = 0;
	if(!writeLed7Driver(chipAddr, regAddr, data)){
		return;
	}
	
	waitNmc(100);
	
	chipAddr = I2C_ADDR_TCA6416AR_L;
	regAddr = TCA6416A_CONFIG_BANK_1;
	data = 0;
	if(!writeLed7Driver(chipAddr, regAddr, data)){
		return;
	}
}

#endif
/*		End of LED7 output													*/
/****************************************************************************/


/****************************************************************************/
/* 		LED7 driver 														*/
#if 1
// Write LED7 data
void writeLed7(unsigned char ledIndex, unsigned char data)
{
	unsigned char chipAddr;
	unsigned char regAddr;
	
	// Chip address
	if(ledIndex < 2){
		chipAddr = I2C_ADDR_TCA6416AR_L;
	} else {
		chipAddr = I2C_ADDR_TCA6416AR_H;
	}
	
	// Register address
    if(ledIndex % 2){
        regAddr = 0x02;
    } else {
        regAddr = 0x03;
    }
	
	// Write data to LED7 driver
	writeLed7Driver(chipAddr, regAddr, data);
	
}

// Write data to LED7 driver
unsigned char writeLed7Driver(unsigned char chipAddr, unsigned char regAddr, unsigned char data)
{
	unsigned char flg;
	
	flg = 0;
	
	// Output start condition
	setI2CStartCondition();
	
	// Output chip address (write command)
	if(!writeI2CDataAndCheckAck(chipAddr)){
		goto END;
	}
	
	// Output register address (command)
	if(!writeI2CDataAndCheckAck(regAddr)){
		goto END;
	}
	
	// Output data
	if(!writeI2CDataAndCheckAck(data)){
		goto END;
	}
	
	flg = 1;
END:
	// Output stop condition
	setI2CStopCondition();
	
	return flg;
}

// Set start condition on I2C bus
void setI2CStartCondition()
{
    SDA_LED_D = 0;	//SDA_HIGH
    SCL_LED_D = 0;	//SCL_HIGH
    waitNmc(SCL_HIGH2);
    SDA_LED = 0;	//SDA_LOW
    SDA_LED_D = 1;
    waitNmc(SCL_HIGH2);
}

// Set stop condition on I2C bus
void setI2CStopCondition()
{
    SCL_LED = 0;
    SCL_LED_D = 1;	// SCL LOW
    waitNmc(SCL_LOW);
    SDA_LED = 0;	// SDA LOW
    SDA_LED_D = 1;
    SCL_LED_D = 0;	// SCL HIGH
    waitNmc(SCL_HIGH);
    SDA_LED_D = 0;	// SDA HIGH
}

// Output 8 bit and check ack
unsigned char writeI2CDataAndCheckAck(unsigned char data)
{
	unsigned char pos;
	
	pos = 0x80;
	while(pos){
        SCL_LED = 0;	//SCL_LOW
        SCL_LED_D = 1;
        if(pos & data){
            SDA_LED_D = 0;
        }
        else{
            SDA_LED = 0;
            SDA_LED_D = 1;
        }
        waitNmc(SCL_LOW);
        SCL_LED_D = 0;	//SCL_HIGH
        waitNmc(SCL_HIGH);
		pos = pos >> 1;
	}
	
	if(checkI2CAck()){
		return 1;
	} else {
		return 0;
	}
}

// Check ACK fron I2C bus
unsigned char checkI2CAck()
{
    unsigned char tot;

    SCL_LED = 0;	//SCL_LOW
    SCL_LED_D = 1;
    waitNmc(SCL_LOW);
    SDA_LED_D = 0;	// SDA input
    SCL_LED_D = 0;	//SCL_HIGH
	
	tot = 100;
    while(SDA_LED_I && --tot);
	
	if(tot){
		return 1;
	} else {
		return 0;
	}
}

#endif
/*		End of LED7 driver													*/
/****************************************************************************/


