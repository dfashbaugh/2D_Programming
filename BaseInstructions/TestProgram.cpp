#include <iostream>
#include "InstructionType.h"

using namespace std;

#define REG_FILE_SIZE 255
#define SETUP_TEST TwoDimensionalInstruction* instructions[10][10]; ClearRegisters(registers, regFileSize);

struct ExpectedValue
{
	std::string valueName;
	int expectedValue;
	int actualValue;
};

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

void ListExpected(ExpectedValue value)
{
	cout << "    " << value.valueName << " - Expected: " << value.expectedValue << " Found: " << value.actualValue << endl;
}

void CheckResults(std::string testName, ExpectedValue valueList [], int numberOfValues)
{
	for(int i = 0; i < numberOfValues; i++)
	{
		if(valueList[i].expectedValue != valueList[i].actualValue)
		{
			OnFailure(testName);

			for(int j = 0; j < numberOfValues; j++)
			{
				ListExpected(valueList[j]);
			}

			return;
		}
	}

	OnSuccess(testName);
}

void TestAddCommand(int registers[], int regFileSize)
{
	std::string testName = "Add Instruction";

	SETUP_TEST

	registers[4] = 2;
	registers[2] = 6;

	instructions[0][0] = new AddInstruction(4, 2, 0, TwoDimensionalAddress(1, 0));

	TwoDimensionalAddress myAddr = instructions[0][0]->Execute(registers);

	ExpectedValue valueList [3];
	valueList[0].valueName = "Register 0 Value";
	valueList[0].expectedValue = 8;
	valueList[0].actualValue = registers[0];

	valueList[1].valueName = "Address X";
	valueList[1].expectedValue = 1;
	valueList[1].actualValue = myAddr.x;

	valueList[2].valueName = "Address Y";
	valueList[2].expectedValue = 0;
	valueList[2].actualValue = myAddr.y;

	CheckResults(testName, valueList, 3);
}

void TestSubCommand(int registers[], int regFileSize)
{
	std::string testName = "Subtraction Instruction";
	SETUP_TEST

	registers[2] = 20;
	registers[3] = 12;

	instructions[0][0] = new SubInstruction(2, 3, 1, TwoDimensionalAddress(0, 1));

	TwoDimensionalAddress myAddr = instructions[0][0]->Execute(registers);

	ExpectedValue valueList [3];
	valueList[0].valueName = "Register 1 Value";
	valueList[0].expectedValue = 8;
	valueList[0].actualValue = registers[1];

	valueList[1].valueName = "Address X";
	valueList[1].expectedValue = 0;
	valueList[1].actualValue = myAddr.x;

	valueList[2].valueName = "Address Y";
	valueList[2].expectedValue = 1;
	valueList[2].actualValue = myAddr.y;

	CheckResults(testName, valueList, 3);
}

void TestMultCommand(int registers[], int regFileSize)
{
	std::string testName = "Multiplication Instruction";
	SETUP_TEST

	registers[3] = 3;
	registers[5] = 5;

	instructions[0][0] = new MultInstruction(3, 5, 4, TwoDimensionalAddress(1, 0));

	TwoDimensionalAddress myAddr = instructions[0][0]->Execute(registers);

	ExpectedValue valueList [3];
	valueList[0].valueName = "Register 4 Value";
	valueList[0].expectedValue = 15;
	valueList[0].actualValue = registers[4];

	valueList[1].valueName = "Address X";
	valueList[1].expectedValue = 1;
	valueList[1].actualValue = myAddr.x;

	valueList[2].valueName = "Address Y";
	valueList[2].expectedValue = 0;
	valueList[2].actualValue = myAddr.y;

	CheckResults(testName, valueList, 3);
}

void TestDivCommand(int registers[], int regFileSize)
{
	std::string testName = "Division Instruction";
	SETUP_TEST

	registers[3] = 6;
	registers[5] = 2;

	instructions[0][0] = new DivInstruction(3, 5, 4, TwoDimensionalAddress(1, 0));

	TwoDimensionalAddress myAddr = instructions[0][0]->Execute(registers);

	ExpectedValue valueList [3];
	valueList[0].valueName = "Register 4 Value";
	valueList[0].expectedValue = 3;
	valueList[0].actualValue = registers[4];

	valueList[1].valueName = "Address X";
	valueList[1].expectedValue = 1;
	valueList[1].actualValue = myAddr.x;

	valueList[2].valueName = "Address Y";
	valueList[2].expectedValue = 0;
	valueList[2].actualValue = myAddr.y;

	CheckResults(testName, valueList, 3);
}

void TestBranchIfGreaterCommand(int registers[], int regFileSize)
{
	std::string testName = "Branch If Greater Instruction";
	SETUP_TEST

	registers[2] = 4;
	registers[3] = 1;

	instructions[0][0] = new BranchIfGreaterInstruction(2,3, TwoDimensionalAddress(1,2), TwoDimensionalAddress(3,4));
	TwoDimensionalAddress myAddr =  instructions[0][0]->Execute(registers);

	ExpectedValue valueList [2];
	valueList[0].valueName = "Address X";
	valueList[0].expectedValue = 3;
	valueList[0].actualValue = myAddr.x;

	valueList[1].valueName = "Address Y";
	valueList[1].expectedValue = 4;
	valueList[1].actualValue = myAddr.y;

	CheckResults(testName, valueList, 2);
}

void TestSetCommand(int registers[], int regFileSize)
{
	std::string testName = "Set Instruction";
	SETUP_TEST

	instructions[0][0] = new SetInstruction(1, 22, TwoDimensionalAddress(1, 2));
	TwoDimensionalAddress myAddr = instructions[0][0]->Execute(registers);

	ExpectedValue valueList [3];
	valueList[0].valueName = "Register 1 Value";
	valueList[0].expectedValue = 22;
	valueList[0].actualValue = registers[1];

	valueList[1].valueName = "Address X";
	valueList[1].expectedValue = 1;
	valueList[1].actualValue = myAddr.x;

	valueList[2].valueName = "Address Y";
	valueList[2].expectedValue = 2;
	valueList[2].actualValue = myAddr.y;

	CheckResults(testName, valueList, 3);
}

void TestNOpCommand(int registers[], int regFileSize)
{
	std::string testName = "NOp Instruction";
	SETUP_TEST

	instructions[0][0] = new NOpInstruction(TwoDimensionalAddress(1,0));
	TwoDimensionalAddress myAddr = instructions[0][0]->Execute(registers);

	ExpectedValue valueList [2];

	valueList[0].valueName = "Address X";
	valueList[0].expectedValue = 1;
	valueList[0].actualValue = myAddr.x;

	valueList[1].valueName = "Address Y";
	valueList[1].expectedValue = 0;
	valueList[1].actualValue = myAddr.y;

	CheckResults(testName, valueList, 2);
}

void TestCommands()
{
	// Example Functional Execution Codee
	int registers [REG_FILE_SIZE];
	ClearRegisters(registers, REG_FILE_SIZE);

	TestAddCommand(registers, REG_FILE_SIZE);
	TestSubCommand(registers, REG_FILE_SIZE);
	TestMultCommand(registers, REG_FILE_SIZE);
	TestDivCommand(registers, REG_FILE_SIZE);
	TestBranchIfGreaterCommand(registers, REG_FILE_SIZE);
	TestSetCommand(registers, REG_FILE_SIZE);
	TestNOpCommand(registers, REG_FILE_SIZE);
}

int main(void)
{
	cout << "Test Beginning" << endl;

	TestCommands();

	return 0;
}