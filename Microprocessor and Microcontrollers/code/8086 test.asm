; Verify if “Block1” is a Palindrome.

Data SEGMENT

    Block DB 'ABCDEEDCBA'
    Pal   DB 00H
    
Data ENDS

Extra SEGMENT

    Block2 DB 10 DUP(?)

Extra ENDS

Code SEGMENT

         ASSUME CS: Code, DS: Data, ES: Extra
         MOV    AX, Data
         MOV    DS, AX
         mov    ax, Extra
         mov    es, ax
    
         lea    si, Block1
         lea    di, Block2 + 9

         mov    cx, 00ah

    Back:cld
         lodsb
         stosb
         loop   Back

         lea    si, Block1
         lea    di, Block2
         mov    cx, 00ah
         cld

         REPZ   CMPSB
         jnz    Skip
         mov    Pal, 01h

    Skip:INT    3

Code ENDS

END Start

END