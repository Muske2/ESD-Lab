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
	LDR R0, = n1
	LDR R1, [R0]
	LDR R0, = n2
	LDR R2, [R0]
UP	SUBS R3, R1, R2
	BMI DOWN1
	SUBS R1, R2
	B DOWN2
DOWN1	SUBS R2, R1
DOWN2	BNE UP
STOP B STOP
n1 DCD 10
n2 DCD 15