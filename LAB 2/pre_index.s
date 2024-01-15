Define 10 elements in ROM. Transfer this data into RAM.

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
	LDR R0,=SRC
	LDR R1,[R0]
	STR R1,[R2]
	LDR R1,[R0,#4]!
	STR R1,[R2,#4]!
	LDR R1,[R0,#4]!
	STR R1,[R2,#4]!
	LDR R1,[R0,#4]!
	STR R1,[R2,#4]!
	LDR R1,[R0,#4]!
	STR R1,[R2,#4]!
	LDR R1,[R0,#4]!
	STR R1,[R2,#4]!
	LDR R1,[R0,#4]!
	STR R1,[R2,#4]!
	LDR R1,[R0,#4]!
	STR R1,[R2,#4]!
	LDR R1,[R0,#4]!
	STR R1,[R2,#4]!
	LDR R1,[R0,#4]!
	STR R1,[R2,#4]!
	
STOP
	B STOP
SRC DCD 0X12345678,0XABCDEF12,0X12,0X3563,0x13131313,0x15,0xABC,0xAAAAA,0x12345,0x55
	AREA mydata,DATA,READWRITE
DST DCD 0,0
	END
