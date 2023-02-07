        .ORIG X3000	; origine de mon program
        LD R1,zero
        ADD R1,R1,9
debut:  LEA R0,affichage
        PUTS
        ADD R1,R1,-1       
        BRzp debut
        HALT
zero:  .FILL 0
affichage: .STRINGZ "Z"
.END

; brouillon
ZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZