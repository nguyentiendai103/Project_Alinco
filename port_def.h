#include "iodefine.h"

//Switch & button
#define SW1    PORT3.PORT.BIT.B4   // PIN NO. 25
#define SW2    PORT3.PORT.BIT.B3   // PIN NO. 26
#define SW3    PORT3.PORT.BIT.B2   // PIN NO. 27
#define SW4    PORT3.PORT.BIT.B1   // PIN NO. 28
#define SW5    PORT3.PORT.BIT.B0   // PIN NO. 29

//CN102 connector(NAND FLASH)
#define FLASH_ENA   PORT6.DR.BIT.B5   // PIN NO. 9
#define CS2    		PORT2.DR.BIT.B4   // PIN NO. 33

//Speaker control
#define SPVC    PORT8.DR.BIT.B6   // PIN NO. 17
#define SP    	PORT8.DR.BIT.B5   // PIN NO. 18
#define		AF_PWR		SPVC
#define		AF_SD		SP

//WDT reset
#define WDP    PORT2.DR.BIT.B3   // PIN NO. 34
#define WD     WDP

//Led
#define RESET_LED    PORT1.DR.BIT.B5   // PIN NO. 42
#define LED_SW    PORT1.DR.BIT.B4   // PIN NO. 43
#define LED_1R    PORT1.DR.BIT.B3   // PIN NO. 44
#define LED_1G    PORT1.DR.BIT.B2   // PIN NO. 45
#define LED_2R    PORT1.DR.BIT.B1   // PIN NO. 46
#define LED_2G    PORT1.DR.BIT.B0   // PIN NO. 47
#define LED_FM    PORT3.DR.BIT.B7   // PIN NO. 48
#define LED_TM    PORT3.DR.BIT.B6   // PIN NO. 49
#define LED_3G    PORT3.DR.BIT.B5   // PIN NO. 50
#define LED_4G    PORT8.DR.BIT.B4   // PIN NO. 51
#define LED_5G    PORT5.DR.BIT.B6   // PIN NO. 53
#define LED_W     PORT5.DR.BIT.B5   // PIN NO. 54
#define LED_AM    PORT5.DR.BIT.B4   // PIN NO. 55

//NOR FLASH RESET
#define RES6    PORT8.DR.BIT.B3   // PIN NO. 56
#define RES5    PORT8.DR.BIT.B2   // PIN NO. 58
#define RES4    PORT8.DR.BIT.B1   // PIN NO. 60
#define RES3    PORT8.DR.BIT.B0   // PIN NO. 61
#define RES2    PORT5.DR.BIT.B1   // PIN NO. 64
#define RES1    PORT7.DR.BIT.B7   // PIN NO. 66
//NOR FLASH ADDRESS
#define A25    PORT7.DR.BIT.B2   // PIN NO. 88
#define A24    PORT7.DR.BIT.B6   // PIN NO. 67
#define A23    PORT7.DR.BIT.B5   // PIN NO. 68
#define A22    PORTC.DR.BIT.B7   // PIN NO. 69
#define A21    PORTC.DR.BIT.B6   // PIN NO. 70
#define A20    PORTC.DR.BIT.B5   // PIN NO. 71
#define A19    PORTC.DR.BIT.B4   // PIN NO. 72
#define A18    PORTC.DR.BIT.B3   // PIN NO. 73
#define A17    PORTC.DR.BIT.B2   // PIN NO. 75
#define A16    PORTC.DR.BIT.B1   // PIN NO. 77
#define A15    PORTC.DR.BIT.B0   // PIN NO. 78
#define A14    PORTB.DR.BIT.B7   // PIN NO. 79
#define A13    PORTB.DR.BIT.B6   // PIN NO. 80
#define A12    PORTB.DR.BIT.B5   // PIN NO. 81
#define A11    PORTB.DR.BIT.B4   // PIN NO. 82
#define A10    PORTB.DR.BIT.B3   // PIN NO. 83
#define A9    PORTB.DR.BIT.B2   // PIN NO. 84
#define A8    PORTB.DR.BIT.B1   // PIN NO. 85
#define A7    PORTB.DR.BIT.B0   // PIN NO. 92
#define A6    PORTA.DR.BIT.B7   // PIN NO. 94
#define A5    PORTA.DR.BIT.B6   // PIN NO. 95
#define A4    PORTA.DR.BIT.B5   // PIN NO. 96
#define A3    PORTA.DR.BIT.B4   // PIN NO. 97
#define A2    PORTA.DR.BIT.B3   // PIN NO. 98
#define A1    PORTA.DR.BIT.B2   // PIN NO. 99
#define A0    PORTA.DR.BIT.B1   // PIN NO. 100
#define A_1    PORTA.DR.BIT.B0   // PIN NO. 101

