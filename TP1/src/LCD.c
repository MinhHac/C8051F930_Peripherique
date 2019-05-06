//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_C8051F930_Register_Enums.h>                // SFR declarations
#include "time.h"
#include "LCD_port.h"
#include "LCD.h"


//-----------------------------------------------------------------------------
// init_LCD() :
//
// Initialisation de l'afficheur en mode 4 bits
//-----------------------------------------------------------------------------
void init_LCD(void){
    unsigned char u;

    AFFICHEUR_RS=0;
	//AFFICHEUR_ON;
    //for(u=0;u<250;u++) delay(200);									// attente 50ms afficheur ON

	AFFICHEUR_DB=0X30|(AFFICHEUR_DB & 0x0F); PULSE_EN;			
	for(u=0;u<42;u++) delay(100); 									// attente 4.2ms
	AFFICHEUR_DB=0X30|(AFFICHEUR_DB & 0x0F); PULSE_EN; 	delay(100);	// attente 0.1ms
	AFFICHEUR_DB=0X30|(AFFICHEUR_DB & 0x0F); PULSE_EN; 	delay(40);
	AFFICHEUR_DB=0X20|(AFFICHEUR_DB & 0x0F); PULSE_EN; 	delay(40);
	
	AFFICHEUR_DB=0X00|(AFFICHEUR_DB & 0x0F); PULSE_EN;	delay(40);
	AFFICHEUR_DB=0XE0|(AFFICHEUR_DB & 0x0F); PULSE_EN;	delay(40);

	AFFICHEUR_DB=0X00|(AFFICHEUR_DB & 0x0F); PULSE_EN;	delay(40);
	AFFICHEUR_DB=0X60|(AFFICHEUR_DB & 0x0F); PULSE_EN;	delay(40);

	AFFICHEUR_RS=1;
}

//-----------------------------------------------------------------------------
// sendByte_LCD() :
//-----------------------------------------------------------------------------
static void sendByte_LCD(unsigned char u){
	AFFICHEUR_DB= (u & 0xF0)|(AFFICHEUR_DB & 0x0F);	PULSE_EN;
	AFFICHEUR_DB= (u<<4)|(AFFICHEUR_DB & 0x0F);	PULSE_EN; delay(40);
}

//-----------------------------------------------------------------------------
// putc_LCD() :
//-----------------------------------------------------------------------------
char putC_LCD(char v){
	if(v=='\r')			{AFFICHEUR_RS = 0;sendByte_LCD(0X80);}
	else if(v=='\n')	{AFFICHEUR_RS = 0;sendByte_LCD(0XC0);}
	else				{AFFICHEUR_RS = 1;sendByte_LCD(v);}
	AFFICHEUR_RS = 1;
	return(0);
}
