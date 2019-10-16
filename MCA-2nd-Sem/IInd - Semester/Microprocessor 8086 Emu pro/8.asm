
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Write a program in Assembly programming language ,Input the username into the keyboard if the user name I same then will output username is valid otherwise print invalid username.

.MODEL SMALL
.STACK 100H
.DATA
MSG1    DB "ENETR THE USER NAME-->$"
CORRECT DB "--CORRECT USER NAME--$"
NOTCORRECT DB "--INCORRECT USER NAME--$"
USER_NAME  DB "VINAY"
COUNT DW 5
.CODE
BEGIN:           
    MOV AX,@DATA
    MOV DS,AX  
    MOV CX,COUNT   ;CX=5
    MOV BX,OFFSET  USER_NAME
    ;DISPLAY MESSAGE
    LEA DX,MSG1
    MOV AH,09H
    INT 21H
    ;READ CHARACTER                    
BACK:
    MOV AH,01
    INT 21H        
    CMP AL,[BX]
    JNE ERROR
    INC BX
    LOOP BACK                 
    LEA DX,CORRECT
    MOV AH,09H
    INT 21H
    JMP OVER   
ERROR: LEA DX,NOTCORRECT
      MOV AH,09H
      INT 21H
OVER:    MOV AH,4CH
    	   INT 21H
   END BEGIN


ret




