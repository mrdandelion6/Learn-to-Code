# Cybersecurity

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

we can also disassemble the main function with the following command:

```bash
(gdb) disassemble main
```

this will show us the assembly code for the main function. 

we can also see all the information about the registers with the following command:

```bash
(gdb) info registers
```

for this to work, we need to have executed some code (for example, we we set a breakpoint before).

note that we see many different register names like "ebp, esp, eip" or "rbp, rsp, rip". the "e" stands for "extended" and the "r" stands for "register". you might see "r" on a 64-bit system and "e" on a 32-bit system.

we will list what these are for in the next section.

## x86-64 registers

### general purpose registers

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

rbp: base pointer
- points to the base of the stack frame.

rsp: stack pointer
- points to the top of the stack

rip: instruction pointer
- points to the next instruction to be executed


and for the 32-bit system it is the same, but with an "e" instead of an "r". for example, eax instead of rax.


## buffer overruns

buffer overruns are a common security vulnerability in C programs. they occur when a program writes more data to a buffer than it can hold. this can cause the program to crash, or worse, allow an attacker to execute arbitrary code on the system.

see the c program in `code_examples/buffer_overun.c`

```c

```