	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=0X1234ABCD
	MOV R1,#32
	MOV R4,#0
UP	AND R2,R0,#0X01
	ROR R0,#1
	ADD R4,R2
	SUBS R1,#1
	BNE UP
STOP B STOP
	AREA mydata,DATA,READWRITE
	END