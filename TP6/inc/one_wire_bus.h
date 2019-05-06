/*
 * ibutton.h
 *
 *  Created on: 11 avr. 2014
 *      Author:
 */
#ifndef ONE_WIRE_BUS_H_
#define ONE_WIRE_BUS_H_

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <compiler_defs.h>
#include <SI_C8051F930_Register_Enums.h>                // SFR declarations

//-----------------------------------------------------------------------------
// Prototype de fonctions
//-----------------------------------------------------------------------------
bit reset_line(void);
void write_Byte(uint8_t);
uint8_t read_Byte(void);

//-----------------------------------------------------------------------------
#endif /* IBUTTON_H_ */
