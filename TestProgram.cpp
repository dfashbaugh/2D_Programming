#include <iostream>
#include "InstructionType.h"

using namespace std;

#define REG_FILE_SIZE 255
#define SETUP_TEST TwoDimensionalInstruction* instructions[10][10]; ClearRegisters(registers, regFileSize);

void PrintRegisters(int registers[], int regFileSize)
{
	for(int i = 0; i < regFileSize; i++)
	{
		cout << i << " " << registers[i] << endl;
	}
}

void ClearRegisters(int registers[], int regFileSize)
{
	for(int i = 0; i<255; i++)
	{
		registers[i] = 0;
	}
}

void OnSuccess(std::string testName)
{
	cout << testName << ": " << "Passed" << endl;
}

void OnFailure(std::string testName)
{
	cout << testName << ": " << "Failed" << endl;
}

void ListExpected(std::string valueName, int expected, int found)
{
	cout << "    " << valueName << " - Expected: " << expected << " Found: " << found << endl;
}

void TestAddCommand(int registers[], int regFileSize)
{
	std::string testName = "Add Instruction";
	SETUP_TEST

	registers[4] = 2;
	registers[2] = 6;

	instructions[0][0] = new AddInstruction(4, 2, 0, TwoDimensionalAddress(1, 0));

	TwoDimensionalAddress myAddr = instructions[0][0]->Execute(registers);

	if(registers[0] == 8 && myAddr.x == 1 && myAddr.y == 0)
	{
		OnSuccess(testName);
	}
	else
	{
		OnFailure(testName);
		ListExpected("Register 0 Value", 8, registers[0]);
		ListExpected("Address X", 1, myAddr.x);
		ListExpected("Address Y", 0, myAddr.y);
	}
}

void TestSubCommand(int registers[], int regFileSize)
{
	std::string testName = "Subtraction Instruction";
	SETUP_TEST

	registers[2] = 20;
	registers[3] = 12;

	instructions[0][0] = new SubInstruction(2, 3, 1, TwoDimensionalAddress(0, 1));

	TwoDimensionalAddress myAddr = instructions[0][0]->Execute(registers);

	if(registers[1] == 8 && myAddr.x == 0 && myAddr.y == 1)
	{
		OnSuccess(testName);
	}
	else
	{
		OnFailure(testName);
		ListExpected("Register 1 Value", 8, registers[1]);
		ListExpected("Address X", 0, myAddr.x);
		ListExpected("Address Y", 1, myAddr.y);
	}
}

void TestCommands()
{
	// Example Functional Execution Codee
	int registers [REG_FILE_SIZE];
	ClearRegisters(registers, REG_FILE_SIZE);

	TestAddCommand(registers, REG_FILE_SIZE);
	TestSubCommand(registers, REG_FILE_SIZE);
}

int main(void)
{
	cout << "Test Beginning" << endl;

	TestCommands();

	return 0;
}