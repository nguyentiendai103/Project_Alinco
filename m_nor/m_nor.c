

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
/*  FILE        :m_nor.c		                                       */
/*  DATE        :Tue, Oct 31, 2006                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#include "include.h"
/****************************************************************************/
/* 		setNor																*/
#if 1
// Set NOR Flash
void setNor()
{
	unsigned char count;
	unsigned char dmy;
	unsigned char i;
	
	if(norMode == 0){
		count = 0;
		for(i=0;i<sizeof(norCode)/sizeof(norCode[0]);i++){
			dmy = readNorDeviceId(i);
			if(dmy){
				count++;
			}
		}
		// setNorAddrA25A24A23(0x07000000);
		norMode = 1;
	} else if(norMode == 1){
		
		
		
		
	
		
		dmy = eraseNorBlock(0,12);
		
		readWord(0, 0x000C0000);
		//readNor (3,0x01FF0000,data1,32);
		
		 //
		//chkTimeOut(2,TM_US);
 		// readNor (1,0x07F0000,data1,32);
		// checkBlockProtection(1,127);
		//readNor (0,0x00000000,data1,32);

		// blankCheck(0,5);
		// checkBlockProtection(1,0);


	}
	
	
}


#endif
/* 		End of setNor														*/
/****************************************************************************/


/****************************************************************************/
/* 		readNor, writeNor, etc.												*/
#if 1
// Read data from Nor flash

unsigned char readNor(unsigned char chipNo, unsigned long sAddr, unsigned short* dPos, unsigned short length)
{	
#if 0
	unsigned short	 data;
	unsigned short    blockNo;
	unsigned long    blockStartAddr;
	unsigned long    addr;
	
	unsigned short*  pos;
	unsigned char    i;	
	unsigned char    flg;	

	
	flg = OK;
	blockNo = ADDR_TO_BLOCK(sAddr);
	/* Step 1: Check that the block number exists */
	if(blockNo > NOR_BLOCK_MAX){
		flg = NG;
	}
	if(chipNo > NOR_NUM_CHIP_MAX){
		flg = NG;
	}

 	sendNorCmd(chipNo, NOR_CMD_READ);
	
	setNorAddrA25A24A23(0x00000000);		// Reset A25 and A24
	
	// data = (char)(sAddr >> 16) & 0xFF;
	// sendNorData(chipNo, sAddr,data);
	// data = (char)(sAddr >> 8) & 0xFF;
	// sendNorData(chipNo, sAddr,data);
	// data = (char)(sAddr & 0xFF);
	// sendNorData(chipNo, sAddr,data);
	addr = sAddr & 0x7FFFFF;

  	

	for(i=0;i<length;i++){
		
		data1[i] = *(dPos + addr);
	
	}
	// for(i=0;i<length;i++){
	// 	*(dPos + i) = data1[i];
	// }

	// return 1;
	return data;
#endif 0

	unsigned short blockNo;
	unsigned short data;
	unsigned char flg;
	unsigned char i;
	unsigned long addr;

	flg = OK;
	blockNo = ADDR_TO_BLOCK(sAddr);
	/* Step 1: Check that the block number exists */
	if(blockNo > NOR_BLOCK_MAX){
		flg = NG;
	}
	if(chipNo > NOR_NUM_CHIP_MAX){
		flg = NG;
	}

	/* Step 2: Send the read page command */
	if(flg){
		// send  cmd  read page
		sendNorCmd(chipNo, NOR_CMD_READ);
		// Reset A25 and A24
		nop();
		setNorAddrA25A24A23(0x00000000);
		nop();
		// addr = SAddr;
		for(i=0;i< length;i++){
			data1[i] = readWord(chipNo,sAddr);
			sAddr++;
		}
		for(i=0;i<length;i++){
			*(dPos + i) = data1[i];
		}

	}

	return 1;

}


