; 8086 assembly program to transfer 10 bytes 
; from 2000:0000 to 3000:0000

Code SEGMENT
         ASSUME CS: Code
         MOV    AX, 2000H
         MOV    DS, AX
         MOV    AX, 3000H
         MOV    ES, AX
         MOV    SI, 0000H
         MOV    DI, 0000H
         MOV    CX, 000AH
         CLD
         REP    MOVSB
         INT    3
Code ENDS
END