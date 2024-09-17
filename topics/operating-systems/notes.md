# OS notes

## What is an operating system ?

a very low layer of software that manages hardware resources and provides a set of services for application software. in other words, a very convennient abstract for hardware access.

they also provided restricted access to hardware resources like disks etc.

in older days, there was no OS. this worked because the hardware was very simple but nowadays it's very unfeasible because of the complexity of hardware.

### Main goals of an operating system
- **PRIMARY REASON: convenience** - make the computer easier to use
- 
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
an interrupt is a hardware signal that causes that CPU to jump to a predefined instruction called the interrupt handler. this is used to handle events like I/O completion, hardware errors, etc.

when an interrupt happens,
- CPU goes into kernel mode
- CPU disables interrupts (we can't have a new interrupt occur while we are handling an interrupt)

interrupts can be invoked by the hardware or the software. they signal to the cpu that the device has an event that needs attention. 
- interrupts signal errors or requests off OS intervention (a system call). often called an exception or a trap.

interrupts cause cpu to jump to a predefined routine which is known as the interrupt handler.


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


## Threads & Processes

### requesting OS Services

- operating system and user programs are isolated from each other
- but OS provides service to user programs
- so the question is how do they communicate?

#### user space
- contains the user process

#### kernel space
OS controls: memory management, scheduling, file system, I/O

- the answer is: **system calls**

recall some system calls in C, like `open()`, `read()`, `write()`, etc. these are all system calls.

### assembly review

consider the following code in C:
```c
int pinkbunny(int x, int y) {
  int i = 10;
  return x + y + i;
}

int main() {
  int r = 2;
  int q = 3;
  int result = pinkbunny(r, q);
  printf("result is %d\n", result);
  return 0;
}

```

we will implement pseduo assembly for the above code.

the first thing we do is save the caller's registers to the stack. such as:
- eax
- ecx
- edx

these are the registers that the caller expects to be preserved. 

```assembly
pinkbunny:
  addi sp sp -8
  sw t0 0(sp)
  sw t1 4(sp)

  # the actual code
  addi t0 x0 10
  add a0 0(sp) 4(sp)
  addi a0 a0 t0 
  # a0 is where we're expecting to return the result

  addi sp sp 8
  jr ra

# main code starts here
  addi t0 x0 2
  addi t1 x0 3
  jal ra pinkbunny
  # print a0 (it contains return value)
```

## boundary crossings

### getting into kernal mode.
- we need an explicit system call. 
- need a hardware interrupt
- software or trap execution
  - recall from our assembly examples, we need to store the return address
  - need to store the registers of the caller

this is a "context switch". 

### enforcing restrictions
we don't want the user to be able to do everything. we want to restrict the user's access to the hardware.

#### user mode
- user mode: user programs run in this mode. they can't access hardware directly. they have to go through the OS to access hardware.

#### system mode
- system mode: the OS runs in this mode. it can access hardware directly.
- also known as kernel mode

### determining what handler to use

the OS determines what handler to use because the "reason" is stored in a register and is used to invoke a **handler**. 

in `notes.c` for C, you can see we have similiar notes on **signal handlers**, but these are not the same thing. they are however very similiar. 

## viewing system call interface

- user program calls C library function with arguments
- C library functioin passes arguments to the OS
  - includes a system call identifier

### walking through an example

- we start in user mode, where we have some code to be executed.
- we have a specific system call **int 0x80** that we use to switch to kernel mode.
- the int stands for interrupt.

the **0x80** is the interrupt number. this is the number that the OS uses to determine what system call to execute. 

#### verifying arguments
- ther kernel also has to verify the arguments that can be passed in registers. 
- the result of the system call is stored in EAX.

### system calls in linux
we name the system calls with a number X, where X is the number of parameters.

for example, in C we have `write()`:
```c
write(int fd, const void *buf, size_t count);
```
we can see that this function has 3 parameters, so in the kernal it is called `SYSCALL_DEFINE3`.  

#### making a system call:
1. the kernel assigns each system call type a system call number
2. kernel initializes a table of function pointers ffor each system call number
3. user process sets up system call number and arguments
4. user process runs int N (where N is the system call number)
5. context switch to kernel mode and invokes kernel's interrupt handler for X 
6. kernel looks up **syscall table** using system call number
7. kernel invokes the corresponding function 
8. kernel returns by running *iret* which is the interrupt return

### interprocess communication

recall forking from our C notes. this is an example of interprocess communication.

- **fork()** creates a new process by duplicating the calling process. this actually ends up being very inefficient because it duplicates the entire process, and this is very expensive.

### threads
if we want to make a parallel program, we can use **threads**. threads are a lightweight process. 
- threads can solve a single problem concurrently and can easily share code, heap, and global variables.

note that threads are part of the same process, so they all have the same PID. each thread however, has its own unique TID: thread ID.

#### what exactly is a thread?

a thread is a is a single control flow through a program
- a control flow is a sequence of instructions that are executed sequentially

we say a p rogram with multiple control flows is *multi-threaded*.

note that the OS must interact with multiple running programs, so it is naturally multi-threaded.

this gives us a new memory diagram:

- stack (t1)
- guard region
- stack (t2)
- guard region
- stack (t3)
- guard region

#empty space

- heap
- static data
- text/code

we now have guard regions between each stack. this is to prevent one stack from overwriting another stack. we want to have a separate stack for each thread.

this design allows for very cheap concurrency.

### kernel level threeads

- modern OS' have taken the execution aspect of a process and separate it into thread asbtract

- the OS now manages threads and processes..

  - all thread operations are done in the kernel
  - the OS schedules all of th threads in the system

### kernel threads limitations
- kernel level threads make concurrency cheap than processes
- however, for fine-grained concurrency, kernel threads are too heavy. too much overhead from context switching.

for "fine-grained" we need even cheaper threads, which is where **user-level threads** come in.

### user-level threads

to  make threads cheap and fast, need to be implemented at user level
- kernel threads are managed by OS
- user threads are managed entirely by the run time system

user level threads are smalelr and faster:
- simply represented by a PC, registers, stack, and a small thread control block (TCB)

this allows creating a new threading, switching between threads, and sychnronizing threads to be done via **procedure call**, i.e., no kernel involvment.

### user-level threads limitations

user level threads are not a perfect solution, there is a trade off.

- user level threads are not visible to the kernel
- consequently, the OS can make poor decisions:
  - scheduling a process with only IDLE threads
  - blocking a process whose thread intitated an I/O, even though the process has other threads that could run etc.

basically the OS just doesnt really know whats going on with user level threads.

solving this requires communication between user level and OS. i.e., system calls.


### hybrid threads

another possibility is to use  both kernel and user level threads
- can associate a user level thread with a a kernel-level thread.

we can have all the user level threads in a process share the same kernel level thread. this is called a **many-to-one** model.

or we can have each user level thread have its own kernel level thread. this is called a **one-to-one** model.

we can also have some combination of the two, called a **many-to-many** model.

### thread libraries

a standardized API for creating and managing threads is the POSIX thread library, or **pthread**.

- it specifies the interface, but not the implementation.

excellent tutorial: https://computing.llnl.gov/tutorials/pthreads/


# synchronization

in  this section we will be discussing synchronization, locks, and semaphores.

## why do we need synchronization?
- all boils down to scheduling
note that we have:
- multiple threads/processes that need to run
- some mechanism to switch betweewn them, i.e, context switches.

so we need some policy for choosing the next process to run. 

- this policy may be preemptive: OS stops execution for a process with the promise that it will be executed later

### two main uses of synchronization

#### 1. enforcing a single use of a shared resource
- called the critical section problem

### critical section problem

refers to when we have multiple threads that are accessing shared data. we need to ensure that only one thread can access the shared data at a time.

recall, when threads access data at the same time, this can lead to **racing**: when the output of a program depends on the order of execution.

we want to ensure that only one thread can access the shared data at a time. even for stuff like printing to a terminal. the order of the outputs may be different for different runs, but the output shouldn't be mixed. example:
```bash
HelloWord
WorldHello
```
these are fine, but we don't want:
```bash
HWoerllod
```
that is, we don't want the threads the write the console concurrently.

#### 2. control order of thread execution
- e.g) parent waits for the child to finish 

