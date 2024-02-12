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
	LDR R1,[R0]
	MLA R4,R1,R1,R1
	LDR R2,=RES
	LSR R4,#1     ;ASR ALSO WORKS
	STR R4,[R2]
 
	
STOP B STOP
SRC DCD 10
	AREA mydata,DATA,READWRITE
RES DCD 0
 
	
	END