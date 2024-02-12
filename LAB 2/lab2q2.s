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
	MOV R10, #4
	LDR R0, = DST
	LDR R1, = SRC1
	LDR R2, = SRC2
UP	LDR R3, [R1], #4	
	LDR R4, [R2], #4
	ADCS R5, R3, R4
	STR R5, [R0], #4
	SUB R10, #1
	TEQ R10,#0
	BNE UP
	ADCS R6, #0	
	STR R6, [R0]
STOP B STOP
SRC1 DCD  0x12345678,0x11111111,0xABCDEF12,0xAAAAAAAA
SRC2 DCD  0xF2343412,0xFFFFFFFF,0x15ABCDEF,0xF0109999
	AREA mydata, DATA, READWRITE
DST DCD 0, 0
	END