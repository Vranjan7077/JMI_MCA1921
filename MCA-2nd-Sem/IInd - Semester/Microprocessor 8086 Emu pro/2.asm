
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Write a program in Assembly programming language to print "ELECTRICAL AND ELECTRONIC".
.MODEL SMALL
.STACK 100H
.DATA
MSG1    DB "ELECTRONIC AND ELECTRICAL$"
.CODE
    MOV AX,@DATA
    MOV DS,AX
    LEA DX,MSG1
    MOV AH,09H
    INT 21H
     MOV AH,4CH
    INT 21H
END


ret




