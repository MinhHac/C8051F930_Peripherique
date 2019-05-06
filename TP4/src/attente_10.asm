;-----------------------------------------------------------------------------
;	Attente
;
;	Paramètre entrant est un char (passage par R7)
;	Fonction valise pour un paramètre entrant compris entre 2 et 255
;	Durée = 10 sysclock * parametre entrant
;-----------------------------------------------------------------------------
$include (c8051f930.inc)			;Include register definition file.
PUBLIC		_attente_10
wait		segment   CODE

				rseg     wait    	; Switch to this code segment.

_attente_10:						;	6
				DEC  R7				;	1
				SJMP attente_10a	;	3

attente_10b:						; boucle de 10 sysclock
				NOP					;	*1
				NOP					;	*1
				NOP					;	*1
				NOP					;	*1
				NOP					;	*1
				NOP					;	*1
				NOP					;	*1
attente_10a:	DJNZ R7,attente_10b	;	*3   	; 2

				NOP								; 1
				NOP								; 1
				NOP								; 1
				RET								; 5
;----------------------------------------------------------------
END
