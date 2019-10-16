
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Write a program in Assembly programming language to print sum of series of 10 number and store the result in the memeory location total.

;SUM OF SERISE OF 10 NUMBER
 .MODEL SMALL
 .STACK 200H
 .DATA 
       MSG DB "TOTAL:$"
       TOTAL DW ?
       COUNT DW 10
 .CODE
 BEGIN:MOV AX,@DATA
       MOV DS,AX
       MOV AX,00   
       MOV CX,00         
       MOV CX,COUNT
AGAIN:
       ADD AX,CX
       LOOP AGAIN
       MOV TOTAL,AX  
       ;LEA DX,MSG
       ;MOV AH,09H
       ;INT 21H      
       ;LEA DX,
       ;MOV AH,09H
       ;INT 21H
       
       MOV AH,4CH
       INT 21H
END BEGIN


ret




