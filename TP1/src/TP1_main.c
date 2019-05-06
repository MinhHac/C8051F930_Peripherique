
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_C8051F930_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]

#include "variables_globales.h"
#include "pin_test.h"

// [Generated Includes]$

//-----------------------------------------------------------------------------
// Prototypes de fonctions
//-----------------------------------------------------------------------------
void scheduler(void);
//-----------------------------------------------------------------------------
// Wrapper
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{

	// Call hardware initialization routine
	enter_DefaultMode_from_RESET();

	IE_EA=1;

	while (1) 
   {
	while(new_task==0);
	new_task=0;
	scheduler();
   }                             
}

void scheduler(void){

	switch(scheduler_ct) {
		case 0: {

				break;
		}

		case 1: {

				break;
		}
	}

	scheduler_ct++;
	if(scheduler_ct==10) scheduler_ct=0;
}

INTERRUPT(TIMER3_ISR,TIMER3_IRQn) {			// Timer 3 base de temps de 10ms

	TMR3CN&=~0x80;
	new_task=1;
	TEST=!TEST;
}

