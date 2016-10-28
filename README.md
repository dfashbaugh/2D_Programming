# 2D Programming

This is a simple concept for a language that is addressed in two dimensions. 

Imagine programming low level stuff by making flow charts or organizing tiles on a checker board. Each address is a 2D 
location, and each command points to a next address that is also a 2D location.

## How Does it Work?

It works like any other programming language. It has a program counter that points at a command, the command executes, then the program counter moves on. 
The program counter in this case is 2 dimensional though. So it doesn't 
really count..

The 2 dimensional program counter is constantly loaded by each
instruction that is executed. Therefore, every instruction includes the arguments necessary for the functionality of the 
instruction, but also includes a next address.

## What is this Code For?

The code in this repo is intended to be extended by other users. Its also written in C++ because my main intention is to use it with embedded systems.

Examples are Coming soon....

## Syntax

Syntax is a tricky question with 2D programming. In most cases, the syntax will probably be visual. But when it comes down to it, a file will be made at some point that will linearly contain the information.

Currently the command structure will be as follows:
```
InstructionAddressX InstructionAddressY Command Argument1 Argument2 NextAddrX NextAddrY

With a branch Instruction:
InstructionAddressX InstructionAddressY Command Argument1 Argument2 BrAddrX BrAddrY NextAddrX NextAddrY
```

That's really hard to look at. So lets do an example program that shows a for loop.
```
0 0 Set 0 20 0 1      % Set register 0 to 20 and point to address 0,1
0 1 Set 1 0 0 2       % Set register 1 to 0 and point to address 0,2
0 2 Set 2 1 1 2       % Set Register 2 to 1 and point to address 1,2
1 2 BrGr 0 1 1 1 -1 -1 % Check if register 0 is greater than register 1. Branch to 1,1 if so. If not end program with negative address
1 1 Add 2 1 1 1 2 	  % Add register 2 to register 1 and set register 1 to the sum and point to address 1,2
```
This is also hard to look at, but that's why this programming language is 2 Dimensional. Humans aren't intended to be the readers of the 'Assembly' this puts out. Anyway, this code will run a for loop that will run until register 1's value reaches 20

## Basic Command Set

* Set
  * Sets a register address to a given value
  * Syntax: `<AddrX> <AddrY> Set <Reg> <Value> <NextAddrX> <NextAddrY>`
  * Example: `0 1 Set 1 20 0 2`

* Add
  * Adds the values of 2 registers and saves the sum into a third regsiter
  * Syntax: `<AddrX> <AddrY> Add <Reg1> <Reg2> <RegDestination> <NextAddrX> <NextAddrY>`
  * Example: `0 1 Add 2 1 1 2 2`

More coming soon...

## Future Development

The goal of this code is to create an easily extensible 2D programming language that can run on embedded systems.

A code designer that allows visual design of XY code will be created. A compiler for that code designer, and a decompiler will also be made

I fully intend to create a series of libraries for 2D programming to cover things like Arduino control and DSP. These will serve as an example of how to program in 2D, but also should be useful libraries.

Future Libraries Intended to be written:
* Arduino
* DSP
* DsPIC