#define		NOR_A25 	2
#define		NOR_A24 	1
#define		NOR_A23 	0

//NOR FLASH DATA
#define Q15    PORTE.PORT.BIT.B7   // PIN NO. 102
#define Q14    PORTE.PORT.BIT.B6   // PIN NO. 103
#define Q13    PORTE.PORT.BIT.B5   // PIN NO. 104
#define Q12    PORTE.PORT.BIT.B4   // PIN NO. 105
#define Q11    PORTE.PORT.BIT.B3   // PIN NO. 106
#define Q10    PORTE.PORT.BIT.B2   // PIN NO. 107
#define Q9    PORTE.PORT.BIT.B1   // PIN NO. 108
#define Q8    PORTE.PORT.BIT.B0   // PIN NO. 109
#define Q7    PORTD.PORT.BIT.B7   // PIN NO. 110
#define Q6    PORTD.PORT.BIT.B6   // PIN NO. 111
#define Q5    PORTD.PORT.BIT.B5   // PIN NO. 112
#define Q4    PORTD.PORT.BIT.B4   // PIN NO. 113
#define Q3    PORTD.PORT.BIT.B3   // PIN NO. 119
#define Q2    PORTD.PORT.BIT.B2   // PIN NO. 120
#define Q1    PORTD.PORT.BIT.B1   // PIN NO. 121
#define Q0    PORTD.PORT.BIT.B0   // PIN NO. 122
//NOR FLASH CHIP SELECT
//#define CS6    PORT7.DR.BIT.B1   // PIN NO. 89
//#define CS4    PORT6.PORT.BIT.B4   // PIN NO. 114
//#define CS3    PORT6.PORT.BIT.B3   // PIN NO. 115
//#define CS2    PORT6.PORT.BIT.B2   // PIN NO. 116
//#define CS1    PORT6.PORT.BIT.B1   // PIN NO. 117
//#define CS5    PORT6.PORT.BIT.B0   // PIN NO. 118
//NOR FLASH POWER
#define VC33ME_ENA    PORT9.DR.BIT.B0   // PIN NO. 131

// NOR CONTROL BUS
#define CS1     PORT6.DDR.BIT.B1    // PIN NO. 117

//NAND FLASH(CN103)
#define C_RY_BY    PORT9.DR.BIT.B7   // PIN NO. 123
#define C_CE    PORT9.DR.BIT.B6   // PIN NO. 124
#define C_ALE    PORT9.DR.BIT.B5   // PIN NO. 125
#define C_WP    PORT9.DR.BIT.B4   // PIN NO. 126
#define C_RE    PORT9.DR.BIT.B3   // PIN NO. 127
#define C_CLE    PORT9.DR.BIT.B2   // PIN NO. 128
#define C_WE    PORT9.DR.BIT.B1   // PIN NO. 129
#define C_I_O8_O    PORT4.DR.BIT.B7   // PIN NO. 133    -     
#define C_I_O8_I    PORT4.PORT.BIT.B7   // PIN NO. 133
#define C_I_O7_O    PORT4.DR.BIT.B6   // PIN NO. 134    -     
#define C_I_O7_I    PORT4.PORT.BIT.B6   // PIN NO. 134
#define C_I_O6_O    PORT4.DR.BIT.B5   // PIN NO. 135    -     
#define C_I_O6_I    PORT4.PORT.BIT.B5   // PIN NO. 135
#define C_I_O5_O    PORT4.DR.BIT.B4   // PIN NO. 136    -     
#define C_I_O5_I    PORT4.PORT.BIT.B4   // PIN NO. 136
#define C_I_O4_O    PORT4.DR.BIT.B3   // PIN NO. 137    -     
#define C_I_O4_I    PORT4.PORT.BIT.B3   // PIN NO. 137
#define C_I_O3_O    PORT4.DR.BIT.B2   // PIN NO. 138    -     
#define C_I_O3_I    PORT4.PORT.BIT.B2   // PIN NO. 138
#define C_I_O2_O    PORT4.DR.BIT.B1   // PIN NO. 139    -     
#define C_I_O2_I    PORT4.PORT.BIT.B1   // PIN NO. 139
#define C_I_O1_O    PORT4.DR.BIT.B0   // PIN NO. 141    -     
#define C_I_O1_I    PORT4.PORT.BIT.B0   // PIN NO. 141

