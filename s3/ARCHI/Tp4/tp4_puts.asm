	.ORIG X3000     ; spécifie l'adresse de chargement du programme
	LEA R0,chaine
	PUTS
        HALT		; rend la main à l'OS
chaine:	.STRINGZ "hello\n"
.END
