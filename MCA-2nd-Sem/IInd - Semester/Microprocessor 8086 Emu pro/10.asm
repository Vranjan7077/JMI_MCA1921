
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Write a program in Assembly programming language , that take input from keyboard and print on the monitor.

.MODEL SMALL
.STACK 200
.DATA
.CODE
 BEGIN :MOV AX,@DATA
        MOV DS,AX              
        READING:
        MOV AH,01  ;TAKING CHARACTER FROM KEYBOARD
        INT 21H        
        CMP AL,13   ; COMPARE CHARACTER WITH ENTER
        JE EXIT        
        MOV AH,02
        INT 21H
        LOOP READING
        EXIT:
        MOV AH,4CH
        INT 21H
        END



ret




