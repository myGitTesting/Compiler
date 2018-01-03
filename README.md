OPERATION CODES:

Input/Output operations:
READ = 10; WRITE = 11;
Load and store operations:
LOAD = 20; STORE = 21;
Arithmetic operations:
ADD = 30; SUBTRACT = 31; DIVIDE = 32; MULTIPLY = 33;
Transfer-of-control operations:
BRANCH = 40; BRANCHNEG = 41; BRANCHZERO = 42; HALT = 43;
Take the following program as an example, which reads two numbers from the keyboard and prints their sum.

Location	Number	Instruction
00	+1007	Read A
01	+1008	Read B
02	+2007	Load A
03	+3008	Add B
04	+2109	Store C
05	+1109	Write C
06	+4300	Halt
07	+0000	Variable A
08	+0000	Variable B
09	+0000	Result C
