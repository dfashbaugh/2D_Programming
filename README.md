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

## Instruction List
