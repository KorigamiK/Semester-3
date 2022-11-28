; calculate the fibonacci sequence

; Declaration Part
.MODEL SMALL
.DATA
FIB DB?
CNT DB 10H ; Initialize the counter for the no. of fibonacci numbers needed

.CODE
START: MOV AX,@DATA
MOV DS,AX
LEA DI, FIB
MOV CL,CNT
MOV AX,00H
MOV BX,01H

;Fibonacci Part
L1:ADD AX,BX
;DAA
MOV [DI],AX
MOV AX,BX
MOV BX,[DI]
