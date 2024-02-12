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
	LDR R2,=DST
	LDR R0,=0x1234ABCD
	MOV R3,#8
Up	AND R1,R0,#0x0F
	CMP R1,#0x0A
	BCC do
	ADD R1,0x07
do	ADD R1,0x30
	STRB R1,[R2],#1
	ROR R0,#4
	SUBS R3,#1
	BNE Up	
STOP
	B STOP
	AREA mydata,DATA,READWRITE
DST DCD 0,0
	END