; Find the highest and lowest number in an array

Data segment
    arr  db 25h, 10h, 11h, 6h, 44h, 15h, 16h, 7h, 8h, 19h
    n    db 10h
Data ends

Code segment
           assume cs:code, ds:data
    start: 
           mov    si, arr
           mov    cx, n

           mov    ah, 00h
           mov    al, ffh

    back:  cmp    ah, [si]
           jle    higher
    higher:mov    ah, [si]
    next:  inc    si
           loop   back

           mov    [si], al
        
           int    3
Code ends

end start   