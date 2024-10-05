    # x86 notes

welcome to my notes on x86 assembly language. this is a work in progress, so please bear with the emptiness.

# memory

in order to understand x86 assembly language, it is important to understand how memory works in a computer. we won't do a deep dive into it but you must understand that each process has its own memory space, which is divided into several segments. you may have often heard of a "memory table" or "memory map" which shows how memory is divided into different segments. here is a standard memory table for a process:

```
------------------------ higher memory
| kernel space         |
|----------------------|
| stack                |
| (grows downwards)    |
|----------------------| <- stack pointer (esp)
|                      |
|----------------------|
| heap                 |
| (grows upwards)      |
|----------------------|
| uninitialized data   |
| (bss)                |
|----------------------|
| initialized data     |
| (data)               |
|----------------------|
| text/code            |
| (read-only)          |<- instruction pointer (eip) aka program counter
|----------------------|
| unmapped memory      |
------------------------ 0x00000000 (lower memory)
```

each process has its own memory space such as the one shown above. spoiler, this memory is actually **virtual memory** which is managed by the operating system. if you want to learn more about this read my [operating system notes](../../topics/operating-systems/notes.md). but for our purposes, we can think of this as the memory space of a process. 

### kernel space
- this is the memory space used by the operating system kernel. it is protected from user processes, and is used to store the kernel code and data structures.
- you might wonder, "why does each process have its own kernel space?" well, even though the operating system kernel manages all processes, having a separate kernel space for each process acts as a sort of unique interface for each process to interact with the kernel. this is important for security and stability reasons.
- attempting to access kernel space from user space will result in a segmentation fault.

# registers

registers are small, fast storage locations in the cpu that are used to store data that the cpu is currently working with. they are the lowest level of memory storage in the cpu, and are used to store data that the cpu is currently working with. the cpu uses these registers to perform arithmetic operations, move data around, and more.

## general purpose registers

x86 has 8 general purpose registers, each of which is 32 bits wide. they are:
1. **eax** (accumulator register): used for arithmetic operations and function return values.
2. **ebx** (base register): often used as a pointer to data in the data segment.
3. **ecx** (counter register): used for loop counters and string operations.
4. **edx** (data register): used for i/o operations and arithmetic operations.
5. **esi** (source index): used for string and array operations.
6. **edi** (destination index): used for string and array operations.
7. **ebp** (base pointer): used to point to the base of the stack frame.
8. **esp** (stack pointer): points to the top of the stack.

note that in 16-bit mode, the registers are 16 bits wide, and are named ax, bx, cx, dx, si, di, bp, and sp.

similarly, in 64-bit mode, the registers are 64 bits wide, and are named rax, rbx, rcx, rdx, rsi, rdi, rbp, and rsp.

modern machines are typically 64-bit, but we will be using the 32-bit registers in this guide. furthermore, in 64-bit mode there are 8 additional general purpose registers (r8-r15), but we will start with the 32-bit registers for simplicity.

the registers are the lowest level of memory storage in the cpu, and are used to store data that the cpu is currently working with. the cpu uses these registers to perform arithmetic operations, move data around, and more.

## xmm registers

the xmm registers are part of the **SSE** (streaming simd extensions) instruction set, which is used for vector operations. this instruction set is designed to accelerate data processing by enabling **SIMD**: single instruction, multiple data operations. this means that a single instruction can operate on multiple data elements simultaneously, in parallel. 

the xmm registers are used to improve performance in various computational tasks by allowing multiple data elements to be processed simultaneously. each xmm register is 128 bits wide. modern cpu's have 16 xmm registers, xmm0-xmm15 in 64-bit mode and xmm0-xmm7 in 32-bit mode. these registers can hold different kinds of **packed data**:
- 16 8-bit integers
- 8 16-bit integers
- 4 32-bit integers or single precision floating point numbers (float)
- 2 64-bit integers or double precision floating point numbers (double)

note that "single precision" refers to the ieee 754 standard for floating point numbers, which uses 32 bits to represent a floating point number, and "double precision" uses 64 bits. so remember, the key benefit of xmm is to enable parallel processing of multiple data elements. this is particularly useful in graphics processing, scientific computing, and other applications that require high performance.