unsigned char readPage(unsigned char chipNo, unsigned long sAddr,unsigned short* dPos,unsigned short length)
{
	unsigned long blockNo;
	unsigned short data;
	unsigned char flg;
	unsigned char i;
	unsigned long addr;

	flg = OK;
	blockNo = ADDR_TO_BLOCK(sAddr);
	/* Step 1: Check that the block number exists */
	if(blockNo > NOR_BLOCK_MAX){
		flg = NG;
	}
	if(chipNo > NOR_NUM_CHIP_MAX){
		flg = NG;
	}

	/* Step 2: Send the read page command */
	if(flg){
		sendNorCmd(chipNo, NOR_CMD_READ);
		// Reset A25 and A24
		nop();
		setNorAddrA25A24A23(0x00000000);
		nop();
		// addr = SAddr;
		for(i=0;i< length;i++){
			data1[i] = readNorWord(chipNo,sAddr);
			sAddr++;
		}
		for(i=0;i<length;i++){
			*(dPos + i) = data1[i];
		}

	}

	return 1;
}

// Write data to Nor flash
unsigned char writeNor(unsigned char chipNo, unsigned long dAddr, unsigned short* sPos, unsigned short length)
{	
	 unsigned long blockAddr;
	unsigned short blockNo;
	unsigned short data;
	unsigned long  addr;
	unsigned short i;
	 unsigned char flg;

	flg = OK;
    blockAddr = BLOCK_TO_ADDR(blockNo);

    // Step 1: Check for block and chip number
    if (blockNo > NOR_BLOCK_MAX || chipNo > NOR_NUM_CHIP_MAX) {
        flg = NG;
    }
	/* Step 2: Check if the block is protected */
	if(checkBlockProtection(chipNo,blockNo) == NOR_FLASH_PROTECTED){
		return NOR_FLASH_PROTECTED;
	}

	sendNorCmd(chipNo, NOR_CMD_HEADER_1ST);
    sendNorCmd(chipNo, NOR_CMD_HEADER_2ND);

	pos = blockAddr &  0xFFFFF000;
	dmy = pos + 0x0025;
	
    sendNorCmd(chipNo, pos);
	
	// blockAddr = blockAddr & 0x007FFFFF;


	// sendNorCmd(chipNo, NOR_CMD_PAGE_PRG_3RD);

	setNorAddrA25A24A23(0x00000000);		// Reset A25 and A24

	blockNo = ADDR_TO_BLOCK(dAddr);
	setNorAddrA25A24A23(blockNo);
	
	// eraseNorBlock(chipNo,blockNo);
	
	sendNorCmd(chipNo, NOR_CMD_PAGE_PRG_3RD);
	data = (char)(dAddr >> 16) & 0xFF;
	sendNorData(chipNo, dAddr,data);
	data = (char)(dAddr >> 8) & 0xFF;
	sendNorData(chipNo, dAddr,data);
	data = (char)(dAddr & 0xFF);
	sendNorData(chipNo, dAddr,data);

	// 	data = 0xaa00;
	// 	sPos = data;
	// sendNorData(chipNo,dAddr,sPos);

	for(i=0;i<length;i++){
		data = *(sPos + i);
		// addr = dAddr + (i * NOR_PAGE_SIZE);
		sendNorData(chipNo,dAddr,data);
	}
	
	
	return 1;
}

// Erase block of Nor flash
unsigned char eraseNorBlock(unsigned char chipNo, unsigned short blockNo)
{	
    unsigned long blockStartAddr;
    unsigned long blockAddr;
    unsigned long   dmy;
    unsigned long temp;
    unsigned char flg;
    unsigned short data;
    unsigned long pos;
    unsigned char i;
  
	flg = OK;
    blockAddr = BLOCK_TO_ADDR(blockNo);

    // Step 1: Check for block and chip number
    if (blockNo > NOR_BLOCK_MAX || chipNo > NOR_NUM_CHIP_MAX) {
        flg = NG;
    }
	/* Step 2: Check if the block is protected */
	if(checkBlockProtection(chipNo,blockNo) == NOR_FLASH_PROTECTED)
		return NOR_FLASH_PROTECTED;
	/* Step 3: Write Block Erase command */
    if (flg) {
		sendNorCmd(chipNo, NOR_CMD_HEADER_1ST);
        sendNorCmd(chipNo, NOR_CMD_HEADER_2ND);
        sendNorCmd(chipNo, NOR_CMD_BLOCK_ERASE_3RD);
        sendNorCmd(chipNo, NOR_CMD_BLOCK_ERASE_4TH);
        sendNorCmd(chipNo, NOR_CMD_BLOCK_ERASE_5TH);
	
	pos = blockAddr &  0xFFFFF000;
	dmy = pos + 0x0030;
	
        sendNorCmd(chipNo, pos);
	
	blockAddr = blockAddr & 0x007FFFFF;
	
	/* Step 4: Wait for the Erase Timer Bit (DQ3) to be set */
        chktimeout(0, TM_US);/* Initialize TimeOut Counter */
        while (!(readWord(chipNo, blockAddr) & 0x0008 )) {
            if (chktimeout(200, TM_US) == NG) {
                reset(chipNo);
                flg = NG;
                break;
            }
        }
        chktimeout_off();
	/* Step 5: Follow Bit Toggle Flow Chart until Program/Erase Controller completes */
        if (flg) {
            if (norBitTogle(chipNo, 2, TM_S) == NG) {
                reset(chipNo);
                flg = NG;
            }
        }
    }

    // data = readWord(chipNo, blockAddr); // check lại xem đã xóa được chưa bằng cách gán data
	return flg;

}

