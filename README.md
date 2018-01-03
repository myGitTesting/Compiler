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
