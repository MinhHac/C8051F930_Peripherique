/*
 * clavier.h
 *
 *  Created on: 11 avr. 2014
 *      Author:
 */
#ifndef CLAVIER_PORT_H_
#define CLAVIER_PORT_H_

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <compiler_defs.h>
#include <SI_C8051F930_Register_Enums.h>                // SFR declarations

//-----------------------------------------------------------------------------
// D�finition des I/O
//-----------------------------------------------------------------------------
//  in				 CLAVIER_X1  CLAVIER_X2  CLAVIER_X3
// 				     ----------------------------------
//  out	 CLAVIER_Y1  |	1		    2		    3     |
//	out	 CLAVIER_Y2  |	4		    5		    6     |
// 	out	 CLAVIER_Y3  |	7		    8		    9     |
// 	out	 CLAVIER_Y4  |	*		    0		    #     |
//		             ----------------------------------
//-----------------------------------------------------------------------------
SBIT (CLAVIER_X1, P2, 2);
SBIT (CLAVIER_X2, P2, 1);
SBIT (CLAVIER_X3, P2, 0);

SBIT (CLAVIER_Y1, P2, 3);
SBIT (CLAVIER_Y2, P2, 5);
SBIT (CLAVIER_Y3, P2, 6);
SBIT (CLAVIER_Y4, P2, 4);

//-----------------------------------------------------------------------------
// Mettre X en PUSH_PULL
//-----------------------------------------------------------------------------
#define	X1_PUSH_PULL;		P2MDOUT|=0x04;
#define	X2_PUSH_PULL;		P2MDOUT|=0x02;
#define	X3_PUSH_PULL;		P2MDOUT|=0x01;

//-----------------------------------------------------------------------------
// Mettre X en OPEN DRAIN
//-----------------------------------------------------------------------------
#define	X1_OPEN_DRAIN;		P2MDOUT&=~0x04;
#define	X2_OPEN_DRAIN;		P2MDOUT&=~0x02;
#define	X3_OPEN_DRAIN;		P2MDOUT&=~0x01;

//-----------------------------------------------------------------------------
#endif /* CLAVIER_H_ */
