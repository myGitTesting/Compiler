Program takes a programming language called 'Simple', converts it to Simple Machine Language (SML), then executes it.

**SML**

The machine language syntax is a 4 digit number, where the leading two digits describe the operation and the trailing two digits describe the location in memory of which to run the operation against.

**OPERATION CODES:**

- Input/Output operations: 
    - READ = 10; WRITE = 11;
- Load and store operations:
    - LOAD = 20; STORE = 21;
- Arithmetic operations:
    - ADD = 30; SUBTRACT = 31; DIVIDE = 32; MULTIPLY = 33;
- Transfer-of-control operations:
    - BRANCH = 40; BRANCHNEG = 41; BRANCHZERO = 42; HALT = 43;

The following program as an example, which reads two numbers from the keyboard and prints their sum.

| Location      | Number        | Instruction  |
| ------------- |:-------------:| ------------:|
| 00            | +1007         | Read A       |       
| 01            | +1008         | Read B       |
| 02            | +2007         | Load A       |
| 03            | +3008         | Add B        |
| 04            | +2109         | Store C      |
| 05            | +1109         | Write C      |
| 06            | +4300         | Halt         |
| 07            | +0000         | Variable A   |
| 08            | +0000         | Variable B   |
| 09            | +0000         | Result C     |

**SIMPLE**

These are the following acceptable commands for the Simple language. Each statement begins with a line number. The actual value of the line is arbitrary, so long as the lines continue forth in ascending order.

| Command       | Example                  |
| ------------- |:------------------------:| 
| rem           | 10 rem this is a remark  |      
| input         | 20 input x               | 
| let           | 30 let a = 1 + (b * 2)   | 
| print         | 40 print a               | 
| goto          | 50 goto 60               | 
| if...goto     | 60 if a == x goto 70     | 
| end           | 70 end                   | 

Consider the following Simple code as an example, which reads 3 digits from the keyboard and prints the average.

| Simple Program |
| ------------------ |
| 10 rem calculate the average of 3 integers |  
| 20 input a |
| 30 input b |
| 40 input c |
| 50 let d = (a + b + c) / 3 |
| 60 print the average |
| 70 print d |
| 80 end |
