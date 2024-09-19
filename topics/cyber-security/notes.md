# cybersecurity notes

## relevant tools

you will need the following languages:
-  C,
- python
- bash
- ruby
- php
- perl

you will want the following debugging tools:
- gdb
- valgrind
- strace

don't worry if you don't know these, we will cover the basics along the way. but what you really need to know (that i won't be covering) is the following:
- python
- C
- bash

if you don't know these, you're cooked. go read my notes on them first.


## ssh'ing into an ip address

how can we ssh into an old machine where we have the ip address?

```bash
ssh username@ip_address
```

we will typically get an error message like this:

```bash
Unable to negotiate with `ip_address` port 22: no matching key exchange method found. Their offer: diffie-hellman-group1-sha1
```

this is because the server is using an outdated key exchange method. we can listen to the server's offer, but we just end up running into a different error message.

the reason we are looking into this is because we will be working work old machine images that may have security vulerabilities. it will be easier to exploit these vulnerabilities while we are ssh'd into the machine.

### red hat 7.2

for my notes, i will be using a very old red hat 7.2 machine. specifically, we are using: rh72 2.4.7-10. we will be using this machine to learn about cybersecurity. you can find a zip for the vm in `cyber-security/VMs/RH72BufferOverruns

for the VM we are using, the command to `ssh` into it can be found in `jots.md`, but i add it here as well:
```
ssh -oKexAlgorithms=+diffie-hellman-group1-sha1 -c 3des-cbc hacker@10.10.10.12
```
where `10.10.10.12` is the ip address of the machine we are trying to ssh into.

## components of a computer system

### CPU
- executes instructions
- has registers to store data

### memory
- has stack and heap
- has program data
- has OS data

### instructions
- are executed by the CPU
- are loaded into memory from source code


now we ask the question. when we compile a program, it turns into an executable which can be run on a computer. this executable contains instructions. we ask the question, "how can we know what the instructions even mean? how are sure that a line of binary is an instruction to add somethong or just some data?"

well it depends on the CPU's architecture. the CPU looks at the instruction and determines what to do with it based on where the byutes are located and what values they are. we often represent these instructions in hex, because hex is a compact form.

## hexidecimal

hexidecimal is a base 16 number system. it uses the digits 0-9 and the letters A-F. it is used to represent binary data in a more compact form.

### converting between hex and binary

| Binary | Hexadecimal |
|--------|-------------|
| 0000   | 0           |
| 0001   | 1           |
| 0010   | 2           |
| 0011   | 3           |
| 0100   | 4           |
| 0101   | 5           |
| 0110   | 6           |
| 0111   | 7           |
| 1000   | 8           |
| 1001   | 9           |
| 1010   | A           |
| 1011   | B           |
| 1100   | C           |
| 1101   | D           |
| 1110   | E           |
| 1111   | F           |

hexidecimal usually starts with `0x` to indicate that it is a hex number. for example, `0x1A` is the hexidecimal representation of the binary number `00011010`.


### using gdb on a C program

we will learn how to effectively use gdb to debug a C program. this will help us understand how a program works at a low level.

consider the following C program:

```c
main(int argc, char **argv) {
    int x = 5;
    int y = 6;
    int z = x + y;
    printf("z is %d\n", z);
}
```

we can compile this program with the following command:

```bash
gcc -g -o add add.c
```

this allows us to be able to use gdb on the program. we can run the program with the following command:

```bash
gdb ./add
```

now let's add a break point at the start of main and run gdb:

```bash
(gdb) break main
(gdb) run
```

if do run, we see we are at the start of the main function since we added our breakpoint.

instead of typing `break`, we can also just type `b`. we could also break at a specific line number if we would like. for example:
```bash
(gdb) b 64
```

and to run, we could have used `r` instead. similarly, we can also step through code using the `step` command or `s` for short:
```bash
(gdb) step
``` 

moving on, we can also disassemble the main function with the following command:

```bash
(gdb) disassemble main
```

this will show us the assembly code for the main function. 

we can also see all the information about the registers with the following command:

```bash
(gdb) info registers
```

for this to work, we need to have executed some code (for example, we we set a breakpoint before).

note that we see many different register names like "ebp, esp, eip" or "rbp, rsp, rip". the "e" stands for "extended" and the "r" stands for "register". you might see "r" on a 64-bit system and "e" on a 32-bit system. we will list what these are for in the next section.

we can also use the command `x / 32` to see the next 32 bytes of memory. x stands for "examine" and 32 is the number of bytes we want to see. for example:

```bash
(gdb) x / 32 $esp
```
the above command will show us the next 32 bytes of memory starting from the stack pointer.

depending on the architecture, gdb might show us the memory in different ways. for example, on a 32-bit system, gdb might show us the memory in 4-byte chunks, while on a 64-bit system, gdb might show us the memory in 8-byte chunks.

## x86-64 registers

we will mostly only be inspecting the stack pointer, frame pointer, and instruction pointer but here's a list of all the registers and what they are used for:

rax: accumulator
- used for arithmetic operations

rbx: base
- used as a base pointer. this is a general purpose register.

rcx: counter
- used for loops and string operations

rdx: data
- used for I/O operations

rsi: source index
- used for string operations

rdi: destination index
- used for string operations

rbp: **base pointer** aka frame pointer
- points to the base of the stack frame.

rsp: **stack pointer**
- points to the top of the stack

rip: **instruction pointer**
- points to the next instruction to be executed


and for **the** 32-bit system it is the same, but with an "e" instead of an "r". for example, eax instead of rax.


## WYSINWYX

what you see is not what you execute. this is one of the most fundamental ideas in computer security. the idea is that your source code may seem fine, but what happens in the background at a low level may include hidden vulnerabilities.

for example, consider the following code:
```c
set(password, '\0', len);
free(password);
```
where `password` is some pointer to a string that contains sensitive data and len is the length of the string. a compiler might attempt to "optimize" this code never actually compiling code to call `set` because it sees that the memory is never used later on. this would leave the password in memory, even after it has been freed.

the idea is that we can't trust the source code for program security. a better security check would be to examine the compiled code and test for vulnerabilities there. you never know what the compiler might do to your code.

another such example is cases where libraries not part of the standard library are used. for example, in C, if you want to make a multithreaded program, you would typically use `pthread.h`, but this is an external library not part of the standard C framework. hence the compiler might create security risks for multithreaded programs that it would otherwise not have for single-threaded programs. 

### unexpected function pointer behavior

below is an example of how we can implicitly call a function pointer by manipulating memory:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f2() {
    printf("hello from f2\n");
}

void f1() {
    printf("jaja from f1\n");
}

int main() {
    int (*f) (void);
    // this is a function **pointer**
    // recall the syntax: int (*f) (void) means that f is a pointer to a function that returns and integer and takes no arguments (void)
    

    int diff = (char*)&f2 - (char*)&f1; 
    // gives offset between f1 and f2

    f = &f1;
    f = (int (*)())((char*)f + diff); 
    // f now points to f2
    
    (*f)(); 
    // indirect call to f2
}
```
not that we simplify took the difference between the memory addresses of the two functions and added that to the memory address of the first function. this allowed us to call the second function using the function pointer.

this may seem obvious or trivial, but we extend this idea to buffer overruns and other security vulnerabilities. what if we could manipulate memory to call a function that we shouldn't be able to call? this is the basis of many security vulnerabilities.


## buffer overruns

buffer overruns are a common security vulnerability in C programs. they occur when a program writes more data to a buffer than it can hold. this can cause the program to crash, or worse, allow an attacker to execute arbitrary code on the system.

see the c program in `code_examples/bufferoverruns/stack.c`

```c
#include<stdio.h>

// global variables, available to the whole program
char c;
short s;
int i;
long l;
float f;
double d;

int sumNums(int n, int m){
	int i;
	int sum=0;
	char c[16];
	i=n;
	while(i<m){
		sum=sum+i;
		i=i+1;
	}
	
	/*
	 *  modify this so 
	 * that the return address is overwritten with the address of hacked
	c[0]=0xb0;
	c[1]=0x25;
	c[2]=0x33;
	c[3]=0x55;
	*/

	return sum;
}
void f1(int a, int b, int c, int d){

}
void hacked(){
	printf("I've been hacked\n");
}
int main(int argc, char ** argv){
	sumNums(3,7);
	f1(1,2,3,4);
	f1(1,2,3,4);
}

```

we will compile this with the `-g` flag:
```bash
gcc -g stack.
```

and run it with gdb:
```bash
gdb ./stack
```

we can then use `list` to list the sumNums and main function, then use `b` to set some breakpoints:
```bash
listSumnums 
b 93 # nefore the "modify this" comment
list main
b 112 # on the call to sumNums
```

we can then examine the memory at the stack pointer with the following command:
```bash
x/32w $esp
```

this will show us the next 32 words of memory starting from the stack pointer. 

if we tried doing just `x/32`, we might get a message like "Cannot access memory at address 0x0" since we are trying to access memory that we don't have permission to access. we include the `$esp` to tell gdb to start at the stack pointer.