now we look at some examples for critical section problem.

thread A
```
money = getMoney()
addMoney(100)
```

thread B
```
```

### mutual exclusion
we use this to prevent multiple threads from accessing shared data at the same time.

given:
- a set of n threads, T1, T2, ..., Tn
- a set of shared resources between threads
- a segment of code which accessing shared resources

we want to ensure:
- only one thread can execute in the critical section at a time
- all other threads are forced to wait on entry 
- when a thread leaves teh CS (critical section) another can enter


the idea is that we each thread needs permission to enter a CS, in it's **entry** section. when a thread is done with the CS, it exits the CS in the **exit** section.

threads that are not in the CS, entry, or exit sections are in the **remainder** section.

### critical section requirements
so a breakdown of the requirements of the critical section:
1. mutual exclusion
2. progress:
- only threads not in the reamainder section can influence the hcoiceo f which thread enters next, and the choice cannot be postponed indefinitely.
3. bounded waiting, i.e, no starvation:
- there is a limit to how long a thread needs to wait before entering CS. no thread is "starved" indefinitely.

let us take a look at some solutions to the critical section problem and see how whether they satisfy these requirements. 

...

#### atomic
all of the above solutions are "atomic". this means that once they start, they will finish without interruption. either that or they will not start at all.

## syncrhonication primitives
some more solutions to the critical section problem:
- semaphores
- locks
- condition variables
- monitors

### semaphores

semaphores are an ADT that provideds synch.

they consist of:
- an integer counter variable accessed only through 2 atomic operations
- the atomic operation wait - decrement the counter and block until sempahore is free
- the atomic operation signal - increment the counter and unblock a waiting thread
- a queue of waiting threads


### locks

locks are another synchronization primitive. they are similiar to a binary semaphore.  

#### test and set
the **test and set** instruction is an atomic instruction that sets a register to 1 and returns the previous value of the register. 