//RES
#define TP086    PORT7.DR.BIT.B4   // PIN NO. 86
#define TP087    PORT7.DR.BIT.B3   // PIN NO. 87
#define TP090    PORT7.DR.BIT.B0   // PIN NO. 90
#define TP062    PORT5.PORT.BIT.B3   // PIN NO. 62
#define TP007    PORT0.DR.BIT.B1   // PIN NO. 7
#define TP008    PORT0.DR.BIT.B0   // PIN NO. 8

/*** 7 segment LED module ***/
#if 1
#define 	SCL_LED 	PORT1.DR.BIT.B7   // PIN NO. 38
#define 	SCL_LED_D 	PORT1.DDR.BIT.B7   // PIN NO. 38
#define 	SDA_LED 	PORT1.DR.BIT.B6   // PIN NO. 40
#define 	SDA_LED_I 	PORT1.PORT.BIT.B6   // PIN NO. 40
#define		SDA_LED_D	PORT1.DDR.BIT.B6   // PIN NO. 40
#define		LED7SEG_1	0x01
#define		LED7SEG_2	0x02
#define		LED7SEG_3	0x04
#define		LED7SEG_4	0x08

#endif

/*** LED7 pin assignment ***/
#if 1
#define	LED72_A		led7Out.P2.BIT.B0
#define	LED72_B		led7Out.P2.BIT.B1
#define	LED72_C		led7Out.P2.BIT.B2
#define	LED72_D		led7Out.P2.BIT.B3
#define	LED72_E		led7Out.P2.BIT.B4
#define	LED72_F		led7Out.P2.BIT.B5
#define	LED72_G		led7Out.P2.BIT.B6
#define	LED72_DP	led7Out.P2.BIT.B7

#define	LED71_A		led7Out.P1.BIT.B0
#define	LED71_B		led7Out.P1.BIT.B1
#define	LED71_C		led7Out.P1.BIT.B2
#define	LED71_D		led7Out.P1.BIT.B3
#define	LED71_E		led7Out.P1.BIT.B4
#define	LED71_F		led7Out.P1.BIT.B5
#define	LED71_G		led7Out.P1.BIT.B6
#define	LED71_DP	led7Out.P1.BIT.B7

#define	LED74_A		led7Out.P4.BIT.B0
#define	LED74_B		led7Out.P4.BIT.B1
#define	LED74_C		led7Out.P4.BIT.B2
#define	LED74_D		led7Out.P4.BIT.B3
#define	LED74_E		led7Out.P4.BIT.B4
#define	LED74_F		led7Out.P4.BIT.B5
#define	LED74_G		led7Out.P4.BIT.B6
#define	LED74_DP	led7Out.P4.BIT.B7

#define	LED73_A		led7Out.P3.BIT.B0
#define	LED73_B		led7Out.P3.BIT.B1
#define	LED73_C		led7Out.P3.BIT.B2
#define	LED73_D		led7Out.P3.BIT.B3
#define	LED73_E		led7Out.P3.BIT.B4
#define	LED73_F		led7Out.P3.BIT.B5
#define	LED73_G		led7Out.P3.BIT.B6
#define	LED73_DP	led7Out.P3.BIT.B7

#endif
