// Erase chip
unsigned char eraseNorChip(unsigned char chipNo)
{	
	unsigned char flg;
	unsigned char i;

	flg = 1;
	
	if(chipNo > NOR_NUM_CHIP_MAX){
        flg = 0;
    }

	if (flg){
		sendNorCmd(chipNo, NOR_CMD_HEADER_1ST);
		sendNorCmd(chipNo, NOR_CMD_HEADER_2ND);
		sendNorCmd(chipNo, NOR_CMD_CHIP_ERASE_3RD);
		sendNorCmd(chipNo, NOR_CMD_CHIP_ERASE_4TH);
		sendNorCmd(chipNo, NOR_CMD_CHIP_ERASE_5TH);
		sendNorCmd(chipNo, NOR_CMD_CHIP_ERASE_6TH);

	}
	return 1;
}

// Read device ID of Nor flash
unsigned char readNorDeviceId(unsigned char chipNo)
{
	unsigned short sBuff[4];
	unsigned short* pos;
	unsigned char flg;
	unsigned char i;
	
	// Send auto select command to put NOR flash into AUTO SELECT MODE
	sendNorCmd(chipNo, NOR_CMD_HEADER_1ST);
	sendNorCmd(chipNo, NOR_CMD_HEADER_2ND);
	sendNorCmd(chipNo, NOR_CMD_AUTO_SELECT_3RD);
	
	// Read manuafacturer code
	setNorAddrA25A24A23(0x00000000);		// Reset A25 and A24
	sBuff[0] = readNorWord(chipNo, 0x00000000);
	sBuff[1] = readNorWord(chipNo, 0x00000001);
	sBuff[2] = readNorWord(chipNo, 0x0000000E);
	sBuff[3] = readNorWord(chipNo, 0x0000000F);
	
	flg = 1;
	if(sBuff[0] ^ NOR_MANUFACTURER_CODE){
		flg = 0;
	}
	if(sBuff[1] ^ NOR_DEVICE_CODE1){
		flg = 0;
	}
	if(sBuff[2] ^ NOR_DEVICE_CODE2){
		flg = 0;
	}
	if(sBuff[3] ^ NOR_DEVICE_CODE3){
		flg = 0;
	}
	
	if(flg){
		pos = &norCode[chipNo].manufacturerCode;
		for(i=0;i<sizeof(sBuff)/sizeof(sBuff[0]);i++){
			*(pos + i) = sBuff[i];
		}
	}
	
	// Exit from auto select mode
	sendNorCmd(chipNo, NOR_CMD_EXIT_AUTO_SEL);
	
	return flg;

	
}

