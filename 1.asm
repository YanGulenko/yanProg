.386
dseg  segment use16
buf	db	512 dup (0)	 ; область для содержимого сектора
text1 db 'Net svobodnogo mesta na diske$'
text2 db 'Vvedite razmer razdela v sectorah (8 znakov), ne menee FC0000,ne bolee:$'
text3 db 'Error$'
text4 db 0Dh,0Ah,'$'
text5 db 'Net svobodnoy zapisy$' 
buf1 db 9, 10 dup (?); план нажатий 9 и еще 10-й байт 

mass1 db 8 dup (0),'$'
mass2 db 8 dup (0)
razm dd 1E81A39h


dseg ends
cseg segment use16
assume ds:dseg,cs:cseg, es:dseg
m1:	mov ax, dseg
	mov ds,ax
	mov es,ax
mov ah,2	; номер функции 
mov dl,80h	; номер физического диска 
mov dh,0	; номер головки -0
mov cx,1	; номер цилиндра – 0, сектора - 1
mov al,1	; количество считываемых секторов
lea bx,buf 
int 13h
jnc x1

mov ah,9 ;ошибка чтения диска (CF=1)
lea dx,text3
int 21h
jmp m9

x1:
lea si,buf
mov si,1beh
mov eax,ds:razm
mov cx,4
xor ebx,ebx 
x2:
cmp byte ptr ds:[si+4],0
je x3
add ebx,ds:[si+12]
add si,16
loop x2

x3:
cmp ebx,eax
jl x4
mov ah,9
lea dx,text1
int 21h
jmp m9

x4:
sub eax,ebx
mov byte ptr ds:[si],0h
mov byte ptr ds:[si+4],07h

; получение ASCII кодов для вывода на экран
mov bx,0 
mov cx,8
t1: rol eax,4
mov dl,al
and dl,0Fh
cmp dl,9
jle t2
add dl,7
t2: add dl,30h
mov mass1[bx],dl
inc bx
loop t1
;выбор размера лог.диска
mov ah,9
lea dx,text2
int 21h
mov ah,9
lea dx,mass1
int 21h;-перевод в hex и вывод на экран свободного места

mov ah,9
lea dx,text4
int 21h

mov ah,0Ah
lea dx,Buf1
int 21h

; получение хекс кодов из ASCII кодов
mov di,2
mov cx,4
mov bp,0
q1: mov ah,buf1[di]
cmp ah,39h
jbe short q2
sub ah,37h
jmp short q3
q2: sub ah,30h
q3: ror ah,4
n1: mov bh,buf1[di+1]
cmp bh,39h
jbe short n2
sub bh,37h
jmp short n3
n2: sub bh,30h
n3: or ah,bh
mov mass2[bp],ah
inc bp
inc di
inc di
loop q1
 
lea bx,mass2
mov cx,4
add si,12
x5:
mov ah,ds:[bx+3]
mov ds:si,ah
inc si
dec bx
loop x5

sub si,8
mov ds:[si-3],00FFFFFEh
mov eax,ds:[si-16]
mov ebx,ds:[si-12]
add eax,ebx
mov ds:si,eax

cmp dword ptr ds:mass2,00FC0000h
jge q9
mov word ptr ds:si,0000h
mov word ptr ds:[si+1],0000h
jmp m8 
q9:
xor bx,bx
sub si,7
mov ds:si,00h
mov ax,ds:[si-11]
rol al,2
ror ax,2
and al,11000000b
or al,00000001b
mov ds:[si+1],ax




m8:
mov ah,3	
mov dl,80h	
mov dh,0	
mov cx,1
mov al,1	
lea bx,buf 
int 13h

m9:
mov ah,4ch
int 21h
cseg ends
end m1
