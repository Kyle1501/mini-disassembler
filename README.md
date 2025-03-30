# Mini x86 Disassembler in C

A simple x86 disassembler written in C that reads raw machine code from a binary file and outputs the corresponding assembly instructions for known opcodes.

This project simulates the behavior of a disassembly engine by matching byte sequences against a predefined opcode table and printing readable assembly mnemonics.

## Features

- Parses binary machine code from a `.bin` file
- Matches both single-byte and multi-byte x86 instructions
- Prints disassembled instructions in human-readable form
- Handles unknown opcodes cleanly
- Fully written in C using only standard libraries

## Getting Started

### Compile:

gcc Disassembler.c -o Disassembler

## Run

./Disassembler

Make sure `test.bin` is in the same directory.

## Sample Output

push ebp mov ebp, esp unknown opcode 0x53 ... ret

pgsql
Copy
Edit

## Author

Kyle Anderson  
_Disassembler built from scratch as a learning tool for reverse engineering and low-level systems development._