// blank check
unsigned char blankCheck(unsigned char chipNo, unsigned short blockNo)
{
	unsigned long blockStartAddr;
	unsigned long blockAddr;
	unsigned short data;
	unsigned long dmy;
	unsigned char flg;

	setNorAddrA25A24A23(0x00000000);		// Reset A25 and A24
	blockAddr = (unsigned long*)norCsAddrTbl[chipNo];
	blockStartAddr = BLOCK_TO_ADDR(blockNo);
	blockStartAddr = blockAddr + blockStartAddr;

	sendNorCmd(chipNo,NOR_CMD_BLANK_CHECK_3RD);
	sendNorCmd(chipNo,NOR_CMD_BLANK_CHECK_4TH);
	sendNorCmd(chipNo,NOR_CMD_BLANK_CHECK_5TH);
	sendNorCmd(chipNo,NOR_CMD_BLANK_CHECK_6TH);
	sendNorCmd(chipNo,NOR_CMD_BLANK_CHECK_7TH);
	
	data = readNorWord(chipNo,blockStartAddr);
	if(data == 0xFFFF){
		return 	1;
	}else{
		return 0;
	}

}
#endif
/* 		End of readNor, writeNor, etc.										*/
/****************************************************************************/


/****************************************************************************/
/* 		setNorAddr, sendNorCmd, etc.										*/

// Set Nor Flash Address
void setNorAddrA25A24A23(unsigned long addr)
{
	// A25
	if(addr & NOR_A25_MASK){
		A25 = 1;
	} else {
		A25 = 0;
	}
	
	// A24
	if(addr & NOR_A24_MASK){
		A24 = 1;
	} else {
		A24 = 0;
	}

	//A23
	if(addr & NOR_A23_MASK){
		A23 = 1;
	} else {
		A23 = 0;
	}
}

// Send Nor Flash Command
void sendNorCmd(unsigned char chipNo, unsigned long cmd)
{
	unsigned short* pos;
	unsigned short cmdAddr;
	unsigned short cmdData;
	
	cmdAddr = (unsigned short)((cmd & 0xFFFF0000) >> 16);
	cmdData = (unsigned short)(cmd & 0x0000FFFF);
	
	// Get address from chip number
	pos = (unsigned short*)norCsAddrTbl[chipNo];
	pos += cmdAddr;
	
 	setNorAddrA25A24A23(0x00000000);		// Reset A25 and A24

	*pos = cmdData;

#if 1
	// unsigned short* pos;
    // unsigned short cmdAddr;
    // unsigned short cmdData;
	
	// unsigned short temp;

	// temp = (unsigned short)((cmd & 0xFFFF0000) >> 16);
	
	
	// if ((temp  & 0x03FF) < 0x0400 ){
	// 	nop();
	// }
	
    // if ((temp <= 0xFFFF) ) {
    //     cmdAddr = (unsigned short)((cmd >> 16) & 0x0000FFFF);
    //     cmdData = (unsigned short)(cmd & 0x0000FFFF);
    // } else if ((temp  & 0x03FF) < 0x0400 ) {
    //     cmdAddr = (unsigned short)((cmd & 0xFFFF0000) >> 16);
    //     cmdData = (unsigned short)(cmd & 0x0000FFFF);
    // }
    
    // // Get address from chip number
    // pos = (unsigned short*)norCsAddrTbl[chipNo];
    // pos += cmdAddr;
    
    // setNorAddrA25A24A23(0x00000000);  // Set A25 and A24 (cmd >> 24) & 0x00000003
    
    // *pos = cmdData;
#endif 1
}


// Send Nor Flash Command
void sendAddrCmd(unsigned char chipNo, unsigned long cmdAddr)
{
	unsigned short* pos;
	unsigned short addr;
	unsigned short cmdData;

	cmdData = (unsigned short)(cmdAddr & 0x0000FFFF);
	addr = (unsigned short)((cmdAddr & 0xFFFF0000) >> 16);
	pos = (unsigned short*)norCsAddrTbl[chipNo];
	pos += (addr << 15 );

	setNorAddrA25A24A23(0x00000000);		// Reset A25 and A24

	*pos = cmdData;

}

// Send data to a specific address
void sendNorData(unsigned char chipNo, unsigned long destAddr, unsigned short data)
{
	unsigned short* pos;
	unsigned long addr;
	
	// Get address from chip number
	addr = destAddr & 0x00FFFFFF;
	addr += (unsigned long)norCsAddrTbl[chipNo];
	pos = (unsigned short*)addr;
	
	setNorAddrA25A24A23(destAddr);		// Set A25 and A24
	*pos = data;
}

