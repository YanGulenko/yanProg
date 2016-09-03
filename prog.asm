.386
dseg segment use16
    a db 80h,80h,80h,80h
    b dw 77h
    c dw -127
    d dw 15
    e db 'AZ'
dseg ends

eseg segment use16
    ea dw ?
    eb dw ?
    e1 db ?,?
eseg ends

cseg segment use16
    assume ds:dseg, cs:cseg, es:eseg

m1:
    mov cx,dseg
    mov ds,cx
    mov bx,eseg
    mov es,bx
    
    movsx cx,ds:a
    mov es:ea,cx

    mov bx,ds:b
    mov es:eb,bx
    
    mov ax,ds:word ptr e
    mov es:e1,ah
    mov es:e1+1,al
    
    mov ax,4ch
    int 21h
cseg ends
end m1