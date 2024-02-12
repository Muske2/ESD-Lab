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
	LDR R0,=SRC
	MOV R1,#0
	LDR R3,=0X2537
	MOV R4,#-1
UP	CMP R1,#5
	BEQ stop
	LDR R2,[R0],#4
	TEQ R2,R3
	BEQ found
	ADD R1,#1
	B UP
found mov r4,r1
stop b stop
 
SRC DCD 0X1234,0X25372,0XABCDEF12,0X23,0X73723
	END
