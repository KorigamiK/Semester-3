; 8086 assemply program to calculate the square root of a number

.MODEL SMALL
.STACK 100
.DATA                     ; Data segment starts
    NUM1 DW 0019H         ; Initialize num1 to 0019 (25 in decimal
    SQRT DW 01 DUP (?)    ; Reserve 1 word of uninitialised data space to offset sqrt

.CODE                      ; Code segment starts
    START:
          MOV AX, @DATA    ; Initialize data segment
          MOV DS, AX
          MOV AX, NUM1     ; Move the number(num1) to AX
          XOR BX, BX       ; XOR is performed and result is stored in BX
          MOV BX, 0001H    ; Initialize BX to 0001H
          MOV CX, 0001H    ; Initialize CX to 0001H
    LOOP1:SUB AX, BX       ; AX <- AX - BX
          JZ  LOOP2        ;  If zero flag is zero jump to loop2
          INC CX           ;  Increment CX by 1
          ADD BX, 0002H    ; BX <- BX + 0002H
          JMP LOOP1        ;  Jump to loop1
          INC CX           ;  Increment CX by 1
    LOOP2:MOV SQRT, CX     ;  Store result
          INT 03H          ;  halt to debugger

END START