//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_C8051F930_Register_Enums.h>                // SFR declarations
#include <stdio.h>
#include "variables_globales.h"
#include "pin_test.h"


//-----------------------------------------------------------------------------
//	UART0_ISR
//-----------------------------------------------------------------------------

INTERRUPT(UART0_ISR, UART0_IRQn){


	if(SCON0_TI==1){
		SCON0_TI=0;
		SBUF0=0x33;
		while(SCON0_TI==0);
		SCON0_TI=0;

	}
	else if(SCON0_RI==1){
		SCON0_RI=0;

	}

}




