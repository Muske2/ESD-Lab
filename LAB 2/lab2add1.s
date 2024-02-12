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
	LDR R11,=0x20000000
    MSR xPSR,R11 ;sets carry to 1 (initialization)
	LDR R0, = DST
	LDR R1, = SRC1
	LDR R2, = SRC2
	LDR R3, [R1], #4	
	LDR R4, [R2], #4
	SBCS R5, R3, R4
	STR R5, [R0], #4
STOP B STOP
SRC2 DCD  0x1234ABCD
SRC1 DCD  0x01234567
	AREA mydata, DATA, READWRITE
DST DCD 0, 0
	END