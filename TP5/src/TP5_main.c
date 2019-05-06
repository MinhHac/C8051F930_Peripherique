
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_C8051F930_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
#include "LCD.h"
#include "LCD_port.h"

// $[Generated Includes]

#include "variables_globales.h"
#include "pin_test.h"
#include "time.h"
#include "stdio.h"

#include "clavier.h"
#include "ibutton.h"



// [Generated Includes]$

//-----------------------------------------------------------------------------
// Prototypes de fonctions
//-----------------------------------------------------------------------------
void scheduler(void);

//-----------------------------------------------------------------------------
// Wrapper
//-----------------------------------------------------------------------------
char getchar(void){
	return(get_touche());
}
char putchar(char c){
	return(putC_LCD(c));
}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void){
	if((RSTSRC&0x02)==0x00){
		if((RSTSRC&0x08)==0x08)
		   NOP();
	}
	// Call hardware initialization routine
	enter_DefaultMode_from_RESET();
	/*while(1){
		reset_IBUTTON();
		delay(250);
	}*/
	PCA0CPH5=0;

	IE_EA=1;

	while (1) 
   {
	while(new_task==0);
	new_task=0;
	scheduler();
   }
}

void scheduler(void){


    uint8_t key , table_ID[8];

    static uint8_t key_memoire = 0, etat_key = 0, compteur=0;  //

    static bit flag_affi_init,flag_affi_1,flag_affi_2, flag_allume, flag_init;



	PCA0CPH5=0;                                 //
	switch(scheduler_ct) {
	    case 0: {
	    	//TEST=!TEST;                       // pour mesurer sur oscilloscope
	    	key = getchar();                    // fonction getchar()
	    	//TEST=!TEST;                       // pour mesurer sur oscilloscope
	    	//NOP();

	    	if(key==0 && etat_key!=0){
	    		key_memoire=etat_key;
	    	    etat_key=0;
	    	}else if(key!=0){
	    		etat_key=key;
	    	}



	    	if(key_memoire != 0){
	    		//TEST=!TEST;

	    		if(key_memoire=='*'){
	    		    key_memoire=0;
	    		    flag_affi_1=1;
	    		}
	    		if(key_memoire=='#'){

		    		key_memoire=0;
		    		flag_affi_2=1;

	    		}

	    		key_memoire = 0;
		    	//NOP();
	    	}
	    	break;
	    }

	    case 1:{
	    		if(!flag_allume){
	    			poweron_LCD();
	    			flag_allume = 1;
	    		}else if(!flag_init) {
	    			init_LCD();
	    			flag_init = 1;
	    		}

	    	else {
	    		if(flag_affi_1 == 1){                               //affichage de message
	    			flag_affi_1 = 0;

	    			//putchar('0');
	    			//TEST=!TEST;
	    			printf("\r0123456789ABCDEF");
	    			printf("\n0123456789ABCDEF");
	    			//TEST=!TEST;
	    		}
	    		if(flag_affi_2 == 1){                               //affichage de message
	    			flag_affi_2 = 0;
	    			clrscr_LCD();
	    	  }
	    	}
	    	break;
	    }
	    case 3: {
	    	        compteur ++;
	    	        printf("\r %d : %d",compteur*100);

	    			break;
	    		}


		case 7: {
			/*
			nb_appels++;                        // incremente nb_appels a chaque fois de case 7
			if(nb_appels==50){
				for(i=0;i<100;i++) delay(120);  //fonction delay pour 1 microseconde, pour 12 ms = 100*120 us
			}*/
			break;
		}

		case 9: {

			//TEST = 0;
			lecture_ID(table_ID);
			//TEST = 1;
			NOP();
			break;

		}

	}
	scheduler_ct++;
	if(scheduler_ct==10) scheduler_ct=0;

}

INTERRUPT(TIMER3_ISR,TIMER3_IRQn) {			// Timer 3 base de temps de 10ms
	TMR3CN&=~0x80;
	new_task=1;
	//TEST=!TEST;
}