this may seem like one small thing to remember, but it's actually very important in a lot of different contexts. here are just a few. you don't have to read all of this, but the point is that the xmm registers are very important for performance in a lot of different applications.
- **graphics processing**: when you're rendering a 3d scene, you need to perform a lot of calculations on a lot of data points (vertices, pixels, etc.) in parallel. the xmm registers allow you to do this efficiently.
- **scientific computing**: when you're running simulations or doing other kinds of scientific computing, you often need to perform the same operation on a large number of data points. the xmm registers allow you to do this efficiently.
- **machine learning**: when you're training a machine learning model, you often need to perform the same operation on a large number of data points. the xmm registers allow you to do this efficiently.
- **video encoding/decoding**: when you're encoding or decoding video, you often need to perform the same operation on a large number of data points. the xmm registers allow you to do this efficiently.
- **audio processing**: when you're processing audio data, you often need to perform the same operation on a large number of data points. the xmm registers allow you to do this efficiently.
- **compression/decompression**: when you're compressing or decompressing data, you often need to perform the same operation on a large number of data points. the xmm registers allow you to do this efficiently.
- **cryptography**: when you're encrypting or decrypting data, you often need to perform the same operation on a large number of data points. the xmm registers allow you to do this efficiently.

# instructions

instructions are the basic building blocks of x86 assembly language programs. they tell the cpu what to do, and how to do it. there are many different types of instructions, but they can be broadly categorized into the following groups:
- **data movement instructions**: these instructions move data between memory and registers, or between registers.
- **arithmetic instructions**: these instructions perform arithmetic operations on data in registers.
- **logical instructions**: these instructions perform logical operations on data in registers.
- **control flow instructions**: these instructions change the flow of control in a program, by jumping to a different part of the program, or by calling a function.

there are many other types of instructions as well, these are just some common ones. we will now look at some examples of each type of instruction.

**arithemetic instructions**

```assembly
mov eax, 10 ; move the value 10 into the eax register
add eax, 5 ; add 5 to the value in the eax register
sub eax, 3 ; subtract 3 from the value in the eax register
mul eax, 2 ; multiply the value in the eax register by 2
div eax, 4 ; divide the value in the eax register by 4
```

note that `;` is used to indicate a comment in assembly language. comments are ignored by the assembler, and are used to explain what the code is doing.

## specific instructions

a quick and dirty list of some common instructions. this is not exhaustive, but it should give you a good starting point.

**mov**
- moves data from one location to another
```assembly
mov eax, 10 ; move the value 10 into the eax register
```

**add**
- adds two values together
```assembly
add eax, ebx ; eax = eax + ebx
add eax, 0FH ; eax = eax + 0FH
```
note that `0FH` is a hexadecimal number, `0FH` = `15` in decimal. the `0F` gives 15, and the `H` indicates that it is a hexadecimal number.

**sub**
- subtracts one value from another
```assembly
sub eax, ebx ; eax = eax - ebx
sub eax, -0FH ; eax = eax - (-0FH)
```
note that `-0FH` is a negative hexadecimal number, `-0FH` = `-15` in decimal. the `-` indicates that it is a negative number.

**pxor**
- performs a bitwise xor operation on two packed data elements
```assembly
pxor xmm0, xmm1 ; xmm0 = xmm0 ^ xmm1
```

**jmp**
- jumps to a different part of the program
```assembly
jmp label ; jump to the label
```

**call**
- calls a function
```assembly
call function ; call the function
```

**ret**
- returns from a function
```assembly
ret ; return from the function
```

**movdqa**
- moves 128 bit aligned data from one register to another or from memory to a register
```assembly
movdqa xmm1, [eax] ; move 128 bits of data from the memory location pointed to by eax into xmm1
```

**pcmpeqb**
- compares two packed data elements for equality
- stands for "packed compare equal byte"
```assembly
pcmpeqb xmm0, xmm1 ; compare xmm0 and xmm1 for equality
```
note that each `xmm` register holds 16 bytes. if we compare `xmm0` and `xmm1` for equality, we compare each byte in `xmm0` with the corresponding byte in `xmm1`. if the i'th byte is equal, we set xmm0[i] to 0xFF, otherwise we set xmm0[i] to 0x00.

for example, consider the following values in `xmm0` and `xmm1`:
```assembly
xmm0 = 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F
xmm1 = 00 01 02 10 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F

pcmpeqb xmm0, xmm1 ; compare xmm0 and xmm1 for equality
```
after the comparison, `xmm0` will contain:
```assembly
FF FF FF 00 FF FF FF FF FF FF FF FF FF FF FF FF FF
```
this is because all bytes are equal except for the 3rd byte (with first byte being zero'th).