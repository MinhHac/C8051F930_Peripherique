//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_C8051F930_Register_Enums.h>                // SFR declarations
#include "clavier_port.h"
#include "clavier.h"

//-----------------------------------------------------------------------------
// Activation:     Mettre X en PUSH_PULL  puis à 0
//-----------------------------------------------------------------------------
#define	ACTIVATION_X1;	  X1_PUSH_PULL; CLAVIER_X1=0;
#define	ACTIVATION_X2;	  X2_PUSH_PULL; CLAVIER_X2=0;
#define	ACTIVATION_X3;	  X3_PUSH_PULL; CLAVIER_X3=0;

//-----------------------------------------------------------------------------
// Désactivation   Mettre X à 1 puis en OPEN DRAIN
//-----------------------------------------------------------------------------
#define	DESACTIVATION_X1; CLAVIER_X1=1; X1_OPEN_DRAIN;
#define	DESACTIVATION_X2; CLAVIER_X2=1; X2_OPEN_DRAIN;
#define	DESACTIVATION_X3; CLAVIER_X3=1; X3_OPEN_DRAIN;

//-----------------------------------------------------------------------------
// Attente pour un changement de niveau :  1 CLK
//-----------------------------------------------------------------------------
#define	ATTENTE_NIVEAU_STABLE;  NOP();

//-----------------------------------------------------------------------------
// get_touche() Routine
//
// Parametre de sortie :
// 	= 0 			: si aucune touche appuyée
// 	= 0X7F			: si plusieurs touches appuyées
// 	= code ASCII	: de l'unique touche appuyée
//
// ----------------------------------------------------------------------------
char get_touche(void)
{
	unsigned char code_ASCII;
	unsigned char nb_touche=0;

	ACTIVATION_X1;
	ATTENTE_NIVEAU_STABLE;
	if(CLAVIER_Y1==0) {code_ASCII='1';nb_touche++;}
	if(CLAVIER_Y2==0) {code_ASCII='4';nb_touche++;}
	if(CLAVIER_Y3==0) {code_ASCII='7';nb_touche++;}
	if(CLAVIER_Y4==0) {code_ASCII='*';nb_touche++;}
	DESACTIVATION_X1;
	ACTIVATION_X2;
	ATTENTE_NIVEAU_STABLE;
	if(CLAVIER_Y1==0) {code_ASCII='2';nb_touche++;}
	if(CLAVIER_Y2==0) {code_ASCII='5';nb_touche++;}
	if(CLAVIER_Y3==0) {code_ASCII='8';nb_touche++;}
	if(CLAVIER_Y4==0) {code_ASCII='0';nb_touche++;}
	DESACTIVATION_X2;
	ACTIVATION_X3;
	ATTENTE_NIVEAU_STABLE;
	if(CLAVIER_Y1==0) {code_ASCII='3';nb_touche++;}
	if(CLAVIER_Y2==0) {code_ASCII='6';nb_touche++;}
	if(CLAVIER_Y3==0) {code_ASCII='9';nb_touche++;}
	if(CLAVIER_Y4==0) {code_ASCII='#';nb_touche++;}
	DESACTIVATION_X3;

	if(nb_touche==0)		return(0);
	else if(nb_touche!=1)	return(0X7F);
	else 					return(code_ASCII);
}


