AREA   reset, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000 
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	EXPORT Reset_Handler
	ENTRY
Reset_Handler
	MOV R0,#12
	LDR R1,=0X12345
	MOV R3,#-12
	MOV R4,#2_10101010
	MOV R5,8_1763
	MOV R6,7_1563
STOP
	B STOP
	
