#include "Simpletron.h"

/* Map each function to its corresponding function. */
std::map<int, Simpletron::func> Simpletron::map =
{
	{ READ, &Simpletron::read }, { WRITE, &Simpletron::write },
	{ LOAD, &Simpletron::load }, { STORE, &Simpletron::store },
	{ ADD, &Simpletron::add }, { SUBTRACT, &Simpletron::subtract },
	{ DIVIDE, &Simpletron::divide }, { MULTIPLY, &Simpletron::multiply },
	{ MOD, &Simpletron::mod }, { BRANCH, &Simpletron::branch },
	{ BRANCH_NEG, &Simpletron::branchNeg }, { BRANCH_ZERO, &Simpletron::branchZero },
	{ HALT, &Simpletron::halt }
};

Simpletron::Simpletron()
{
	/* Initlize all registers and mem */
	accumulator = instructionCounter = operationCode
		= operand = instructionRegister = 0;
	for (auto &elem : mem) 
	{
		elem = 2424;
	}
}

/* Calls a simpletron operation based on an opCode. */
void Simpletron::invoke(const int &operation)
{
	(this->*(map.find(operation)->second))();
}

void Simpletron::runApp()
{
	loadProgram();

	while (operationCode != HALT)
	{
		splitWord();
		instructionCounter += 1;
		invoke(operationCode);
	}
}

/* split word into opCode and operand */
void Simpletron::splitWord()
{
	instructionRegister = mem[instructionCounter];
	operationCode = instructionRegister / 100;
	operand = instructionRegister % 100;
}

/* Operations */
void Simpletron::read()
{
	cout << "? ";
	cin >> mem[operand];
}

void Simpletron::write()
{
	cout << "FROM WRITE: " << mem[operand] << endl;
}

void Simpletron::load()
{
	accumulator = mem[operand];
}

void Simpletron::store()
{
	mem[operand] = accumulator;
}

void Simpletron::add()
{
	accumulator += mem[operand];
}

void Simpletron::subtract()
{
	accumulator -= mem[operand];
}

void Simpletron::divide()
{
	accumulator /= mem[operand];
}

void Simpletron::multiply()
{
	accumulator *= mem[operand];
}

void Simpletron::mod()
{
	accumulator %= mem[operand];
}

void Simpletron::branch()
{
	instructionCounter = operand;
}

void Simpletron::branchNeg()
{
	if (accumulator < 0)
	{
		instructionCounter = operand;
	}
}

void Simpletron::branchZero()
{
	if (accumulator == 0)
	{
		instructionCounter = operand;
	}
}		

/* Terminate program then perform a memory dump. */
void Simpletron::halt()
{
	printRegisters();
	printMemory();
}

/* load proram into memory */
void Simpletron::loadProgram()
{
	std::ifstream inFile("program.txt", std::ifstream::in);
	std::string str;

	for (int i = 0; std::getline(inFile, str); ++i) 
	{
		mem[i] = std::stoi(str);
	}
	inFile.close();
}

/* printing functions */
void Simpletron::printRegisters() const
{
	cout << "REGISTERS:" << endl;
	cout << "accumulator         " << showpos << setfill('0') << setw(5) << internal << accumulator << endl;
	cout << "instructionCounter     " << noshowpos << setfill('0') << setw(2) << internal << instructionCounter << endl;
	cout << "instructionRegister " << showpos << setfill('0') << setw(5) << internal << instructionRegister << endl;
	cout << "operationCode          " << noshowpos << setfill('0') << setw(2) << internal << instructionCounter << endl;
	cout << "Operand                " << noshowpos << setfill('0') << setw(2) << internal << operand << endl << endl;
}

void Simpletron::printMemory() const
{
	cout << "Memory\n       0     1     2     3     4     5     6     7     8     9" << endl;
	for (int i = 0; i < 100; ++i)
	{
		if (i % 10 == 0)
		{
			if (i == 0)
			{
				cout << " ";
			}
			cout << noshowpos << i << " ";
		}
		cout << showpos << setfill('0') << setw(5) << internal << mem[i] << " ";
		if ((i + 1) % 10 == 0) cout << endl;
	}
}

void Simpletron::printMenu() const
{
	cout << "\t*** Welcome to Simpletron!***" << endl << endl
		<< "*** Please enter your program one instruction ***" << endl
		<< "*** (or data word) at a time. I will type the ***" << endl
		<< "*** location number and a question mark(?). ***" << endl
		<< "*** You then type the word for that location. ***" << endl
		<< "*** Type the sentinel - 99999 to stop entering ***" << endl
		<< "*** your program. ***" << endl;
}
