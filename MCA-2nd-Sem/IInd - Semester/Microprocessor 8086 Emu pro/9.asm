
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Write a program in Assembly programming language , that multiply the two number and store result in the memory .
; 16 BIT MULTIPLICATION NUMBER
.MODEL SMALL
.STACK 200H
.DATA
     N1 DW 7895H
     N2 DW 0FFFFH
     PRODUCT DW 2 DUP(?)
.CODE                  
BEGIN:  MOV AX,@DATA
        MOV DS, AX
        MOV DX,0
        MOV AX,N1   ; AX = 7895H
        MUL N2      ; 7895*FFFF => DX : AX(LOWER PART STORE IN AX AND HIGHER PART STORE IN DX)
        MOV PRODUCT, AX
        MOV PRODUCT[2],DX                            
        MOV AH, 4CH
        INT 21H
END BEGIN


ret




