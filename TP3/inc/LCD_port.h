/*
 * afficheur.h
 *
 *  Created on: 11 avr. 2014
 *      Author:
 */
#ifndef LCD_PORT_H_
#define LCD_PORT_H_

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <compiler_defs.h>
#include <SI_C8051F930_Register_Enums.h>                // SFR declarations

//-----------------------------------------------------------------------------
// Définitions pour l'afficheur
//
// AFFICHEUR_DB : utilisation uniquement du poids fort de P1 (P1.4/5/6/7)
//-----------------------------------------------------------------------------
#define	AFFICHEUR_DB	P1

SBIT (AFFICHEUR_RS, P1, 3);
SBIT (AFFICHEUR_EN,	P1, 1);
SBIT (AFFICHEUR_POWER, P1, 2);

//-----------------------------------------------------------------------------
// AFFICHEUR OFF :
//
// => les quatre bits de poids fort de AFFICHEUR_DB sont mis à '1'
// => AFFICHEUR_RS=1, AFFICHEUR_EN=1, AFFICHEUR_POWER=0
// => AFFICHEUR_DB, AFFICHEUR_RS, AFFICHEUR_EN et AFFICHEUR_POWER en open-drain
//-----------------------------------------------------------------------------
#define	AFFICHEUR_OFF; \
		P1|=0XF0;AFFICHEUR_RS=1;AFFICHEUR_EN=1;AFFICHEUR_POWER=0;\
		P1MDOUT&=~0xF0;P1MDOUT&=~0x0E;

//-----------------------------------------------------------------------------
// AFFICHEUR ON :
//
// => les quatre bits de poids fort de AFFICHEUR_DB sont mis à '1'
// => AFFICHEUR_RS=1, AFFICHEUR_EN=0, AFFICHEUR_POWER=1
// => AFFICHEUR_DB, AFFICHEUR_RS, AFFICHEUR_EN et AFFICHEUR_POWER en push-pull
//-----------------------------------------------------------------------------
#define	AFFICHEUR_ON; \
		P1|=0XF0;AFFICHEUR_RS=1;AFFICHEUR_EN=0;AFFICHEUR_POWER=1;\
		P1MDOUT|=0xF0;P1MDOUT|=0x0E;

//-----------------------------------------------------------------------------
// PULSE_EN :
//
// La durée du pulse depend de l'afficheur.
//-----------------------------------------------------------------------------
#define PULSE_EN	AFFICHEUR_EN=1; NOP();\
					AFFICHEUR_EN=0;

//-----------------------------------------------------------------------------
#endif /* AFFICHEUR_H_ */
