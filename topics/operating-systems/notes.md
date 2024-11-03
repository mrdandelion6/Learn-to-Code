# OS notes

## prerequisites
- C programming
- assembly programming
- light systems programming knowledge

# what is an operating system ?

a very low layer of software that manages hardware resources and provides a set of services for application software. in other words, a very convenient abstraction for hardware access.

they also provided restricted access to hardware resources like disks etc.

in older days, there was no OS. this worked because the hardware was very simple but nowadays it's very unfeasible because of the complexity of hardware.

## main goals of an operating system
- **PRIMARY REASON: convenience** - make the computer easier to use
- **SECONDARY REASON: efficiency** - make the computer run faster
  - note that you have limited resources, you need something to manage which process gets what resources and when

these two goals can often conflict with each other. for example, a more secure system might be less convenient to use.

## roles of an OS
- **being a virtual machine**: extends and simplifices interface to physical hardware as mentioned before. also provides a library of functions accessible through an API.
  
- **resource manager**: manages resources like CPU, memory, disk, etc. provides an environment 

- **system controller**: controls the execution of programs, and prevents errors and improper use of the computer. protects against unauthorized access.


## main components of an operating system
- memory management
- synchronization
- inter-process communication
- scheduling
- exception handling
- file system management
- device drivers
- networking

## how to make OS faster?
**limited direct execution**
- we want to set up CPU so that the the next instruction is fetched from the code of the current process. this is called **direct execution**.

- **how do we limit it?**

**key abstraction**: "the process"
- this includes everything OS needs to know to manage running programs 

# protection domains and CPU modes

CPUs uses **dual-mode operation** which consists of two modes: a **user mode** and a **kernel mode**, also known as **system mode**. these are the primary two modes of operation for the CPU and will be the focus of the next few sections.

- **user mode**: the mode in which the user programs run. the user programs can't access hardware directly. they have to go through the OS to access hardware. this is to prevent user programs from messing with the hardware.

- **kernel mode**: the mode in which the OS runs. the OS can access hardware directly. you have access to privileged instructions and operations.

## privileged instructions/operations
- setting mode bits
- disabling interrupts
- enabling interrupts
- writing to device registers
- halting cpu
- performing DMA (direct memory access)

all of these are privileged

## what are interrupts?
an interrupt is a hardware signal that causes that CPU to jump to a predefined instruction called the interrupt handler. this is used to handle events like I/O completion, hardware errors, etc.

