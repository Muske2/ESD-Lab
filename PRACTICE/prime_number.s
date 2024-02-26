	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	EXPORT Reset_Handler
	ENTRY
Reset_Handler
 MOV R0,#15              ;Number which you want to test
 CMP R0,#01               ;Comparing with 01
 BEQ PRIME                ;If equal declare directly as prime
 CMP R0,#02               ;Compare with 02
 BEQ PRIME                ;If equal declare directly as prime
 MOV R1,R0                ;Copy test number in R1
 MOV R2,#02               ;Initial divider
UP                     
 BL DIVISION              ;Call for division sub-function
 CMP R8,#00               ;Compare remainder with 0
 BEQ NOTPRIME             ;If equal then its not prime
 ADD R2,R2,#01            ;If not increment divider and check
 CMP R2,R1                ;Compare divider with test number
 BEQ PRIME                ;All possible numbers are done means It's prime
 B UP                     ;If not repeat until end
NOTPRIME 
 LDR R3,=0x11111111       ;Declaring test number is not prime
 B STOP                   ;Jumping to infinite looping
PRIME 
 LDR R3,=0xFFFFFFFF       ;Declaring test number is prime number
STOP B STOP               ;Infinite looping

DIVISION                  ;Function for division operation
 MOV R8,R0                ;Copy of data from main function
  MOV R9,R2                ;Copy of divider from main function
LOOP                     
 SUB R8,R8,R9             ;Successive subtraction for division
 ADD R10,R10,#01          ;Counter for holding the result of division
 CMP R8,R9                ;Compares for non-zero result
 BPL LOOP                 ;Repeats the loop if subtraction is still needed
 MOV PC,LR                ;Return back to main function
 END
