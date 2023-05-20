# Monty

## Stacks, Queues - LIFO, FIFO

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Usage](#usage)
- [Monty Bytecode File Format](#monty-bytecode-file-format)
- [Example](#example)
- [Supported Instructions (Opcodes)](#supported-instructions-opcodes)
- [Flowchart](#flowchart)
- [Credits](#credits)

## Introduction

![monty](https://github.com/Dr-dyrane/monty/assets/115133529/ad704944-7dee-489d-a674-dc07210b2186)

Monty is an interpreter for Monty bytecodes files, written by [Alexander Udeogaranya](https://github.com/Dr-dyrane) as a project for the ALX SE Program. Monty is a scripting language that uses a unique stack data structure with specific instructions to manipulate it. The interpreter reads Monty bytecodes files (with the .m extension) and executes the instructions specified in the file.

## Features

- Supports stack and queue data structures
- Implements various instructions for manipulating the stack/queue
- Provides error handling and reporting

## Requirements

- Ubuntu 20.04 LTS
- GCC compiler
- Standard C library

## Compilation

To compile the Monty interpreter, use the following command:

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Usage

1. Compile the Monty interpreter using the compilation command.
2. Execute the interpreter with the desired Monty bytecode file:

```
$ ./monty monty_byte_code_file.m
```

## Monty Bytecode File Format

Monty bytecode files contain instructions that the interpreter reads and executes. Each instruction is written on a separate line.

## Example

Consider the following Monty bytecode file (example.m):

```
push 1
push 2
push 3
pall
add
pall
```

Running the interpreter with this file will produce the following output:

```
3
2
1
5
1
```

## Supported Instructions (Opcodes)

- `push <int>`: Pushes an element onto the stack/queue.
- `pall`: Prints all elements in the stack/queue.
- `pint`: Prints the value at the top of the stack/queue.
- `pop`: Removes the top element from the stack/queue.
- `swap`: Swaps the top two elements of the stack/queue.
- `add`: Adds the top two elements of the stack/queue.
- `nop`: Does nothing.
- `sub`: Subtracts the top element from the second element of the stack/queue.
- `div`: Divides the second element by the top element of the stack/queue.
- `mul`: Multiplies the top two elements of the stack/queue.
- `mod`: Computes the modulo of the second element by the top element of the stack/queue.
- `pchar`: Prints the character represented by the top element of the stack/queue.
- `pstr`: Prints the string starting from the top element of the stack/queue.
- `rotl`: Rotates the stack/queue to the top.
- `rotr`: Rotates the stack/queue to the bottom.

## Flowchart

![Monty](https://github.com/Dr-dyrane/monty/assets/115133529/5b25eb3a-8a64-4b0b-baa5-eff85f944b0d)

## Credits

The Monty project was developed by [Alexander Udeogaranya](https://github.com/Dr-dyrane) as part of the ALX SE Program.
