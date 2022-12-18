; 8086 assembly program to calculate the factorial of a number

DATA SEGMENT
    N    DW 7h    ; factorial to calculate
DATA ENDS

CODE SEGMENT
          ASSUME CS:CODE, DS:DATA
    START:
          MOV    AX, DATA
          MOV    DS, AX
          MOV    AX, N
          MOV    BX, AX
          DEC    BX

    LOOP1:
          MUL    BX
          DEC    BX
          JNZ    LOOP1
          MOV    N, AX               ; store result in N
          INT    3h                  ; break to debugger
CODE ENDS
    END START