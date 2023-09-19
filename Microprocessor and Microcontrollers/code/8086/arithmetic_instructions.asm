; 8086 assembly program to show the arithmetic instruction set
Data SEGMENT
      A          DB 14H
      B          DB 50H
      Sum        DB ?        ; word to store the sum of A + B
      Difference DB ?        ; word to store the difference A - B
      Product    DW ?        ; word to store the product A * B
      Division   DW ?        ; word to store the division A / B
Data ENDS

Code SEGMENT
            ASSUME CS: Code, DS: Data
      START:
            MOV    AX, Data
            MOV    DS, AX
      ; Addition
            MOV    AL, A
            ADD    AL, B
            MOV    Sum, AL
      ; Subtraction
            MOV    AL, A
            SUB    AL, B
            MOV    Difference, AL
      ; Multiplication
            MOV    AH, 0                   ; clear AH
            MOV    AL, A
            MUL    B
            MOV    Product, AX
      ; Division
            MOV    AH, 0                   ; clear AH
            MOV    AL, A
            DIV    B
            MOV    Division, AX
      ; Halt
            MOV    AH, 4CH
            INT    3H
Code ENDS

END