// Read 1 word from NOR flash
unsigned short readNorWord(unsigned char chipNo, unsigned long sourceAddr)
{	

	unsigned short* pos;
	unsigned short  addr;
	unsigned short  data;
	unsigned short temp;

	
	
	// Get address from chip number

	// addr = sourceAddr & 0x00FFFFFF;
	// addr += (unsigned long)norCsAddrTbl[chipNo];
	// pos = (unsigned short*)addr;
	
	// Get address from chip number
	pos = (unsigned short*)norCsAddrTbl[chipNo];
	addr = (sourceAddr & 0x00FFFFFF);
	pos += addr;
	
	
	setNorAddrA25A24A23(sourceAddr);		// Set A25 and A24
	data = *pos;
	
	return data;


	
 }

// Read 1 word from NOR flash
unsigned short readWord(unsigned char chipNo, unsigned long sourceAddr)
{
	unsigned short* pos;
	unsigned long addr;
	unsigned short data;

	// Get address from chip number
	// addr = sourceAddr & 0x00FFFFFF;
	// addr += (unsigned long)norCsAddrTbl[chipNo];
	// pos = (unsigned short*)addr;
	

	pos = (unsigned short*)norCsAddrTbl[chipNo];
	addr = (sourceAddr & 0x00FFFFFF) ;
	//pos += (sourceAddr >> 1);
	pos += addr;
	
	setNorAddrA25A24A23(sourceAddr);		// Set A25 and A24
	data = *pos;
	return data;

}

// Read 1 byte from NOR flash
unsigned char readNorByte(unsigned char chipNo, unsigned long sourceAddr)
{
	unsigned char* pos;
	unsigned long addr;
	unsigned char data;
	
	// Get address from chip number
	addr = sourceAddr & 0x00FFFFFF;
	addr += (unsigned long)norCsAddrTbl[chipNo];
	pos = (unsigned char*)addr;
	
	setNorAddrA25A24A23(sourceAddr);		// Set A25 and A24
	data = *pos;
	
	return data;
}



/* 		End of setNorAddr, sendNorCmd, etc.									*/
/****************************************************************************/
// Check timeout
unsigned char chktimeout(unsigned long timeout, unsigned char mode)
{	
   static unsigned long  counter ;
    unsigned long countPer ;
    // unsigned long  elapsedTime;
	unsigned char flg;
	// unsigned long dmy;

	countPer = 0;
	
	flg = OK;

	if(timeout == 0){
		counter = 0;
		flgTm = 1;
		return flg;
	}


	if (mode == TM_S){
		countPer = COUNT_FOR_A_SECOND;
	}else if(mode == TM_MS){
		countPer =  COUNT_FOR_A_MSECOND;
	}else if(mode == TM_US){
		countPer = COUNT_FOR_A_MICROSECOND;
	}else{
		countPer = COUNT_FOR_A_SECOND;
	}

	if(counter == ( timeout * countPer)){
		flg = NG;
	}else{
		counter++;
		flg = OK;
	}

#if 0	
	elapsedTime = 0;
	if(timeout == 0){
		startTime = CMT0.CMCNT;
		flgTm = 1;
		return flg;
	}
	dmy = CMT0.CMCNT;

	elapsedTime = dmy - startTime;    

    if (mode == TM_US){
        timeout = timeout * 100; // ms--> us
	}
	else if(mode == TM_S){
		timeout = timeout * 1000; // ms-> s
	}
	
	if (elapsedTime >= timeout){
		flg = 0 ;// Chưa vượt quá thời gian chờ
	}

#endif 0
    return  flg;

}

// Off calcultor check timeout
void chktimeout_off()
{
	flgTm = 0;
}
// Reset
void reset(unsigned char chipNo)
{
	unsigned char flg;
	unsigned char dmy;

	flg = OK;
	if(chipNo > NOR_NUM_CHIP_MAX){
        flg = 0;
    }

	
	sendNorCmd(chipNo,NOR_CMD_HEADER_1ST );
	sendNorCmd(chipNo,NOR_CMD_HEADER_2ND );
	sendNorCmd(chipNo,NOR_CMD_RESET_3RD );
	return OK;
	

	
}

