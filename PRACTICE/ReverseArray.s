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
	LDR R0,=SRC
	LDR R1,=0X10002000
	MOV R3,#5
UP	LDR R2,[R0],#4
	STR R2,[R1],#-4
	SUBS R3,#1
	BNE UP
STOP B STOP
SRC DCD 0X12345678,0X10101010,0X23,0XABCDEF12,0X1A2B3C4D
	AREA mydata,DATA,READWRITE
DST DCD 0
	END