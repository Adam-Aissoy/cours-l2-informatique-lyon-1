	.ORIG x3000

	; partie dédiée au code
	; complétez ici
	
	; je parcours mon tab 
	;while (var >=0){
	;	TAB[fin]-TAB[debut];
	;	debut++
	;}
	; 
	

			LEA R1,tabfin
			LEA R2,tabdeb
			LD R3,tabdeb
			ST R3,min
			LEA R4,tabdeb; on point vers tabdeut 
			
			NOT R2,R2
			ADD R2,R2,#1
			ADD R1,R2
	loop: 	BRn endloop
			ADD R4,R4,1 ; on increment le pc à label tabdeb
			LD R5,R4
			NOT R5,R5
			ADD R5,R5,#1; negation de R5 pour faire la difference de R5 et R3
			ADD R5,R5,R3
			BRp loop
			NOT R5,R5; si c'est negatif j'inverse le R5 et je le stoke a min
			ADD R5,R5,#1
			ST R5,min
			LD R3,min ; je remet mon registre R3 comme min 
			BR loop
			
	endloop:
	HALT

	; partie dédiée aux données
min:	.BLKW 1
max:	.BLKW 1
tabdeb:	.FILL x0000
	.FILL x0014
	.FILL xFFF8
	.FILL x000E
	.FILL xFFD8
	.FILL xFFB4
	.FILL x0041
	.FILL xFFFF
	.FILL x000A
tabfin:	.FILL xFFFC

	.END