// nor bit toggl
unsigned char   norBitTogle(unsigned char chipNo, unsigned long timeout, unsigned char mode)
{
	unsigned short dmy1,dmy2;
	unsigned char flg;
	unsigned char dmy;

	flg = OK;
	dmy1 = readNorWord(chipNo, 0x00000000);
	chktimeout(0,mode);
	dmy = OK;
	while(dmy = OK){
		dmy = chktimeout(timeout,mode);
		if(dmy = OK){
			dmy2 = readNorWord(chipNo, 0x00000000);
			if((dmy1 & 0x40) != (dmy2 & 0x40)){
				if(!(dmy2 & 0x20)){
					if(!(dmy2 & 0x01)){
						dmy1 = dmy2;
						continue;
					}
				}
				dmy1 = readNorWord(chipNo, 0x00000000);
				dmy2 = readNorWord(chipNo, 0x00000000);		
				if((dmy1 & 0x40) != (dmy2 & 0x40)){
					if(dmy2 & 0x20){
						//flg = 3;
						flg = NG;
					}else{
						//flg = 4;
						flg = NG;
					}
				}
				break;
			}else{
				break;
			}
		}else{//Timeout
            //flg = 2;
            flg = NG;
            break;
        }
	}
	chktimeout_off();
	return flg;
}




// // Check NOR flash status
// unsigned char checkNorStatus()
// {
// 	unsigned char flg;

// 	flg = 0;
// 	if(nor.busyFlg & 0x80){
// 		setNorResume();
// 	}
// 	else{
// 		if(norBusyTm == 0){
// 			readNorStatus();
// 			if(!(nor.status[0] & 0x01)){	// if BUSY bit in Status Register 1 = 0,
// 				nor.busyFlg = 0;			// then reset busy flag
// 				flg = 1;
// 			}
// 		}
// 		else{
// 			norBusyTm--;
// 		}
// 	}

// 	return flg;
// }

unsigned char setNorResume(unsigned char chipNo)
{
	sendNorCmd(chipNo, NOR_CMD_PRG_RESUME_1ST);
	return OK;
}

// set nor flash suspend
unsigned char setNorSuspend(unsigned char chipNo)
{

}
// void readNorStatus()
// {

// }

/****************************************************************************/
/*                   Protection Function Prototypes                         */
unsigned char checkBlockProtection(unsigned char chipNo ,unsigned short blockNo)
{
	unsigned char flg;
	unsigned char flgStatus;
	unsigned short protStatus;
	unsigned long addr;
	unsigned long blockAddr;
	unsigned long chipAddr;

	flg = OK;
	/* Step 1: Check that the block number exists */
	if(blockNo > NOR_BLOCK_MAX){
		flg = NG;
	}
	if(chipNo > NOR_NUM_CHIP_MAX){
		flg = NG;
	}
	
	/* Step 2: Send the AutoSelect command */
	sendNorCmd(chipNo, NOR_CMD_HEADER_1ST);
	sendNorCmd(chipNo, NOR_CMD_HEADER_2ND);
	sendNorCmd(chipNo, NOR_CMD_RESET_3RD);

	setNorAddrA25A24A23(0x00000000);		// Reset A25 and A24
	chipAddr = (unsigned long)norCsAddrTbl[chipNo];
	blockAddr =  BLOCK_TO_ADDR(blockNo) + 0x02;
	// addr = chipAddr + dmy;

	
	/* Step 3: Read Protection Status */
	protStatus = readNorWord(chipNo, blockAddr);
	if (protStatus == 0){
		flgStatus = NOR_CMD_UNPROTECTED;
	}
	if (protStatus == 0x0001){
		flgStatus = NOR_CMD_PROTECTED;
	} else{
		flgStatus = NOR_FLASH_PROTECTEDUNCLEAR;
	}
	// if((protStatus & 0x00FF) == NOR_CMD_UNPROTECTED){
	// 	flg = NG; // Uprotected
	// }else if((protStatus & 0x00FF) == NOR_CMD_PROTECTED){
	// 	flg = OK; // protected
	// }

	/* Step 4: Return to Read mode */
	reset(chipNo);

	// Exit from auto select mode
	sendNorCmd(chipNo, NOR_CMD_EXIT_AUTO_SEL);

	return flgStatus;

}
