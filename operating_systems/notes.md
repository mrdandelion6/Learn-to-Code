# OS notes

## What is an operating system ?

a very low layer of software that manages hardware resources and provides a set of services for application software. in other words, a very convennient abstract for hardware access.

they also provided restricted access to hardware resources like disks etc.

in older days, there was no OS. this worked because the hardware was very simple but nowadays it's very unfeasible because of the complexity of hardware.

### Main goals of an operating system
- **PRIMARY REASON: convenience** - make the computer easier to use
- **SECONDARY REASON: efficiency** - make the computer run faster
  - note that you have limited resources, you need something to manage which process gets what resources and when

these two goals can often conflict with each other. for example, a more secure system might be less convenient to use.

### Roles of an OS
- **being a virtual machine**: extends and simplifices interface to physical hardware as mentioned before. also provides a library of functions accessible through an API.
  
- **resource manager**: manages resources like CPU, memory, disk, etc. provides an environment 

- **system controller**: controls the execution of programs, and prevents errors and improper use of the computer. protects against unauthorized access.


### Main components of an operating system
- memory management
- synchronization
- inter-process communication
- scheduling
- exception handling
- file system management
- device drivers
- networking

## How to make OS faster?
**limited direct execution**
- we want to set up CPU so that the the next instruction is fetched from the code of the current process. this is called **direct execution**.

- **how do we limit it?**

**key abstraction**: "the process"
- this includes everything OS needs to know to manage running programs 

## Protection Domains


the OS uses **dual-mode operation** which consists of two modes: a **user mode** and a **kernel mode**, also known as **system mode**.

- **user mode**: the mode in which the user programs run. the user programs can't access hardware directly. they have to go through the OS to access hardware. this is to prevent user programs from messing with the hardware.


### Privileged Instructions/Operations
- setting mode bits
- disabling interrupts
- enabling interrupts
- writing to device registers
- halting cpu
- performing DMA (direct memory access)

all of these are privileged

### What are interrupts?
an interrupt is a hardware signal that causes that CPU to jump to a predefined instruction called the interrupt hanlder. this is used to handle events like I/O completion, hardware errors, etc.

when an interrupt happens,
- CPU goes into kernel mode
- CPU disables interrupts (we can't have a new interrupt occur while we are handling an interrupt)



## Bootstrapping
bootstrapping is the process of starting a computer from a powered-off state. 
- the hardware stores a small program called the **bootstrap loader** in non volaltile memory. this program is executed when the computer is powered on.


## What is a process?
a process is a program in execution. it consists of the following:
- program counter
- stack
- data section

### representation of a process
a process is represented by a **process control block (PCB)**: a data structure that contains information about the process. it includes:
  - process state
  - program counter
  - CPU registers
  - CPU scheduling information
  - memory-management information
  - accounting information
  - I/O status information

## context switch

a context switch is the process of saving the state of a process or thread, so that it can be restored and resume execution at a later point. this is done so that multiple processes can be executed concurrently. 

for example, say we are in process A and we want to switch to process B. we would: 
- we save the hardware registers of process A to the kernel stack
- move to kernal mode
- jump to trap handler which will load the registers of process B from the kernel stack

**handling the trap**:
Call *switch()* routine 
```
switch(A, B)
  save regs(A) to proc-struct(A)
  restore regs(B) from proc-struct(B)
  switch to k-stack(B)
```

and then we return from the trap handler into process B. 