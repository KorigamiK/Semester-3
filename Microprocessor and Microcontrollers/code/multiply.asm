
;Multiply

;Write a program to multiply 2 8-bit numbers stored at 2000h and 2001h. Store the result at 2002H and 2003H

jmp start

;data


;code
start: LXI H, 0000H
LXI D, 0000H
LDA 2000H
ADI 00H
JZ Store
MOV E,A
LDA 2001H
ADI 00H
JZ store
MOV C,A
back: DAD D
DCR C
JNZ back
store:SHLD 2002H