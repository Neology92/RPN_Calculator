*Please note, that not everything in this project is in english.*

# RPN Calculator

This program is next step of my C education.
The calculator uses Reversed Polish Notation and is based on dc cross-platform program.

## Gettin' started

```sh
$ make
$ make clean 
$ ./program
```

### Basics

Program memory is based on stack, on which top are putted next numbers.
Operations are executed at once - numbers are pushed on stack.

### How to use

User gives commands and numbers on stding
Mathematical operations use 2 top arguments from stack. Result is putted as new top of the stack.

Symbols interpreted by program:
    
    '+', '-', '*', '/'  	- Basic numbers operations
					'f' 	- Print the stack				
					'p' 	- Print top number
					'c'     - Clear all
					'P' 	- Pop (delete) top element
					'r' 	- Reverse 2 top elements
					'd' 	- Duplicate top number
					'q' 	- Quit

There are two implementations of stack (education reasons). 
User can use the implementation simply by choosing 1, or 2 at symbolic const "IMPL" in funkcje.h header file.
If array implementation is used - stack limit is specified at symb const "STACK_LIM" in funkcje.h header file. 

##### Example

```sh
$ ./program
$ 1 1 + d * d * 2 / 
$ -2 + 7 8 9 r
$ f q 
```
output:
```sh
===top===
    8
    9
    7
    6
```

### Notes

Calculator works on integers.
Numbers and results of operations cannot exceed int limits.

### Main learn targets in this project

 Stack implementations
 

License
---

MIT
