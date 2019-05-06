/*
 * afficheur.h
 *
 *  Created on: 11 avr. 2014
 *      Author:
 */
#ifndef LCD_H_
#define LCD_H_

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <compiler_defs.h>
#include <SI_C8051F930_Register_Enums.h>                // SFR declarations

//-----------------------------------------------------------------------------
// Prototype de fonction
//-----------------------------------------------------------------------------
void init_LCD(void);
char putC_LCD(char);
void clrscr_LCD();
void poweron_LCD(void);

//-----------------------------------------------------------------------------
#endif /* AFFICHEUR_H_ */
