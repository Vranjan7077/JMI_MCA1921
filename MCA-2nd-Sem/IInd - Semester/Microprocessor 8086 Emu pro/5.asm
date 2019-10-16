
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Write a program in Assembly programming language to find the largest number in a block and store  result in the memeory location max.

.MODEL SMALL
.STACK 100H
.DATA
    N DB 23H,2H,45H,5H,46H
    COUNT DW 5H
    RESULT DB ?
.CODE
BEGIN:MOV AX,@DATA
      MOV DS,AX   
      MOV SI,0
      MOV BL,N[SI]
      MOV CX,COUNT
BACK:             
      INC SI
      CMP BL,N[SI]
      JNC NOSWAP
      MOV BL,N[SI]
NOSWAP:LOOP BACK 
       MOV RESULT,BL
        MOV AH,4CH
      INT 21H
END BEGIN


ret




