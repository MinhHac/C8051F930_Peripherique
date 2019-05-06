//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_C8051F930_Register_Enums.h>                // SFR declarations
#include "time.h"
#include "one_wire_bus_port.h"

//-----------------------------------------------------------------------------
// Mettre IBUTTON en PUSH_PULL puis à 0
//-----------------------------------------------------------------------------
#define	IBUTTON_OUT_0;	IBUTTON_PUSH_PULL;IBUTTON=0;

//-----------------------------------------------------------------------------
//  Mettre IBUTTON à 1 puis en OPEN DRAIN
//-----------------------------------------------------------------------------
#define	IBUTTON_IN;		IBUTTON=1;IBUTTON_OPEN_DRAIN;

//-----------------------------------------------------------------------------
//  Fonctions du protocoles 1 wire bus
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  write_bit_1 : écriture d'un '1'
//-----------------------------------------------------------------------------
static void write_bit_1(void){
	IBUTTON_OUT_0;	delay(6);
	IBUTTON_IN;		delay(64);
}
//-----------------------------------------------------------------------------
//  write_bit_0 : écriture d'un '0'
//-----------------------------------------------------------------------------
static void write_bit_0(void){
	IBUTTON_OUT_0;	delay(60);
	IBUTTON_IN;		delay(10);
}
//-----------------------------------------------------------------------------
//  read_bit : lecture d'un bit du ibutton
//-----------------------------------------------------------------------------
static bit read_bit (void){
	bit lecture;

	IBUTTON_OUT_0;		delay(6);
	IBUTTON_IN;			delay(9);
	lecture=IBUTTON;	delay(55);
	return(lecture);
}
//-----------------------------------------------------------------------------
//  reset_line : fonction de détection d'un ibutton sur la broche
//
// paramètre sortant = 0 si au moins un ibutton est présent
//-----------------------------------------------------------------------------
bit reset_line(void){
	bit presence;

	IBUTTON_OUT_0;

	delay(240);
	delay(240);

	IBUTTON_IN;	        delay(70);
	presence = IBUTTON;

	delay(200);
	delay(210);
	return(presence);
}

//-----------------------------------------------------------------------------
// write_byte()
//
// écriture d'un octet vers le ibutton
//-----------------------------------------------------------------------------
void write_Byte(uint8_t octet){
	uint8_t u;
	for(u=0;u<8;u++) {
		if((octet & 0X01)==1) write_bit_1();
		else write_bit_0();
		octet = octet>>1;
	}
}

//-----------------------------------------------------------------------------
// read_byte()
//
// lecture d'un octet en provenance du ibutton
//-----------------------------------------------------------------------------
uint8_t read_Byte(void){
	uint8_t u,tampon=0;
	for(u=0;u<8;u++) {
		tampon=tampon>>1;
		if(read_bit()==1)	tampon|=0X80;
	}
	return(tampon);
}




