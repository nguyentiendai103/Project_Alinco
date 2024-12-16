/***********************************************************************/
/*                                                                     */
/*  FILE        :m_nor_const_def.h              					   */
/*  DATE        :Thu, Feb 2, 2017                                      */
/*  DESCRIPTION :Constant variable definition                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#ifndef _M_NOR_CONST_DEF_H
#define _M_NOR_CONST_DEF_H
#endif

#ifdef _M_NOR_CONST_DEF_H
/*** Information NOR FLASH ***/
#define NOR_MAX_WORD_LEN		(512)
#define NOR_NUM_BLOCK 			(1024)
#define NOR_BLOCK_MAX 			(NOR_NUM_BLOCK - 1)
#define NOR_BLOCK_SIZE_WORD		(64 * 1024)
#define NOR_MAX_SIZE_WORD		(NOR_NUM_BLOCK * NOR_BLOCK_SIZE_WORD)
#define NOR_NUM_CHIP			(6)
#define NOR_NUM_CHIP_MAX		(NOR_NUM_CHIP - 1)
#define NOR_PAGE_SIZE   		(32)


/*** Entire chip erase timeout  of 1Gb ***/
#define  FULL_1GB_CHIP_ERASE_2096S  (2096)

/*** NOR flash chip address (CS) ***/
#define CS1_POS  (unsigned short *)0x07000000
#define CS2_POS  (unsigned short *)0x06000000
#define CS3_POS  (unsigned short *)0x05000000
#define CS4_POS  (unsigned short *)0x04000000
#define CS5_POS  (unsigned short *)0x03000000
#define CS6_POS  (unsigned short *)0x02000000

#define NOR_A23_MASK	(0x03000000)
#define NOR_A25_MASK	(0x02000000)
#define NOR_A24_MASK	(0x01000000)

/*** Macro for address conversion ***/
#define BLOCK_TO_ADDR(x)	(x << 16)
#define ADDR_TO_BLOCK(x)	((x & 0xFFFF0000) >> 16)

/*** NOR Flash commands ***/
#define NOR_CMD_HEADER_1ST		(0x055500AA)
#define NOR_CMD_HEADER_2ND		(0x02AA0055)
#define NOR_CMD_RESET_3RD		(0x000000F0)

#define	NOR_CMD_WORD_PRG_3RD	(0x055500A0)
#define	NOR_CMD_PAGE_PRG_3RD	(0x00000025)



#define NOR_CMD_READ            (0x000000F0)

#define	NOR_CMD_CHIP_ERASE_3RD	(0x05550080)
#define	NOR_CMD_CHIP_ERASE_4TH	(0x055500AA)
#define	NOR_CMD_CHIP_ERASE_5TH	(0x02AA0055)
#define	NOR_CMD_CHIP_ERASE_6TH	(0x05550010)

#define NOR_CMD_BLOCK_ERASE_1ST (0x055500AA)
#define NOR_CMD_BLOCK_ERASE_2ND (0X02AA0055)
#define	NOR_CMD_BLOCK_ERASE_3RD	(0x05550080)
#define	NOR_CMD_BLOCK_ERASE_4TH	(0x055500AA)
#define	NOR_CMD_BLOCK_ERASE_5TH	(0x02AA0055)
#define	NOR_CMD_BLOCK_ERASE_6TH	(0x007F0030)

#define	NOR_CMD_BLANK_CHECK_3RD	(0x000000EB)
#define	NOR_CMD_BLANK_CHECK_4TH	(0x00000076)
#define	NOR_CMD_BLANK_CHECK_5TH	(0x00000000)
#define	NOR_CMD_BLANK_CHECK_6TH	(0x00000000)
#define	NOR_CMD_BLANK_CHECK_7TH	(0x00000029)

#define NOR_CMD_AUTO_SELECT_3RD	(0x05550090)
#define NOR_CMD_EXIT_AUTO_SEL	(0x000000F0)

/*** NOR Flash Electronic Signature ***/
#define NOR_MANUFACTURER_CODE	(0x0089)
#define NOR_DEVICE_CODE1		(0x227E)
#define NOR_DEVICE_CODE2		(0x2228)
#define NOR_DEVICE_CODE3		(0x2201)

/*** NOR Flash Protected Cmd ***/
#define NOR_CMD_PROTECTED       (0x0001)
#define NOR_CMD_UNPROTECTED     (0x0000)
#define NOR_CMD_CLEAR_ALL_1ST       (0x00000080)
#define NOR_CMD_CLEAR_ALL_2ND       (0x00000030)
#define NOR_CMD_ENTER_NON_PRO_1ST      (0x055500AA)
#define NOR_CMD_ENTER_NON_PRO_2ND     (0x02AA0055)
#define NOR_CMD_ENTER_NON_PRO_3RD      (0x055500C0)
#define NOR_CMD_EXIT_NON_PRO_1ST      (0x00000090)
#define NOR_CMD_EXIT_NON_PRO_2ND      (0x00000000)
#define NOR_CMD_PRO_NON_PRO_1ST      (0x000000A0)
#define NOR_CMD_PRO_NON_PRO_2ND      (0x00000000)

/*** NOR Flash Resume Cmd ***/
#define NOR_CMD_PRG_RESUME_1ST      (0x00000030)


/*** NOR Flash TIMEOUT Cmd ***/
#define TM_S   0 
#define TM_MS   1
#define TM_US   2

#define COUNT_FOR_A_SECOND      100
#define  COUNT_FOR_A_MSECOND    1
#define  COUNT_FOR_A_MICROSECOND    10


#define OK 1
#define NG 0


/*** NOR Flash Status Return ***/
#define NOR_FLASH_UNPROTECTED  0
#define NOR_FLASH_PROTECTED  1
#define NOR_FLASH_PROTECTEDUNCLEAR  2
#endif



















