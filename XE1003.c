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
/*  FILE        :Main.c or Main.cpp                                    */
/*  DATE        :Tue, Oct 31, 2006                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#include "include.h"

// Main loop (This function is called after reset)

void main(void)
{
	unsigned short i;
	unsigned char count10ms;
	unsigned char flg;
	
	// Disable ALL interrupt
	set_psw(0x00000000);
	
	// Stop Watchdog timer
    WDT.WRITE.WINA = 0xA59E;
    WDT.WRITE.WINB = 0x5A0F;
	
	// Init system clock
    SYSTEM.SCKCR.LONG = 0x00820100;	// ICK = 12.5MHz x 8 = 100MHz
                                    // BCK = 12.5MHz x 2 = 25MHz
                                    // PCK = 12.5MHz x 4 = 50MHz
                                    // PSTOP1 = 1 BCLK = HIGH
    SYSTEM.SYSCR0.WORD = 0x5A03;	// Enable external bus and internal ROM
	for(i = 0;i < 10000;i++);
	
	// Init SFRs
	initSfr();
	count10ms = 0;
	
	// Enable interrupt

	set_psw(0x00010000);
	
	// Main loop
	while(1){
		while(IR(CMT0,CMI0) == 0);
		IR(CMT0,CMI0) = 0;
        	 count10ms++;
		// countTime();
		// getAllSwState();
		// processAllSwState();
		// setAllLeds();
		// setLed7();
		setNor();
       
	}
}

/****************************************************************************/
/* 		Init routines														*/
#if 1
// Init SFRs
void initSfr()
{
	unsigned short i;
	
#if 1// Ports
    PORT0.DDR.BYTE = 0x03;
    PORT0.DR.BYTE = 0x00;
    PORT0.ICR.BYTE = 0x00;
    //PORT0.ODR.BYTE = 0x00;
    //PORT0.PCR.BYTE = 0x00;

    PORT1.DDR.BYTE = 0x3F;
    PORT1.DR.BYTE = 0x00;
    PORT1.ICR.BYTE = 0x00;
    //PORT1.ODR.BYTE = 0x00;
    //PORT1.PCR.BYTE = 0x00;

    PORT2.DDR.BYTE = 0x18;
    PORT2.DR.BYTE = 0x00;
    PORT2.ICR.BYTE = 0x00;
    PORT2.ODR.BYTE = 0x00;
    //PORT2.PCR.BYTE = 0x00;

    PORT3.DDR.BYTE = 0xE0;
    PORT3.DR.BYTE = 0x00;
    PORT3.ICR.BYTE = 0x1F;
    //PORT3.ODR.BYTE = 0x00;
    //PORT3.PCR.BYTE = 0x00;

    PORT4.DDR.BYTE = 0x00;
    PORT4.DR.BYTE = 0x00;
    PORT4.ICR.BYTE = 0x00;
    //PORT4.ODR.BYTE = 0x00;
    //PORT4.PCR.BYTE = 0x00;

    PORT5.DDR.BYTE = 0x72;
    PORT5.DR.BYTE = 0x00;
    PORT5.ICR.BYTE = 0x08;
    //PORT5.ODR.BYTE = 0x00;
    //PORT5.PCR.BYTE = 0x00;

    PORT6.DDR.BYTE = 0x20;
    PORT6.DR.BYTE = 0x00;
    PORT6.ICR.BYTE = 0x1F;
    //PORT6.ODR.BYTE = 0x00;
    //PORT6.PCR.BYTE = 0x00;

    PORT7.DDR.BYTE = 0xFF;
    PORT7.DR.BYTE = 0x00;
    PORT7.ICR.BYTE = 0x00;
    //PORT7.ODR.BYTE = 0x00;
    //PORT7.PCR.BYTE = 0x00;

    PORT8.DDR.BYTE = 0x7F;
    PORT8.DR.BYTE = 0x00;
    PORT8.ICR.BYTE = 0x00;
    //PORT8.ODR.BYTE = 0x00;
    //PORT8.PCR.BYTE = 0x00;

    PORT9.DDR.BYTE = 0x01;
    PORT9.DR.BYTE = 0x00;
    PORT9.ICR.BYTE = 0x00;
    //PORT9.ODR.BYTE = 0x00;
    //PORT9.PCR.BYTE = 0x00;

    PORTA.DDR.BYTE = 0xFF;
    PORTA.DR.BYTE = 0x00;
    PORTA.ICR.BYTE = 0x00;
    //PORTA.ODR.BYTE = 0x00;
    PORTA.PCR.BYTE = 0x00;

    PORTB.DDR.BYTE = 0xFF;
    PORTB.DR.BYTE = 0x00;
    PORTB.ICR.BYTE = 0x00;
    //PORTB.ODR.BYTE = 0x00;
    PORTB.PCR.BYTE = 0x00;

    PORTC.DDR.BYTE = 0xFF;
    //PORTC.DR.BYTE = 0x00;
    PORTC.DR.BYTE = 0x80;
    PORTC.ICR.BYTE = 0x00;
    PORTC.ODR.BYTE = 0x00;
    PORTC.PCR.BYTE = 0x00;

    PORTD.DDR.BYTE = 0x00;
    PORTD.DR.BYTE = 0x00;
    PORTD.ICR.BYTE = 0xFF;
    //PORTD.ODR.BYTE = 0x00;
    PORTD.PCR.BYTE = 0x00;

    PORTE.DDR.BYTE = 0x00;
    PORTE.DR.BYTE = 0x00;
    PORTE.ICR.BYTE = 0xFF;
    //PORTE.ODR.BYTE = 0x00;
    PORTE.PCR.BYTE = 0x00;

    // Set default state of IO ports
    RES1 = 1;
    RES2 = 1;
    RES3 = 1;
    RES4 = 1;
    RES5 = 1;
    RES6 = 1;
    VC33ME_ENA = 1;
    CS2 = 1;

    // LED_7seg I2C Line init
    SCL_LED_D = 0;
    SDA_LED_D = 0;
    RESET_LED = 0;
    nop();
    RESET_LED = 1;

#endif

#if 1// Timers
#if 1// CMT0 (10ms Counter)
    MSTP(CMT0) = 0;// Enable CMT0
    CMT0.CMCR.BIT.CMIE = 0;
    CMT.CMSTR0.BIT.STR0 = 0;// Stop CMT0
    CMT0.CMCR.BIT.CKS = 2;// 50MHz / 128 = 390.625kHz
    CMT0.CMCOR = 3906 - 1;// 390.625kHz / 3906 = 100Hz
    CMT0.CMCR.BIT.CMIE = 1;
    CMT0.CMCNT = 0;
    CMT.CMSTR0.BIT.STR0 = 1;// Start CMT0	
#endif

#if 1// CMT1 (Sampling Frequency)
    MSTP(CMT1) = 0;// Enable CMT1
    CMT1.CMCR.BIT.CMIE = 0;
    CMT.CMSTR0.BIT.STR1 = 0;// Stop CMT1
    CMT1.CMCR.BIT.CKS = 0;// 50MHz / 8 = 6250KHz
    CMT1.CMCOR = 781 - 1;// 6250KHz / 781 = 8KHz
    CMT1.CMCR.BIT.CMIE = 1;
    CMT1.CMCNT = 0;
    IR(CMT1, CMI1) = 0;
    IPR(CMT1, CMI1) = 1;

    //IEN(CMT1,CMI1) = 1;
    //CMT.CMSTR0.BIT.STR1 = 1;// Start CMT1
#endif
#endif

#if 1// SCIs

#if 1// SCI0(ERW7 UART mode)
    MSTP(SCI0) = 0;

    // SCI0 ƒ|[ƒgÝ’èiTxD0 => p2_0; RxD0 => p2_1j
    PORT2.ICR.BIT.B1 = 1;

    SCI0.SCR.BYTE = 0;
    SCI0.SMR.BYTE = 0;// PCLK x 1
    SCI0.SCMR.BYTE = 0;

    SCI0.BRR = 6;// 50MHz / 32 / (230400 - 1)
    //SCI0.BRR = 13;// 50MHz / 32 / (115200 - 1)
    //SCI0.BRR = 26;// 50MHz / 32 / (57600 - 1)
    //SCI0.BRR = 40;// 50MHz / 32 / (38400 - 1)
    //wait_n_10ms(5);
    for(i = 0;i < 10000;i++);

    IR(SCI0, RXI0) = 0;    /* Clear IR bits for TIE and RIE. */
    IR(SCI0, ERI0) = 0;
    IR(SCI0, TXI0) = 0;
    IPR(SCI0, RXI0) = 1;
    IPR(SCI0, ERI0) = 1;
    IPR(SCI0, TXI0) = 1;
    //IPR(SCI0,TEI0) = 1;  
    IEN(SCI0, RXI0) = 1;
    IEN(SCI0, ERI0) = 1;
    IEN(SCI0, TXI0) = 1;
    //IEN(SCI0,TEI0) = 1;

    //SCI0.SCR.BYTE = 0x50;
    SCI0.SCR.BYTE |= 0x30;
    SCI0.SCR.BIT.RIE = 1;
    SCI0.SCR.BIT.TIE = 1;
#endif

#if 1// SCI1 (SERIAL NAND Flash)
    MSTP(SCI1) = 0;
    PORT2.ICR.BIT.B5 = 1;

    //SYSTEM.MSTPCRB.BIT.MSTPB30 = 0; 

    // SCI1 port settings (P2_7 Clock; P2_6 TxD; P3_0 RxD; P3_1 CTS)
    // Register write protect enable
    //MPC.PWPR.BIT.B0WI = 0;
    //MPC.PWPR.BIT.PFSWE = 1;

    //MPC.P26PFS.BIT.PSEL = 0x0A;		// TxD1 => p2_6
    //MPC.P27PFS.BIT.PSEL = 0x0A;		// SCK1 => p2_7
    //MPC.P30PFS.BIT.PSEL = 0x0A;		// RxD1 => p3_0

    // Register write protect disable
    //MPC.PWPR.BIT.PFSWE = 0;
    //MPC.PWPR.BIT.B0WI = 1;

    // Port direction
    PORT2.DDR.BIT.B6 = 1;			// TxD output
    PORT2.DDR.BIT.B7 = 1;			// Clock output
    PORT2.DDR.BIT.B5 = 0;			// RxD input
    PORT2.DR.BIT.B4 = 1;			// Nand Flash Chip select OFF
    PORT2.DDR.BIT.B4 = 1;			// Chip select output CS2# Nand Flash

    // SCI1 initialization
    SCI1.SCR.BYTE = 0;
    //SCI1.SPMR.BYTE = 0x80;			// CKPH = 1; CPOL = 0;
    SCI1.SMR.BYTE = 0x80;			// Simple SPI mode (clock synchronous mode), 8 bit length, no parity, 1 stop bit, PLK clock
    SCI1.SCMR.BYTE = 0x7A;			// Non-smart card mode, MSB first
    SCI1.BRR = 1;                   // 50MHz/(8*2^(2*n-1)*B)-1;[n= 0PCLK clock, B = 6.25MHz]

    for(i = 0;i < 10000;i++);

    //UART1 start
    SCI1.SCR.BYTE |= 0x30;
    SCI1.SCR.BIT.RIE = 1;
    SCI1.SCR.BIT.TIE = 1;

    IR(SCI1, RXI1) = 0;    		// Clear IR bits for TIE and RIE.
    IR(SCI1, ERI1) = 0;
    IR(SCI1, TXI1) = 0;
    IPR(SCI1, RXI1) = 0x03;
    IPR(SCI1, ERI1) = 0x03;
    IPR(SCI1, TXI1) = 0x03;
    //IEN(SCI1,RXI1) = 1;
    //IEN(SCI1,ERI1) = 1;
    //IEN(SCI1,TXI1) = 0;
#endif

#endif

#if 1// External BUS
    // SYSCR0.EXBE = 1;
    SYSTEM.SYSCR0.WORD |= 0x5A02;    //External Bus   

    // Address bus
    PORTA.DDR.BYTE = 0xFF;              // (A0 ~ A7)
    PORTA.DR.BYTE = 0x00;
    //PORTA.DR.BYTE = 0xFF;
    PORTA.PCR.BYTE = 0xFF;
    IOPORT.PFCR4.BYTE = 0xFF;           // (A8 ~ A15)
    IOPORT.PFCR3.BYTE = 0xFF;           // (A16 ~ A23)
    //IOPORT.PFCR3.BYTE = 0x7F;           // (A16 ~ A22)

    // Data bus
    PORTD.DDR.BYTE = 0x00;			    // PORTD（D0 - D7)
    PORTD.DR.BYTE = 0x00;
    IOPORT.PFCR5.BYTE = 0x10;           // PORTE (D8 - D15)

    // CS
    IOPORT.PFCR0.BYTE = 0x7E;		    // CS1 ~ CS6 output enable

    // CS1 (P61)
    BSC.CS1CNT.WORD = 0x0001;			// CS1 operation enable （16 bit bus）
    BSC.CS1MOD.WORD = 0x0000;			// Disable page access
    BSC.CS1WCNT1.LONG = 0x04030000;		// Write wait 3 cycles, Read wait 4 cycles
    BSC.CS1WCNT2.LONG = 0x01100211;		// Read CS wait 1 cycle, Write CS wait 2 cycles, WR asert wait 1 cycle, Write data wait 1 cycle

    // CS2 (P62)
    IOPORT.PFCR2.BIT.CS2S = 0;          // CS2 > P62
    BSC.CS2CNT.WORD = 0x0001;			// CS2 operation enable （16 bit bus）
    BSC.CS2MOD.WORD = 0x0000;			// Disable page access
    BSC.CS2WCNT1.LONG = 0x04030000;		// Write wait 3 cycles, Read wait 4 cycles
    BSC.CS2WCNT2.LONG = 0x01100211;		// Read CS wait 1 cycle, Write CS wait 2 cycles, WR asert wait 1 cycle, Write data wait 1 cycle

    // CS3 (P63)
    IOPORT.PFCR2.BIT.CS3S = 0;          // CS3 > P63
    BSC.CS3CNT.WORD = 0x0001;			// CS3 operation enable （16 bit bus）
    BSC.CS3MOD.WORD = 0x0000;			// Disable page access
    BSC.CS3WCNT1.LONG = 0x04030000;		// Write wait 3 cycles, Read wait 4 cycles
    BSC.CS3WCNT2.LONG = 0x01100211;		// Read CS wait 1 cycle, Write CS wait 2 cycles, WR asert wait 1 cycle, Write data wait 1 cycle

    // CS4 (P64)
    IOPORT.PFCR1.BIT.CS4S = 1;		    // CS4 > P64
    BSC.CS4CNT.WORD = 0x0001;			// CS4 operation enable （16 bit bus）
    BSC.CS4MOD.WORD = 0x0000;			// Disable page access
    BSC.CS4WCNT1.LONG = 0x04030000;		// Write wait 3 cycles, Read wait 4 cycles
    BSC.CS4WCNT2.LONG = 0x01100211;		// Read CS wait 1 cycle, Write CS wait 2 cycles, WR asert wait 1 cycle, Write data wait 1 cycle

    // CS5 (P60)
    IOPORT.PFCR1.BIT.CS5S = 1;          // CS5 > P60
    BSC.CS5CNT.WORD = 0x0001;			// CS5 operation enable （16 bit bus）
    BSC.CS5MOD.WORD = 0x0000;			// Disable page access
    BSC.CS5WCNT1.LONG = 0x04030000;		// Write wait 3 cycles, Read wait 4 cycles
    BSC.CS5WCNT2.LONG = 0x01100211;		// Read CS wait 1 cycle, Write CS wait 2 cycles, WR asert wait 1 cycle, Write data wait 1 cycle

    // CS6 (P71)
    IOPORT.PFCR1.BIT.CS6S = 2;          // CS6 > P71
    BSC.CS6CNT.WORD = 0x0001;			// CS6 operation enable （16 bit bus）
    BSC.CS6MOD.WORD = 0x0000;			// Disable page access
    BSC.CS6WCNT1.LONG = 0x04030000;		// Write wait 3 cycles, Read wait 4 cycles
    BSC.CS6WCNT2.LONG = 0x01100211;		// Read CS wait 1 cycle, Write CS wait 2 cycles, WR asert wait 1 cycle, Write data wait 1 cycle

    // Enable BUS error monitor
    //BSC.BEREN.BYTE = 0x03;

#endif

#if 1// DAC
    PORT6.DDR.BIT.B6 = 0;	// DA0
    PORT6.DDR.BIT.B7 = 0;	// DA1
    MSTP(DA) = 0;
    DA.DADPR.BIT.DPSEL = 0;
    //DA.DADR0 = 512;		// For adjust voltage LED
    DA.DADR1 = 0x200;		// For Replay audio
    DA.DACR.BIT.DAE = 0;
    DA.DACR.BIT.DAOE0 = 1;
    DA.DACR.BIT.DAOE1 = 0;
    //DA.DACR.BIT.DAOE0 = 0;
    //DA.DACR.BIT.DAOE1 = 1;
#endif

#if 1// TMO

#if 1// TMO0 (Used as Beep sound reference clock)
    MSTP(TMR0) = 0;					// Enable TMR0

    //TMR0.TCSTR.BIT.TCS = 0;			// Stop TMR0
    TMR0.TCR.BIT.CCLR = 1;			// Cleared by compare match A
    TMR0.TCCR.BYTE = 0x0D;			// = PCLK / 1024 --> 50MH/1024 = 48.828125KHz, 1 cycle = 20.48us
    TMR0.TCSR.BIT.OSA = 2;			// TCORA match = HIGH
    TMR0.TCSR.BIT.OSB = 1;			// TCORB match = LOW

    MSTP(TMR0) = 1;					// Disable TMR0

#endif	
#endif

	
}

#endif
/* 		End of Init routines												*/
/****************************************************************************/



/****************************************************************************/
/* 		Operation               											*/
#if 1
// Set operate
void operate()
{
	
}

#endif
/* 		End of Operation													*/
/****************************************************************************/




/****************************************************************************/
/* 		Counter, wait														*/
#if 1
// Count time
void countTime()
{
	if(norTm){
		norTm--;
	}
}

// Wait n x 10ms
void wait10ms(unsigned short interval)
{
		
}

// Wait n x mc
void waitNmc(unsigned short interval)
{
	
}

#endif
/*		End of WAIT															*/
/****************************************************************************/

