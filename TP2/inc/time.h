/*
 * time.h
 *
 *  Created on: 15 avr. 2014
 *      Author:
 */

#ifndef TIME_H_
#define TIME_H_

//-----------------------------------------------------------------------------
// Prototypes de fonctions
//-----------------------------------------------------------------------------
void attente_10(uint8_t);

//-----------------------------------------------------------------------------
// delay() Routine
//
// Valeur du paramètre d'entrée entre 2 et 255
// Si sysclock = 10Mhz : delay effectue une attente de 1us * paramètre d'entrée
//-----------------------------------------------------------------------------
#define delay(uint8_t) attente_10(uint8_t);

//-----------------------------------------------------------------------------
#endif /* TIME_H_ */
