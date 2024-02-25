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
	LDR R0,=n1
	LDR R1,=n2
	LDR R2,[R0]
	LDR R7,[R0]  ;MAKING EXTRA COPY
	LDR R3,[R1]
	MOV R5,#1
	CMP R2,R3
	BCS down
	MOV R4,R2
	MOV R2,R3  ;SWAPPING R2,R3
	MOV R3,R4
	MOV R7,R2   ;UPDATING R7 ALSO 
down
	MUL R2,R5   ;i*a
down3	SUB R2,R3    ;repeated subtraction
	CMP R2,R3    ;diff<smaller num[r3]=b
	BCS down3
	TEQ R2,#0
	BEQ down2
	ADD R5,#1
	MOV R2,R7
	BNE down
down2 MUL R6,R5,R7
STOP B STOP
n1 DCD 32
n2 DCD 14
