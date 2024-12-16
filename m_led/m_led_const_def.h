/***********************************************************************/
/*                                                                     */
/*  FILE        :m_led_const_def.h              					   */
/*  DATE        :Thu, Feb 2, 2017                                      */
/*  DESCRIPTION :Constant variable definition                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#ifndef _M_LED_CONST_DEF_H
#define _M_LED_CONST_DEF_H
#endif

#ifdef _M_LED_CONST_DEF_H
/*** LED constant variables definition ***/
#define		L_LED_1R		(0)
#define		L_LED_1G		(1)
#define		L_LED_2R		(2)
#define		L_LED_2G		(3)
#define		L_LED_3G		(4)
#define		L_LED_4G		(5)
#define		L_LED_5G		(6)
#define		L_LED_W			(7)
#define		L_LED_SW		(8)
#define		L_LED_TM		(9)
#define		L_LED_FM		(10)
#define		L_LED_AM		(11)

/*** 7 Segment LED **************************************************/
/*** LED7 index ***/
#define L_LED7_1	(0)
#define L_LED7_2	(1)
#define L_LED7_3	(2)
#define L_LED7_4	(3)

/*** LED7 segment index ***/
#define	LED_A		(0)	
#define	LED_B		(1)
#define	LED_C		(2)
#define	LED_D		(3)
#define	LED_E		(4)
#define	LED_F		(5)
#define	LED_G		(6)
#define	LED_DP		(7)

/*** address i2c two devices TCA6416ARTWR ***/
#define I2C_ADDR_TCA6416AR_L	0x40
#define	I2C_ADDR_TCA6416AR_H	0x42

/*** Command Byte Output Port 0 or Output Port 1 TCA6416ARTWR ***/
#define TCA6416A_INPUT_BANK_0 		0x00
#define TCA6416A_INPUT_BANK_1 		0x01
#define TCA6416A_OUTPUT_BANK_0 		0x02
#define TCA6416A_OUTPUT_BANK_1 		0x03
#define TCA6416A_POLARITY_BANK_0 	0x04
#define TCA6416A_POLARITY_BANK_1 	0x05
#define TCA6416A_CONFIG_BANK_0 		0x06
#define TCA6416A_CONFIG_BANK_1 		0x07

#define	SCL_HIGH	5//3//25
#define	SCL_LOW		5//3//22
#define	SCL_HIGH1	7//4//35
#define	SCL_LOW1	7//4//30
#define	SCL_HIGH2	8//6//50	
#define	SCL_LOW2	8//6//45
#define	SCL_HOLD	2//1//5

/*** Set Led7 Segment Display Mode ******************************************************/
// LED7 display
#define LED7_DSP_OFF					0x00
#define LED7_DSP_FM						0x01
#define LED7_DSP_AM						0x02
#define LED7_DSP_TM						0x03
#define	LED7_SQL_OPEN					0x04
#define	LED7_BER_MODE					0x05
#define	LED7_CH_DSP						0x06
#define	LED7_CPU_VER_DSP				0x07
#define	LED7_DSP_VER_DSP				0x08
#define	LED7_RF_LEVEL_DSP				0x09
#define	LED7_VOL_LEVEL_DSP				0x0A
#define	LED7_AIR_RX_DSP					0x0B
#define	LED7_AIR_MONI_DSP				0x0C
#define	LED7_DIP_SW_DSP					0x0D
#define	LED7_AF_WRITE_DSP				0x0E
#define	LED7_JIG_MODE_DSP				0x0F
#define	LED7_DACS2_DSP					0x10
#define	LED7_SCAN_MODE_DSP				0x11
#define	LED7_WAIT_DSP					0x12
#define	LED7_JIG_END_DSP				0x13
#define	LED7_PROGRAM_NEW_ONGEN			0x14
#define	LED7_ERASE_NAND_ONGEN			0x15
#define	LED7_VERIFY_NOR_NAND_ONGEN		0x16
#define	LED7_OPTION_SET_WRITE_PART_NO	0x17
#define	LED7_OPTION_PLAY_NOR_PART_NO	0x18
#define	LED7_OPTION_PLAY_NAND_PART_NO	0x19
#define	LED7_OPTION_AUTO_MODE			0x1A
#define	LED7_OPTION_PLAY_NOR_PART_SET	0x1B

/*** 7 segment LED character ******************************************************/
#define		LED7_0		0x00
#define		LED7_1		0x01
#define		LED7_2		0x02
#define		LED7_3		0x03
#define		LED7_4		0x04
#define		LED7_5		0x05
#define		LED7_6		0x06
#define		LED7_7		0x07
#define		LED7_8		0x08
#define		LED7_9		0x09
#define		LED7_A		0x0A
#define		LED7_B		0x0B
#define		LED7_C		0x0C
#define		LED7_D		0x0D
#define		LED7_E		0x0E
#define		LED7_F		0x0F
#define		LED7_H		0x10
#define		LED7_I		0x11
#define		LED7_L		0x12
#define		LED7_N		0x13
#define		LED7_O		0x14
#define		LED7_P		0x15
#define		LED7_R		0x16
#define		LED7_S		0x17
#define		LED7_T		0x18
#define		LED7_U		0x19
#define		LED7_BAR	0x1A
#define		LED7_EQUAL	0x1B
#define		LED7_SP		0x1C
#define		LED7_DP		0x1D
#define		LED7_3BAR	0x1E
#define		LED7_LBAR	0x1F
#define		LED7_UBAR	0x20
#define		LED7_H2		0x21
#define		LED7_u		0x22
#define		LED7_o		0x23
#define		LED7_d		0x24

#endif



















