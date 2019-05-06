//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_C8051F930_Register_Enums.h>                // SFR declarations
#include "one_wire_bus.h"
#include "ibutton.h"
#include "one_wire_bus_port.h"

//-----------------------------------------------------------------------------
// test_CRC()
//
// test du CRC ibutton
// paramètre sortant = 1 si le test du CRC est correct (sinon 0)
//-----------------------------------------------------------------------------
static bit test_CRC(uint8_t table_IBUTTON[8]){
	uint8_t i,j,k,n,crc=0;
	for(k=0;k<7;k++)
		for(i=1,j=0;j<8;i=i*2,j++){
			  n=(( (table_IBUTTON[k]&i)>>j)^crc)&1;
			  if(n==1)   { crc=crc^0X18;crc=crc>>1;crc+=128;}
			  else		 { crc=crc>>1;}
	    }
	if(crc==table_IBUTTON[7])   return(1);
	else						return(0);
}

//-----------------------------------------------------------------------------
// reset_IBUTTON()
//
// paramètre sortant = 1 si un ibutton est présent (sinon 0)
//-----------------------------------------------------------------------------
bit reset_IBUTTON(void) {

	if(reset_line()==0) return 1;		// la fonction reset_line() est à écrire dans la couche one_wire_bus !
	else return 0;
}

//-----------------------------------------------------------------------------
// lecture_ID()
//
// paramètre entrant = tableau à remplir avec l'ID du ibutton
// paramètre sortant = 1 si lecture d'un ID sans problème
//					 = 0 si pas de ibutton ou si erreur de CRC
//-----------------------------------------------------------------------------
bit lecture_ID(uint8_t table_IBUTTON[8]){

	 uint8_t i;
	 if(reset_IBUTTON()){    // verifier reset
	   write_Byte(0x33);
	   for(i =0;i<8;i++)  table_IBUTTON[i] = read_Byte();
	   if(test_CRC(table_IBUTTON)) return 1;
	   else return 0;
    }else return 0;
}


