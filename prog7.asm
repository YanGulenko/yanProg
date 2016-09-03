.386   
cseg segment use16 
    assume cs:cseg
mass1 dw 18,67,10,45,33,80,91,23
mass2 db 4 dup(?),'$'


m1: 
lea si,mass1


call vvod
mov dx,cx
call vvod
mov ax,cx

;sub cs:a1,30h
;sub cs:a2,30h
lea si,mass1
mov cx,8

m2:
cmp word ptr cs:si,dx
jl short m6
cmp word ptr cs:si,ax
jg short m6
add bx,cs:si
m6:
inc si
inc si
loop m2

mov al,bh
and bh,00001111b
shr al,4
mov cs:mass2,al
mov cs:mass2+1,bh
mov al,bl
and bl,00001111b
shr al,4
mov cs:mass2+2,al
mov cs:mass2+3,bl
mov cx,4
lea di,mass2

m3:
cmp byte ptr cs:[di],9h
jle short m4
add byte ptr cs:[di],37h
jmp short m5
m4:
add byte ptr cs:[di],30h
m5:
inc di
loop m3

mov ah,9
lea dx, mass2
int 21h

mov ah,4ch 
int 21h 

vvod PROC

xor cx,cx              
m7:
mov ah,1               
int 21h
cmp  al,13              
je short stop               
sub al,30h             
cmp al,9               
jbe short m9                 
sub al,11h             
cmp al,5               
jbe short m8                
sub al,20h             
m8:
add al,10              
m9:
shl cx,4               
or cl,al              
jmp short m7                 
stop:                        
ret
vvod endp

cseg ends 
end m1
