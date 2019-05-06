/*
 * ibutton.h
 *
 *  Created on: 11 avr. 2014
 *      Author:
 */
#ifndef IBUTTON_H_
#define IBUTTON_H_

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <compiler_defs.h>
#include <SI_C8051F930_Register_Enums.h>                // SFR declarations

//-----------------------------------------------------------------------------
// Prototype de fonction
//-----------------------------------------------------------------------------
bit lecture_ID(uint8_t table[8]);
bit reset_IBUTTON(void);

//-----------------------------------------------------------------------------
#endif /* IBUTTON_H_ */
