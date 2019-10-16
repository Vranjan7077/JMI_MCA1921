
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Write a program in Assembly programming language to print a reverse of string.
;REVERSE OF STRING
.MODEL SMALL
.STACK 100H
.DATA
    MSG DB "HELLO WORLD"
    MSGD DB 12 DUP(?) 
    COUNT DW 11
.CODE
BEGIN:MOV AX,@DATA
      MOV DS,AX   ;SI USE BY DS
      MOV ES,AX   ;DI USE NY ES
      MOV CX,COUNT ;CX(THIS IS OF WORD TYPE) = 11
      MOV SI,0
      MOV DI,0 
      ADD DI,COUNT
      DEC DI             
AGAIN:
      MOV AL,MSG[SI]
      MOV MSGD[DI],AL
      INC SI
      DEC DI
      LOOP AGAIN    
      MOV MSGD[12],'$' 
      LEA DX,MSGD
      MOV AH,09H
      INT 21H
      
      MOV AH,4CH
      INT 21H
END BEGIN


ret




