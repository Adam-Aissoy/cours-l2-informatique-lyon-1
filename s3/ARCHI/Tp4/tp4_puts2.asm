	.ORIG x3000      ; specify where to load the program in memory
	LEA R0,HELLO     
	PUTS             
	LEA R0,COURSE    
	PUTS             
	HALT             
HELLO:  .STRINGZ "Hello, world!\n"
COURSE: .STRINGZ "Bienvenue en ARCHI\n"
	.END
