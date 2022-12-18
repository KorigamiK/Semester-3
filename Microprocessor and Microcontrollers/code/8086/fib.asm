; calculate the fibonacci sequence

.MODEL SMALL
.DATA
    FIB  DB ?
    CNT  DB 10H    ; Initialize the counter for the no. of fibNo needed
.CODE
    START:
          MOV  AX,@DATA
          MOV  DS,AX
          LEA  DI, FIB
          MOV  CL,CNT
          MOV  AX,00H
          MOV  BX,01H
    L1:   
          ADD  AX,BX
          DAA
          MOV  [DI],AX
          MOV  AX,BX
          MOV  BX,[DI]
          
          INC  DI
          LOOP L1
          MOV  AH,4CH

          INT  21H
    END START
CODE ENDS
    