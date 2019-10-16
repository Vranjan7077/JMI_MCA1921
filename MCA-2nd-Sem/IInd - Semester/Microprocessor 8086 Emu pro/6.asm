
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Write a program in Assembly programming language to find number of time letter 'e'  in the "EXERSICE"  store  result in the memory location count.
.MODEL SMALL
.STACK 200H
.DATA 
    MSG DB ' CONTAIN E :$'
    STR DB 'EXERSICE$'
    COUNTER DW 8H  
    FIND DB 'E'
    COUNT DB 0
.CODE
BEGIN: MOV AX,@DATA
       MOV DS,AX 
       MOV ES,AX
       MOV CH,0
       MOV BX,OFFSET STR             
      LEA DX,STR
      MOV AH,09H
      INT 21H        
      LEA DX,MSG
      MOV AH,09H
      INT 21H
      MOV AL,FIND
      MOV DX,COUNTER             
BACK: CMP AL,[BX]
      JE CC
      INC BX
      DEC DX
      CMP DX,0
      JE OVER
      LOOP BACK 
      JMP OVER
CC: INC CH 
    INC BX  
    DEC DX
    CMP DX,0
    JE OVER     
    MOV AL,FIND
JMP BACK                  
OVER:
     MOV COUNT,CH
     MOV AH,4CH
     INT 21H
END BEGIN


ret




