	AREA reset, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	EXPORT Reset_Handler
	ENTRY
Reset_Handler
	LDR R0,=ARR1
	MOV R1,#10
UP LDR R2,[R0],#4
	ADDS R3,R2
	ADC R4,#0
	SUBS R1,#1
	BNE UP
	LDR R5,=RES
	STR R3,[R5]
	STR R4,[R5,#4]
STOP B STOP
ARR1 DCD 0x12345678,0x11100111,0xABCDEF12,0xAAAABBBB,0x12,0x18001818,0x1225,0x1010,0x129,0x89898989
	AREA mydata,DATA,READWRITE
RES DCD 0,0
	END