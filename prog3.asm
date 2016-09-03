.386 
dseg segment use16 
x db 60
y dw ?
dseg ends 
  
cseg segment use16 
    assume ds:dseg, cs:cseg

m1: 
mov cx,dseg 
mov ds,cx

movzx ax,ds:x

cmp word ptr ax,50
je short m2
cmp word ptr ax,50
jg short m3
add ax,15
jmp short m4

m2:
add ax,5
jmp short m4

m3:
mov bx,200
sub bx,ax
mov ax,bx

m4:
mov ds:y,ax
mov ah,4ch 
int 21h 
cseg ends 
end m1