
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Write a program in Assembly programming language to find number of time  VOWEL  in the string   store  result in the memory location count.

;COUNT THE VOWEL
.MODEL SMALL
.STACK 200H
.DATA
    MSG DB "NAME :$"
    RESULT1 DB 0AH,0DH,"TOTAL CHARACTER :$"
    RESULT2 DB 0AH,0DH,"COUNTING VOWEL :$" 
 .CODE
BEGIN:
     MOV AX,@DATA
     MOV DS,AX
     
     MOV AH,09
     LEA DX,MSG
     INT 21H     
     MOV BL,0
     MOV CL,0     
     MOV AH,01
     INT 21H 
     WHILE:
        CMP AL,0DH
        JE ENDL        
        CMP AL,'A'
        JE OK         
        CMP AL,'E'
        JE OK        
        CMP AL,'I'
        JE OK        
        CMP AL,'O'
        JE OK        
        CMP AL,'U'
        JE OK             
        CMP AL,'a'
        JE OK        
        CMP AL,'e'
        JE OK       
        CMP AL,'i'
        JE OK        
        CMP AL,'o'
        JE OK        
        CMP AL,'u'
        JE OK        
        up:
        INC bl
        INT 21H        
        JMP WHILE        
        OK:
        INC CL
        JMP UP        
        ENDL:
        MOV AH,09
        LEA DX,RESULT1
        INT 21H        
        MOV AH,02
        MOV DL,BL
        ADD DL,30H
        INT 21H        
        MOV AH,9
        LEA DX,RESULT2 
        INT 21H        
        MOV AH,02
        MOV DL,CL
        ADD DL,30H
        INT 21H
     MOV AH,4CH
     INT 21H
END BEGIN       


ret




