
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Write a program in Assembly programming language to find a factorial of number for 8086.
.MODEL SMALL
.STACK 200H
.DATA
FACT DW ?
.CODE
BEGIN: MOV AX,@DATA
MOV DS, AX
MOV AX, 05H
MOV CH, 05H
BACK: DEC CH
CMP CH, 0
JE E12
MUL CH
MOV FACT, AX
LOOP BACK
E12:
MOV FACT, AX
MOV AH, 4CH
INT 21H
END BEGIN


ret




