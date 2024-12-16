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
/*  FILE        :m_switch.c		                                       */
/*  DATE        :Tue, Oct 31, 2006                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#include "include.h"

/****************************************************************************/
/* 		getAllSw, etc														*/
#if 1
// Get all switch state
void getAllSwState()
{
	swStateFlg = 0;
	getSingleSw(SW1, S_SW1);
	getSingleSw(SW2, S_SW2);
	getSingleSw(SW3, S_SW3);
	getSingleSw(SW4, S_SW4);
	getSingleSw(SW5, S_SW5);
}

// Process all switch state
void processAllSwState()
{
	
}

// Get single switch state
void getSingleSw(unsigned char swValue, unsigned char swIndex)
{
	if(!swValue){			// Switch is pressed
		if(!(swStateBak & uint8Tbl[swIndex])){
			swStateBak |= uint8Tbl[swIndex];
		} else {
			if(!(swState & uint8Tbl[swIndex])){
				swState |= uint8Tbl[swIndex];
				swStateFlg |= uint8Tbl[swIndex];
			}
		}
	} else {			// Switch is releaseds
		if((swStateBak & uint8Tbl[swIndex])){
			swStateBak &= ~uint8Tbl[swIndex];
		} else {
			if(!(swState & uint8Tbl[swIndex])){
				swState &= ~uint8Tbl[swIndex];
				swStateFlg |= uint8Tbl[swIndex];
			}
		}
	}
}

#endif
/*		End of WAIT															*/
/****************************************************************************/