when an interrupt happens,
- CPU goes into kernel mode
- CPU disables interrupts (we can't have a new interrupt occur while we are handling an interrupt)

interrupts can be invoked by the hardware or the software. they signal to the cpu that the device has an event that needs attention. 
- interrupts signal errors or requests that require OS intervention (a system call). often called an exception or a trap.

interrupts cause cpu to jump to a predefined routine which is known as the interrupt handler.

# processes review

we will now briefly review processes and how they work

## bootstrapping
bootstrapping is the process of starting a computer from a powered-off state. 
- the hardware stores a small program called the **bootstrap loader** in non volaltile memory. this program is executed when the computer is powered on.

### volatile vs non-volatile memory
- **volatile memory**: memory that loses its contents when the power is turned off. examples include RAM.
- **non-volatile memory**: memory that retains its contents when the power is turned off. examples include ROM, flash memory, etc. ROM stands for read-only memory.


## what is a process?
a process is a program in execu`tion. each process has its own memory space, its own registers, and its own program counter.

## representation of a process
a process is represented by a **process control block (PCB)**: a data structure that contains information about the process. it includes:
  - process state
  - program counter
  - CPU registers
  - CPU scheduling information
  - memory-management information
  - accounting information
  - I/O status information

# assembly review
quick review of assembly: registers and instructions.

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

we will implement pseudo assembly for the above code.

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

# switching between user and kernel

this is a very important topic to understand. so far we have seen that CPU runs 

recall that the CPU has two modes: user mode and kernel mode as we talked about [here](#protection-domains).

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

## context switch

a context switch is the process of saving the state of a process or thread, so that it can be restored and resume execution at a later point. this is done so that multiple processes can be executed concurrently. 

for example, say we are in process A and we want to switch to process B. we would: 
- we save the hardware registers of process A to the kernel stack
- move to kernel mode
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

### getting into kernel mode.
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
- the kernel also has to verify the arguments that can be passed in registers. 
- the result of the system call is stored in EAX.

### system calls in linux
we name the system calls with a number X, where X is the number of parameters.

for example, in C we have `write()` :
```c
write(int fd, const void *buf, size_t count);
```
we can see that this function has 3 parameters, so in the kernel, we initially call `SYSCALL_DEFINE3` to define the system call. more details below  

### making a system call:
1. the kernel assigns each system call type a system call number
2. kernel initializes a table of function pointers ffor each system call number
3. user process sets up system call number and arguments
4. user process runs **int N** (where N is the system call number), note that **int** is an assembly instruction that generates a software interrupt
5. context switch to kernel mode and invokes kernel's interrupt handler for X 
6. kernel looks up **syscall table** using system call number
7. kernel invokes the corresponding function 
8. kernel returns by running *iret* which is the interrupt return

# threads & processes

## interprocess communication

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

or we can have each user level thread have its own kernel level thread. this is called a **one-to-one** model. we can also have some combination of the two, called a **many-to-many** model.

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

// TODO: add notes on the critical section problem

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


### locks / mutexes

locks are another synchronization primitive. they are similiar to a binary semaphore. the only difference is that locks are "owned" by the thread that acquires them, whereas semaphores are not owned by any thread. so a semaphore can be released by any thread, but a lock can only be released by the thread that acquired it.

we also call locks **mutexes**. this stands for "mutual exclusion".


### deadlock vs starvation
- deadlock: when two or more threads are waiting for each other to release a resource
- starvation: when a thread is waiting indefinitely to enter a critical section


## advanced synchronization issues
we will introduce how synchronization can get complex when we also have conditions to consider.

for example, let us consider the consumer-producer problem. 

### consumer producer problem
recall from our C notes, the consumer producer problem is a classic synchronization problem. mainly, we need to ensure that we are not reading from an empty buffer, and we are not writing to a full buffer. simultaneously, we need to ensure that we are not reading and writing at the same time. let us use our current knowledge of semaphores to solve this problem.

```c


```


### condition variables


### reader writer problem
this problem is similiar to the consumer, producer problem, except readers can read the data concurrently with each other, but writers must have exclusive access to the data.


### monitors

monitors are a high level synchronization primitive that combines locks, condition variables, and a data structure into a single package. monitors are a way to encapsulate shared data and the operations that can be performed on that data. 

for example, we can have a monitor to solve the consumer producer problem.


#### hoare

#### mesa

### implementing a monitor

note that monitors are not part of the C standard library, so we have to implement them ourselves.

let's implement some functions for our monitor:

```c
void add_to_buff(buf_t* b, int val) {
  lock_acquire(b->buflock);
  
  while (b-> nelements == NULL) {
    // this loop blocks so we dont write to a full buffer

    // we use a condition variable to block the thread

    cv_wait(b->not_full, b->buflock);
    // note that b->buflock is released when we wait. this is so that other threads can access the buffer, and possibly signal the condition variable.
  }

  b->data[b->position_index] = val;
  b->position_index = (b->position_index + 1) % b->size;
  b->nelements++;

  cv_signal(b->not_empty); // signal that the buffer is not empty since we added an element
  lock_release(b->buflock);
}

```



#### test and set
the **test and set** instruction is an atomic instruction that sets a register to 1 and returns the previous value of the register. 

# scheduling
- recall that the OS acts as a resource manager for many threads and processes
- the OS treats the processes and threads as the same in linux
- the OS will switch between processes and threads to give the illusion of concurrency

we now focus on how the OS allocates the CPU to processes and threads. this is called **scheduling**.

## processor scheduling
- efficiently schedule processes to increase CPU utilization
- want to maxomize **job throughput** 
- want to overlap I/O and computation

### ready queue
- the OS maintains a **ready queue** of processes that are ready to run
- want to know how OS decides which process to run next from the ready queue

### scheduling policies

lets start with thinking of the simplest policy:
- first come first serve
- let the process run to completion without interruption

consider the following process table:

| process | arrival time | service time |
|---------|--------------|--------------|
| A       | 0            | 3            |
| B       | 2            | 6            |
| C       | 4            | 4            |
| D       | 6            | 5            |
| E       | 8            | 2            |


if we do it like this, we see that processes end up waiting a lot. in total, the processes waits 23 units of time. this give an average wait time of 4.6 units of time.

we can now try another approach, what if we run the process with the shortest service time first (while keeping start times the same)? doing it like this means the processes would execute in the following order:
```
A, B, E, C, D
```
this ends up giving a total wait time of 18 units of time, and an average wait time of 3.6 units of time. however there is a big issue with this kind of scheduling: **starvation**. this is when a process never gets to run. suppose we have a process that has a very long service time, it will never get to run if new short processes keep coming in.

### scheduling goals
- fairness
- avoid starvation
- enforce all scheduling policies
- balance, all parts of the system should be used

#### batch systems
- for batch systems, main goal is to maximize throughput
- this is just like users submit jobs to a batch queue, and the OS runs them in the background
- turnaround time - mnimize the time between submission and completion
- CPU utilization - keep the CPU busy

#### interactive systems
- main goal is to minimize response time
- response time - time between a request and the response
- this contrasts to batch systems where we want to maximize throughput

#### real-time systems
- not about response time or throughput, but about meeting deadlines
- needs to be predictable


## types of CPU scheduling
- long term scheduling
- short term scheduling
- medium term scheduling

#### long term scheduling
- used in batch systems, not common today

#### medium term scheduling
- aka, memory scheduling
- happens infrequently
- decides which processes to swap in and out of memory

#### short term scheduling
- the actual "scheduler"
- runs very frequently
- decides which process to run next
- aka "dispatching"
- the goal is to minimize the turnaround time and maximize CPU utilization


### dispatching
- we now investigate what happens when the OS decides to switch between processes
- select next thread from the ready queue
- save currenetly running thread state (unless the thread is exiting)
- restore state if tge bext thread
  - this is called a **context switch**
  - restore registers, program counter, etc.


### when we schedule

**when a thread blocks**:

now consider when the running thread blocks, for example receives a SIGSETOP or makes a system call. now the OS has to decide what to pick next.

**when a thread is ready**:

when a thread is ready to run, the OS has to decide how to add it to the ready queue.

## types of scheduling
**non-preemptive:**
- once a process starts running, it runs to completion
- good for batch systems
- not good for interactive systems
- our firt come first serve example was non-preemptive

**preemptive:** 
- the OS can stop a process and start another one
- promises to run the process later
- recall our shortest job first example, we can have a preemptive version of this, **shortest time to completion first**

### how xan we estimate expected service time?
- programmer estimate
- historical data
- can be shortest next CPU burst for interactive jobs

## scheduling algorithms

### round robin
- the ready queue is circular
- pre-emptive
- designed for time-sharing systems
- each process gets a time slice called a **quantum**
- we need to choose the quantum size

#### choosing the quantum size
- if quantum -> inf, then its the same as first come first serve
- if quantum -> 0, then we have a lot of context switches
- we want q to be large with respect to the context switch time, but small with respect to the user's point of view so it seems like they are running concurrently
  - we want q >>> context switch time because it will end up being that we just spend all our time context switching

for example recall our table,
| process | arrival time | service time |
|---------|--------------|--------------|
| A       | 0            | 3            |
| B       | 2            | 6            |
| C       | 4            | 4            |
| D       | 6            | 5            |
| E       | 8            | 2            |

if we do time quantums, we could have processes that need more than 1 quantum to complete. this can lead to having a returning process arrive at the same time as a new process. in this case we would need to decide some policy for which process to run next. 

suppose we have a quantum of 2 units of time, and we choose to run new processes first. then we would have the following schedule:
```

```


## priority scheduling
- a priority p is associated with each thread
- highest priority job is selected from ready queue (could be preemptive or non-preemptive)
- enforcing this policy can be difficult
  - a low priority job could starve
  - a low priority task may prevent a high priority task from running by holding a resource

### priority inversion
- a low priority task holds a resource that a high priority task needs
- there is a real example, the Mars Pathfinder mission, where a low priority task held a resource that a high priority task needed. this caused the high priority task to be delayed.

#### mars rover pathfinder bug
- there was a shared information bus
- the bus was held by a low priority task

### multi level queue scheduling
- we can have multiple queues with different priorities
- the queues can all have different scheduling algorithms

for example, suppose we have 3 queues:
- batch processes (FCFS)
- interactive processes (round robin)
- system processes (SJF: shortest job first)

we can assign a priority on the priority queues. the reason for this extra layer of complexity is that it enables us to organize scheduling better. 
- for example, suppose we have *n* priority queues, we can have threads that do not finish their time quantums in the highest priority.

# memory management in OS

## memory hierarchy
- registers (2KB)
- l1 cache (32 - 128KB)
- l2 cache (2 - 4 MB)
- l3 cache (4 - 16 MB) 
- DRAM / main memory (4 - 64 GB)
- disk: SSD, HDD (64 GB - 4 TB)

note the sizes are just rough estimates. varies of course. 

- accessing the first byte in a sequence of memory is slower because you have to position the disk head. 
- for example, in an HDD it takes 100,000 times longer to access the first byte than the next one after that, but for DRAM its only 4 times longer.
- this means on a hard disk, we would want to access the data sequentially because the physical repositioning of the disk head is slow.
- this means the hard disk is good for large sequential reads, but not for random reads.

we want to avoid going to the disk at all costs. but we still need to store all the data somewhere. so the DRAM acts as a cache for the disk.
- performance depends on the efficient use of DRAM
- now we ask, **how can the OS help with this**

the answer is: **virtual memory**

## virtual memory
- only a limited amount of physical memoru
- every active process needs memory, need to provide the illusion of "infinite" memory to each process

**goals**:
- efficiency
- transparency
- protection

### efficiency
- make use of memory wisely

note that,
- some portions of memory are in DRAM
- some are in the disk
- need to transfer the data back and forth between the disk and DRAM

we want to keep stuff in DRAM that we think will be used again.

### transparency
- data moves back and forth between RAM and disk
- programmer shouldnt have to worry about this

we want to create an illusion of having more memory than the size of the DRAM.
- give each process its own view of memory.
  - a large contiguous address space starting at address 0. this simplifies memory allocation
- decouple the data 

### fixed partitioning
- each process gets a fixed partition to use in memory
- OS occupies a separate partition
- each process is granted its own partition

cons of this:
- if we assign the same block size to each process, we might waste memory where some processes don't use all of their memory. this is called **internal fragmentation**.
- if program needs more memory, the programmer has to deal with that (**overlays**)
- number of partitions is limited, this limits number of possible active processes

what if we try unequal sized partitions?
- diversify the sizes of the partitions
- have some policy where we assign each process to a queue corresponding to a partition size
- we try to get the smallest partition that fits the process

issue is that the processes may end up fighting for the same partition when there are multiple processes that fit the same partition size, even tho they could fit in a larger partition.

### dynamic partitioning
- we can assign the processes regions of memory as they request it

cons
- causes **external fragmentation**:
  - when we have a lot of small holes in memory that are too small to fit a process
  - a solution to this is **compaction** where we move all the processes to one end of memory and free up the other end
  - however, this is expensive because we have to update all the pointers to the memory
  - also requires process to be relocatable, and now the process has to be aware of this
- need to know the maximum size of a process in advance
  - can we know this?
  - sort of..
  

### virtual memory!
- the solution to the above problems
- we use **paging** instead


## paging

- page tables map virtual memory to physical memory
- virtual memory is essentially an "abstraction" that the program sees
- the program thinks it has a large contiguous address space starting at 0
- the page table maps the virtual memory to physical memory

## copy on write
- TODO: add notes on copy on write

## page tables
- the page table is a data structure that maps virtual memory to physical memory
- the page table is stored in memory
- the page table is indexed by the virtual address
- the page table contains the physical address

### how to translate virtual memory to physical memory
- for now, we will assume that we can fit the virtual address space in physical memory contiguously (even though we can't and need to use paging to split it up)
- naturally, programmers dont know what physical memory is available, need to translate the virtual memory to physical memory. 
- need to manage many things for memory like relocation.

### address binding
programs must be in memory to be executed!
- program binary is laoded into ap rocess' address space- needs memory for code (instructions) and data
- addresses in program must be translated to real physical addresses
- programmers use symbolic addresses (variable names), to refer to memory locations. this is a very fundamental idea!!

now we ask, when do "bind symbolic addresses to physical addresses"?
- option 1: **compile time**:
  - need to know what memory the process wil use during compile time
  - we call this code, *absolute code* since binary contains real addresses
  - this is not very flexible as no relocation is possible.
  old MS-DOS programs use this


- option 2: **load time**:
  - compiler translates symbolic addresses to **logical addresses** that are **relocatable**
  - linker translates addresses from obj files to logical, absolute addresses within the binary executable
  - the issue with this is that the binary executables produced would not be relocatable. this is because the addresses are hardcoded into the binary executable.
  - the problem with this is then we can't run multiple instances of the same program at the same time and we can't guarantee that the memory will be available at the same address every time.

- option 3: **execution time**:
  - the OS loads the program into memory and then translates the logical addresses to physical addresses
  - this is the most flexible option
  - the OS can move the program around in memory as it sees fit
  - the OS can also run multiple instances of the same program at the same time
  - the executable simply stores virtual addresses starting at 0
  - when a program starts to run the OS decides where in physical memory to place its address

here is the translation process for execution time binding:
- step 1: set base register, i.e, the starting address of the program in physical memory
- step 2: physical address can be translated by: physical address =  base register + virtual address

this way, the instructions in teh executable do NOT need to be modified. note that we need a **bound register**, so we don't want the program to access memory outside of its address space.

now recall our initial assumption: that we can fit the entire virtual address space in physical memory. this is not true, so we need to use **paging**. we cannot have **contiguous** memory.

recall we touched on this before: as processes come and go we will have "holes" in memory. i.e, places where nothing can fit because the memory is too small. this is called **external fragmentation**.

recall **compaction**: we move all the processes to one end of memory and free up the other end. this is expensive because we have to update all the pointers to the memory. this is why we use **paging** instead.

### placement algorithms
placement algorithms are used to decide where to place a process in memory.
- best fit
- first fit
- worst fit
- next fit

### relocation
- placing addresses in contiguous blocks of memory is our challenge
- we can't use our simple translation process anymore, we can't do physical address = base register + virtual address.
- **NEED TO USE PAGING**

# paging
- logically partition physical memory into equal fixed size blocks called **frames**
- divide processes' memoppry into chunks of the same size called **pages**
- any page can be assigned to any frames!!
  - external fragmentation is eliminated
  - internal fragmentation is at most a part of one page per process
- processible page frame sizes are restricted to powers of 2

paging needs **page tables** to map virtual memory to physical memory. no longer using a base register address. 

## page tables
- these are stored in OS memory (recall the OS section at the top of memory diagrams)
- virtual addresses now interpreted as: **page number + page offset**

### translating with page tables
- suppose addresses are 17 bits and pages are 1024 bytes, just as an example.
  - least significant 10 bits of address would need to provide the offset, because each page is 1024 bytes, we need 2^10 bits to map to each byte in the page.
  - most significant 6 bits provide page number
  - the maximum number of pages is then 2^6 = 64 pages

now we can calculate page numbers and offsets for a given address by simply using bit shift operations.
- for example, to get the page number, we can do: `address >> 10` (this shifts the address 10 bits to the right)
- to get the offset, we can do: `address & 0x3FF` (this zeroes the most significant 6 bits)

now consider 32-bit virtual addreses and 4096 byte pages. we would need 12 bits for the offset leaving 20 bits for the page number. this means we can have 2^20 pages. we sometimes refer to the virtual page number as **VPN.**

## page table entries
here is an example of a page table entry:
```
--------------------------------
| M | R | V | Prot | Frame #   |
--------------------------------
```
note that this varies entirely based on the architecture of the system.

- M: modified bit
  - set to 1 if the page has been modified
  - we want to keep track of this because we don't want to write to the disk if the page hasn't been modified
- R: reference bit
  - set to 1 if the page has been referenced (accessed)
  - we want to keep track of this because we want to know which pages are being used
- V: valid bit
  - set to 1 if the page is in memory
  - set to 0 if the page is on disk, we call this a **page fault**
  - if 0, need to load the page from disk (page fault)
- Prot: protection bits
  - read, write, execute permissions
  - similiar to file permissions but different
  - for example, want to protect pages that correspond to OS memory
- Frame #: frame number
  - the physical frame number that the page is in
  - if the page is not in memory, this is the frame number that the page will be loaded into

### where are pages tables stored?
- too big to fit into MMU (memory management unit)
- stored in protected OS memory

#### page limitations
- biggest limitation is space

suppose we need the following:
- need one PTE per page
- 32 bit virtual addresses with 4KB pages
- suppose we need 4 bytes per PTE
- then we need 4MB / page table
- then for 100 processes, need 400 MB just for page tables, which is a lot of memory
- now for **modern processors** that have 64 bits.. ends up being 16 petabytes of memory just for page tables

idea: increase page size
- this reduces the number of pages, and thus the number of PTEs
- however, this increases internal fragmentation
- suppose a process needs 1 byte, but the page size is 4KB, then we have 4KB - 1 byte of internal fragmentation

**solution**: use **multilevel page tables** 

- multilevel page tables (aka hierachical page tables) are a way to reduce the size of the page table
- instead of having a single large page table, the address space is divided into multiple levels of page tables

### multilevel page tables
- the address space is divided into multiple levels of page tables
- the top level page table is stored in memory, this is the **page directory**
- the page directory contains pointers to the next level of page tables
- the next level of page tables contains pointers to the actual frames in memory
- this is a way to reduce the size of the page table

however multilevel page tables can become inefficient if we have to traverse multiple levels of page tables to get to the actual frame in memory. this is why we use a **translation lookaside buffer (TLB)**.

## TLB
- the TLB is a cache for the page table
- the TLB is a small, fast memory that stores the most recently used page table entries
- the TLB is indexed by the virtual page number

so this is how address are read,

### read access:
- CPU reads the virtual address
- TLB does a lookup using the **page number** of the address
- common cose: TLB hit
  - page number matches
  - returns a page table entry for the mapping to the address
  - TLB validates that the **PTE protection** allows reads
  - PTE specifies the physical frame which holds the page
  - MMU (memory management unit) combines physical address and offset to get the physical address
  - MMU reads from that physical address and returns a value to the CPU
- uncommon case: TLB miss. can have either one of the following cases:
  - TLB does not have a PTE mapping for the page number
  - PTE exists, but the memory access violates PTE protection bits


### PTE protection 
PTES have protection bits that specify the permissions for the page. for example. this is very similiar to linux file permissions.
- read, write, execute permissions

### TLB misses
lets examine the TLB miss case. we will consider what happens when the TLB does not have a PTE mapping for the page number first.

if TLB does not have a PTE mapping for the page number. then we have 2 possibilities:
- MMU loads PTE into TLB from the in-memory page table


# page policy decisions
- page tables, MMU, aTLB, etc. are mechanisms that make virtual memory possible
- now we'll look at some policy decisions that the OS has to make

*policies to consider*
- demand paging (fetch policy)
- page replacement
- page fault handling

## demand paging
this is the OS' perspective for demand paging:
- pages are evicted to disk when memory is full
- pages loaded from disk when referenced again
- references to evicted pages causes a TLB miss
  - if PTE was invalid, we have a page fault.

we say demand paging is when we load pages from disk to memory on demand as needed. this is a fetch policy.

### demand paging process
- demand paging is also used when a process first starts up
- when a process is created it has
  - a brand new page table with all valid bits off
  - no pages in memory
- when a process starts executing
  - instructions fault on code and data pages
  - faulting stops when all necessary code and data pages are in memory
  - only code and data needed by ap rocess needs to loaded 

### costs of demand paging
- on demand paging is expensive
- we would have to load pages from disk to memory every time we have a page fault, i.e, want to access a page that is not in memory

alternatively, we can use **pre-paging**. for example with on demand paging we would have something like the following:
```
load  A
... fetch A
run
load  B
... fetch B
run
```

with pre-paging we would have something like the following:
```
load  A
... fetch A and B
run
load  B
run
```

the issue with pre-paging is that we may end up loading pages that we don't need. this is called **thrashing**.

## placement policy
- in paging s ystems, memory management hardware can translate to any virtual-to-physical mapping equally well

then we ask why would we prefer some mappings over others?
- NUMA (non-uniform memory access) systems
  - any processor can access entire memory, but local memory is faster (L1, L2, L3 cache)

that being said, the placement policy has a much greater impact on performance than the replacement policy.

## replacement policy
- when a page fault opccurs, the OS loads the faulted page from disk into memory
- need to choose a page to evict from memory to make room for the new page

### evicting the best page
- goal  of replacement algorithm is to minimize the number of page faults
- replacement algos are evaluated on a *reference string* of memory accesses 

### optimal page replacement
in theory if we knew the future, we could choose the page that will be used the farthest in the future. this is called the **optimal page replacement** algorithm. 

we call this the **Belady's optimal algorithm**. this is the best possible algorithm because it has the lowest number of page faults.

but in reality, we can't know the future. so belady's algorithm is just an ideal to aim for.

generally, we have two types of page misses:
- cold misses: when a page is accessed for the first time. this is unavoidable.
- capacity misses: when a page is accessed again after being evicted. this is avoidable. caused by limited memory.

a practical algorithm we might think of immediately is FIFO:
- FIFO: we evict the page that has been in memory the longest
  - this might be good because we "expect" that recently accessed pages may be accessed again
  - but this is not always the case, this is an assumption

FIFO suffers from "belady's anomaly":
- increasing the number of frames can increase the number of page faults

### LRU
- LRU: least recently used
- this is a sort of modification of FIFO
- we bump a page to the front of the queue when it is accessed
- we evict pages that have not been used for the longest time 

LRU is known as a **stack algorithm**. we can implement LRU with a stack. we can also implement LRU with a **circular queue**.

stack algos do not exhibit belady's anomaly. this is because the stack is always increasing in size, so we always have the most recently used pages in memory.

### implementing LRUs
- how can we keep track of the order of pages?
- if we store floats for time stamps, this will take a lot of space in memory
- we could also keep pages in a *stack*, but this is expensive because we have to move all the pages every time we access a page.

in other words, implementing LRU exactly is expensive to implement, so we use approximations. LRU approximates belady's algo, and we approximate LRU.

### approximating LRU
- use the PTE reference bit
- basic idea
  - initially all R bits are zero; as processes execute bits are set to 1 for pages thatr are used
  - periodically examine the R bits, we do not know the *order* of use, but we know pages that were (or were not) used
- additional reference bits algorithm:
  - keep a counter for each page
  - periodically shift the counter right by 1 bit
  - set the most significant bit to the value of the reference bit
  - the page with the smallest counter is the least recently used

however, we don't even need the additional reference bits algorithm. we can use the following:

### second chance algorithm
- LRU-like algorithm
- when a page is accessed
  - if ref bit 0 is, replace the page
  - if ref bit is 1, clear ref bit 


### clock algorithm
- clock algorithm is a modification of the second chance algorithm
- replace page that is "old enough"
- arrange all of physical page frames in a big circle
- when we need to evict a page we look at a page in the circle
- if the ref bit is 0, we replace the page. the new page is inserted in the circle where the old page was and the ref bit is set to 1
- if the ref bit is 1, we clear the ref bit and move to the next page in the circle
- note that the ref bit is a bit that is set to 1 when the page is accessed

this is a really simple yet effective algorithm.

## page buffering
- so far we implicitly assumed that the replacement algo is run and a victim page is selected when a new a page needs to be brought in
- most of these algos are too csotly to run on every page fault we get

so what we can do is use a *paging daemon*,
- maintain a pool of free pages (free page list): this is a list of pages that are not being used
- run replacement algo when a pool becomes too small, we say this is a "low water mark". free enough pages to at once replenish the pool, i.e, get a "high water mark"
- this uses a dedicated kenrel thread called the *paging daemon*
- on a page fault, grab a frame from the free list
- frames on the free list still hold previous contents, can be rescued if virtual page is referenced before reassignment

## thrashing
- thrashing is when the system spends most of its time swapping pages in and out of memory
- possible causes:
  - too many processes
  - too many pages per process
  - too small a page size
  - too small a memory size

- possible solutions:
  - reduce the number of processes
  - reduce the number of pages per process
  - increase the page size
  - increase the memory size

## CPU utilization and paging
- CPU utilization is the percentage of time the CPU is busy
- if we have mostly I/O heavy processes, CPU util is low
- if we have compute intesive processes, CPU util is high


## addressing page tables
- where should we store these?
- we before thought of storing the page tables in physical memory 
- what if we stored them in virtual memory?
- we would then need page tables for the page tables. so this is not really a good idea.

## swap space
- swap space is a region of the disk that is used to store pages that are not in memory
- we can use swap space to store pages that are not in memory

how do we store swap?
- option 1: having a raw disk partition
  - pros: fast
  - cons: not flexible
- option 2: using ordinary large files
  - pros: flexible
  - cons: slow
