# PARALLEL PROGRAMMING

## why learn parallel programming?

parallel programming s very useful in many fields for optimization.

## implicit parallelism in CPU architectures

we have some big questions to consider:
- how to effectively use a higher transistor count
- how to mitigate the memory speed gap (hierarchy of memories)

# INSTRUCTION LEVEL PARALLELISM (ILP)
in this section we will focus on parallelism at the instruction level. i.e., how instructions themselves can be parallelized in the CPU. 

## multiple instruction execution
we will be considering 4 ideas for executing multiple instructions
1. pipelining
2. superscalar execution
3. out-of-order execution
4. very long instruction word (VLIW) processors


## pipelining
recall that an instruction involves multiple micro-actions and stages, for example:
- F: fetch
- D: decode
- E: execute
- W: write back

before, instructions would be instructed one after the other, but now we can have multiple instructions in different stages at the same time. the concept is that while one instruction is being fetched, another is being decoded, and another is being executed, and another is being written back, we can have these all happening concurrently.

### data dependencies

something we need to consider when trying to execute multiple instructions at the same time is data dependencies. data dependencies are when one instruction depends on the result of another instruction.

recall, sometimes we will need stalling, and sometimes we can use forwarding to avoid stalling if any data dependencies are present.

for example, if we have the following assembly code:
```assembly

add R3, R1, R2
mul R5, R4, R3
sub R7, R5, R3
and R9, R7, R8 
```

note that the second instruction depends on the first instruction, etc.

in case you forgot assembly (like me), here's a quick refresher on the above:
```
add A B C
```
means
```
A = B + C
```
so we store the sum of B and C in A.

when doing this, we have the following steps:
1. fetch the instruction
   - this is where we get the instruction from memory
   - by this we mean
2. decode the instruction
 -  

### branch predictions

we can use branch predictions to get around data dependencies.

now lets consider something like a branching operation. when we make a branching operation and execute code after that, we may have to end up waiting for some value tot be stored (the value while will determine our branch). for example, consider the following code:

```
loop:
    add R1, R2, R3
    sub R4, R5, R6
    beq R1, R4, loop
```

we have to end up waiting to branch back to the loop DEPENDING ON the value of R1 and R4. in this case we can do two things:
1. just wait
2. predict the branch

if we just wait, we end up losing on a lot of opportunities for parallelism. if we predict the branch, we can continue executing instructions after the branch, and if we are wrong, we would need to **flush** the pipeline and start over. this is called **branch prediction**.

so you might ask, why risk taking that hit? why not just go with option 1. well the answer is because branches are very common in code, and if we just wait, we will end up losing a lot of opportunities for parallelism. moreover, branch predictions are usually very accurate.

## superscalar execution

we can also have multiple pipelines, which is called **superscalar execution**. this is where we have multiple pipelines, and we can execute multiple instructions at the same time. this is a form of parallelism.

visually it might look like

```
F D E W
F D E W
  F D E W
  F D E W
    F D E W
    F D E W
```

note that we have two pipelines, and we can execute two instructions at the same time. each column represents a moment in time.

### same code can do different things

the way your code behaves on your machine will end up depending on how it was compiled.

## out of order execution

sometimes the instructions can just be reordered for better parallelism. for example consider a CPU with 2-way superscalar execution. consider the following assembly:
```assembly
load R1, @aff0
add R1, R1 @aff8
load R2, @aff4
add R2, R2, @affc
add R1, R1, R2
store R1, @bff0
```
we can re-order these instructions such that like operations can be execution in parallel (loads and adds):
```assembly
load R1, @aff0 ; parallel pair
load R2, @aff4

add R1, R1 @aff8 ; parallel pair
add R2, R2, @affc

add R1, R1, R2 ; true data dependency, can't parallelize with other add

store R1, @bff0 
```

### branch dependencies
- this is when scheduling instructions across branches may lead to errors
- i.e, we scheduled incorrect instructions and now need to flush results

branch dependencies are handled by speculative execution and branch prediction.

### resource dependencies
- when two or more instructions compete for a single processor resource.

### under-utilization of superscalar processor

the performance of a superscalar processor is ultimately just determined by how many instructions we can execute at the same "level" of time. remember this is "instruction level parallelism" (ILP).

**vertical waste**: when no instructions are executed on a cycle

**horizontal waste** when only part of the execution units are used during a cycle

## very large instruction word
- VLIW is a hardware logic for ILP
- an alternative to superscalar execution
- we allow software to specify the instructions to execute in parallel!
- compile time scheduling where the compiler explicitly specifies multiple operations to run in parallel.
- a VLIW instruction encodes multiple operations to be executed in parallel

**advantages**:
- simpler hardware logic for instruction issue
compiler not limited by a small look-ahead window, have more time to optimize code better.

**disadvantages**:
- compilers do'nt have dynamic program state to make dynamic scheduling decisions (branch predictions, predict stalls, cache misses, etc.)
- performance is highly dependent on compiler's ability to detect dependencies and maximize parallelism.


# MEMORY SYSTEM PERFORMANCE

performance depends on both cpu speed and memory system parameters.

**latency** is just the time taken to serve a memory request (for example 100ns)

**bandwidth** is the rate at which data can be served from memory (for example 10GB/s)

**pizza truck analogy**:
1. latency = how long it takes the pizza truck to deliver pizza. independent of how many pizzas it's carrying.
2. bandwidth = max number of pizzas that can be transported at a time


### performance impact

lets consider an example. say we have:
- 1 core cpu @4GHz clock rate
- say CPU is capable of executing 4 instructions per cycle

we consider one floating point operation to be the same as 1 instruction. so we have:
```
4GHz * 4 = 16 GFLOPS 
```

this means the peak processing rate is **16 GFLOPS** (16 x 10^9 FLOPS). FLOPS stands for floating point operations per second. 

however, from having to access memory, we may have significantly less performance!

for instance, suppose DRAM latency is 40ns and we have no caches. suppose we are computing the sum of an array's elements where 1 element is 1 word. then every time we need to make a memory request to retrieve 1 word from memory. so our computations are limited to doing a single floating point operation every 40 ns.
```
=> performance = 1 / (4 * 10^-8 s)
                    = 0.25 * 10^8 FLOPS
                    = 25 MFLOPS
```
this is technically neglecting the time for the floating point operation itself which is 1 / 16 * 10^9Hz (negligible compared to 40ns). our actual time would be 40ns + 1 / 16 * 10^9Hz for clarity.

anyhow, we see we went from 16 GFLOPS to 25 MFLOPS! massive performance loss. this is a memory-bound process: computation rate is not bounded by CPU speed but rather memory access. 

### improving latency with caches

so to avoid the loss of performance from DRAM, we can use caches. caches are small, fast memory units that store frequently accessed data. they are much faster than DRAM. 

DRAM access took 40ns, and using the clock rate (4GHz), we know a single cycle takes = 1 / 4GHz = 0.25 ns. Then each DRAM access takes 40 / 0.25 = 160 cycles.

now suppose we had a cache that was 32KB and had a latency of only 1 cycle. so 160 times faster! and suppose our entire array was able to fit into the cache. then we could compute the sum of the arrays elements much faster!

if we had no pipelining, our performance would be 8 GFLOPS. with pipelining (overlapping fetches and addition) we could have 16 GFLOPS.

### cache lines

caches are managed at the granularity of **cache lines**. this is the size of memory that is loaded or evicted from a cache at once. so if we're accessing an element of an array, we load in a cache line of data around that element. 

### improving performance with memory bandwidth 

recall with no caches, our perfomrnace was 25 MFLOPS due to memory accesses. suppose our memory access still takes 40ns (160 cycles), but we can load 4 words in of the array at a time. that is, we have a higher bandwidth.

so we can load in 4 elements, sum them, and then load the next 4. this means we can do 4 floating point operations every 40ns, or 1 floating point operation every 10ns.
```
performance = 1 / (10 * 10-9 s)
            = 10^8 FLOPS
            = 100 MFLOPS
```
four-fold performance increase compared to before. of course, we are again neglecting the time it would take for the floating point operations themselves (1/16 * 10^-9 s).

the bandwidth is dependent on the **memory bus**. a memory bus of 4 words would be 4 * 32 = 128 bits (on a 32-bit system). however, having large bus width's is expensive and impractical.

we can keep the memory bus width to be 32-bits and instead load put the next 3 words on each "subsequent bus cycle" (N.S. what this means for now: where are the next 3 words being loaded? is there some buffer?).

so the practical solution is after the first word is sent, the next 3 are on the next 3 subsequent bus cycles. assuming that the memory bus speed is 1GHz (1ns), each access will then be 40ns + 3x * 1ns = 43 ns.
- still remains close to 100 MFLOPS

#### cache hit ratio
the above gives us a cache hit ratio of 75% (3 words of 4 are essentially cached). this means 25% of accesses take 40ns and the rest are 1ns (memory bus speed). if we neglect cache access and memory bus speed, then we can say that
```
performance = 1 / (0.25 * 40 ns)
            = 1 / (1*10^-8s)
            = 100 MFLOPS
```

side note, 128-bit is actually too "expensive". DDR4 and DDR5 use 64-bit with dual channels making them effectively 128-bits. 

notice that fetching "closeby" locations in memory benefits cache hit rates.
- if a program accesses contiguous data items, we say it has good spatial locality. for example, accessing array elements that are contiguous in memory.

### spatial locality & bandwidth utilization
it's important to note that programs that have good spatial locality have good bandwidth utilization. 
- data lies in same DRAM row
- program takes advantage of things like burst transfers (more on this later)
- compiler can also help with this by restructing code for better spatial locality in memory accesses.

### spatial locality example

consider the following code:
```c
int col_sum[1000];
// a is an integer matrix of dimensions 1000 x 1000 already initialized
for (int i = 0; i < 1000; i++) {
   col_sumn[i] = 0.0;
   for (j = 0; j < 1000; j++) {
      col_sum[i] += a[j][i]
   }
} 
```
note when we do a[j][i], j accesses the  row, then i accesses the column inside that row. so if we iterate through i before j, then we are going through the matrix in a column-major acccess pattern:
```
# matrix:
A  B  C 
D  E  F
G  H  I

# column major access:
1.
[A] B  C
 D  E  F
 G  H  I

2.
 A  B  C
[D] E  F
 G  H  I

3. 
 A  B  C
 D  E  F
[G] H  I

4.
 A [B] C
 D  E  F
 G  H  I

and so on... E, H, C, F, I
```
this is bad spatial locality because in C, memory is contiguous in ROWS! our matrix is essentially just a pointer to pointers (rows). for better spatial locality, we want to access in a row-major pattern.

```
# row major access

# matrix:
A  B  C 
D  E  F
G  H  I

# access order
A, B, C, D, E, F, G, H, I
```

we can restructure the code to do row-major access:

```c
for (int i = 0; i < 1000; i++) {
   col_sum[i] = 0.0;
}

for (int j = 0; j < 1000; j++) {
   for (int i = 0; i < 1000; i++) {
      col_sum[i] += a[j][i];; 
   }
}
```
now we're going through a whole row at once and incrementing the column index `i` each iteration.ol


## hiding memory latency

a common technique to hide memory latency is to use **pre-fetching**. this is where we predict what data we will need in the future and load it into the cache before we need it.

load data from emory in advance (either in hardware or software), so that when we need it, it's already in the cache.

**an issue**: the data could be updated between load and use,
- would need to reload it once again

### prefetching

#### hardware prefetching

we can do this using "stream buffers".
- on a cache miss, fetch **x** subsequent addresses into a buffer size of size **x**, i.e, the stream buffer.
    - note that by cache miss, we mean that the data we need is not in the cache, so we need to go to memory to get it.

#### software prefetching

- typically for loops with a large number of iterations. the compiler can prefetch the data into the cache before it's needed.

an example is the following code:

```c
for  (int i = 0); i < N; i++) {
    a[i] = 2 * a[i];
}
```

we prefetch like so:
```c
for (int i = 0; i < N; i++) {
    prefetch(a[i + s]);
    a[i] = 2 * a[i];
}
```

let's make some assumptions to demonstrate this idea of prefetching:
- assume that each element is on its own cac he line
- prefetch the "stride" s elements ahead of time

for example, if each iteration takes 7 cycles and a cache miss is 49 cycles, then we can hide the latency of the cache miss by prefetching the data 7 elements ahead of time.

to clarify, when we say each iteration takes 7 cycles, we mean that the the processor takes 7 cycles to execute the code in one loop. 

### multi threading
another way to hide latency is by multithreading. multithreading will be the primary focus on these notes actually. 
- the idea is if lots of threads are running in parallel, while soem are waiting for data from memory, others already have some data that they are working with.
- hide latency with multiple contexts of execution

in the next section we explore threads with more detail.

# THREADS

threads are a way to have multiple tasks running concurrently. threads are lightweight processes that share the same memory space. threads are useful for parallelism.


### why threads over processes?

processes take a lot more overhead. in short, threads are just more lightweight. the main difference is that threads share the same memory space, while processes do not.

threads are all the same process, but they have different stacks. so they all have the same PID, but they have different TIDs. whereas processes all have their own PID and don't share memory space.

### posix threads

a standard interface for creating and managing threads in C is called **pthreads** (posix threads). pthreads is a library that allows us to create and manage threads.

in addition to these notes, learn more about pthreads here: https://hpc-tutorials.llnl.gov/posix/

here is an example of how to create a thread in C using pthreads:

```c
#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS     5

void *PrintHello(void *thread_id) {
   long tid;
   tid = (long)thread_id;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t = 0; t < NUM_THREADS; t++) {
      printf("In main: creating thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
```

before we go into the code, note that **you must compile with the `-pthread` flag**. for example, if you have a file called `threads.c`, you would compile it like so:

```bash
gcc -pthread threads.c
```

if you don't use the `-pthread` flag, you may get errors or the code may not work as expected.

now let's focus on the code itself. so we have a few things going on here. first of all, we are using the `<pthread.h>` library. from this library, we are using `pthread_create` to create threads. this function takes 4 arguments:

1. the thread object (where the thread will be stored)
2. the thread attributes (NULL for default)
3. the function to run in the thread, sometimes called the routine
4. the arguments to pass to the function (only one argument, so we cast it to a `void *`)

#### thread creation
in this case, we are creating 5 threads, and each thread is running the `PrintHello` function. the `PrintHello` function takes a `void *` argument, so we need to cast it to a `long` inside that function before we can use it.

#### passing arguments
also, to pass multiple arguments to a function, you can create a struct and pass a pointer to that struct as the argument. we will go more in depth on this in the next section.

#### exiting threads
note that we are using `pthread_exit` to exit the threads. you can run this code in `pthreads/creating_and_deleting_threads.c` inside `code_examples`.

we can exit with pthread_exit() and return any pointer type (just need to cast it to void).
```c
pthread_exit((void*)some_value);
```
if we have nothing to return, we can just do:
```c
pthread_exit(NULL);
```
you can access this value again using `pthread_join()`. more on this later.

we can also exit by just returning a void pointer type back directly:
```c
return (void*)some_value;
```
and access the return value the same way (using `pthread_join`). 

#### pthread_exit vs return
there are 2 main differences between using `pthread_exit(val)` and `return val` for threads.
1. control flow
   - calling `return` in threads may not make threads exit if the return is placed inside another function that was called during the routine
   - calling `pthread_exit()` always exits the thread
2. main function
   - calling `return` in main function terminates the **entire process**, including any separate threads
   - calling `pthread_exit()` in main only terminates the main thread, while leaving any spawned threads still running. the program terminates once all threads exit. 

control flow difference example:
```c
int helper(int n) {
   if (n == 1) pthread_exit(NULL); // stops routine and exits whole thread
   return n % 3;
}

void* thread_routine(void* arg) {
   int n = *(int*)args;
   int val = helper(n);
   // ...
   pthread_exit((void*)val);
}

```
in `helper`, if we get `n == 1`, then the entire thread routine ends. on the other hand, if we end up doing `return n % 3`, control is returned to the calling function--the thread routine `thread_routine`, and then `pthread((void*)val)` is called.


### passing arguments to pthreads

this is actually something you need to be careful about. firstly, note that all arguments need to be "passed by reference" (i.e, pointers) and should be cast to `void *`. 

now we ask the question, "given that created threads have a non-deterministic startup, how can we safely pass data to them?".

one answer is: **make sure all data passed cannot be changed by other threads**. any data that you pass in should be not changeable by other threads.
- you can do things like pass in an array but each thread accesses a unique index
- for concurrent read/writes to same data, we need to protect it with primitives like mutexes and semaphores (more on these later)

for example, in the code we provided above, each thread received a unique `long` value, which is safe because no other thread can change that value.

DO NOT DO SOMETHING LIKE THIS:

```c
int rc;
long t = 69;

for(int i = 0; i < NUM_THREADS; i++) {
   printf("Creating thread %ld\n", t);
   rc = pthread_create(&threads[i], NULL, PrintHello, (void *) &t);
   ...
}
```

this is bad because it passes the address of variable `t`, which is in a shared memory space and visible to all threads. as the loop iterates, the value of this memory location changes, possibly before the created threads have a chance to read it. we can instead pass the value of `t` itself (so not its address) masked as void*:

```c
int t = 69;
for (int i = 0; i < NUM_iHREADS; i++) {
   rc = pthread_create(&threads[i], NULL, PrintHello, (void*) t);
}
```
this is safe so long as the thread routine properly handles the non-address value.

### joining and detaching threads

suppose we have a thread that we want to wait for before we continue in the calling thread. or maybe we have multiple threads that we want to wait for before we continue in the calling thread. we can do this using `pthread_join`. calling `pthread_join` will make the calling thread wait for the specified thread to finish and allow u to also read its value.

joining a thread is useful because it allows us to obtain the thread's termination status and any return value.

we can obtain the thread's termination status if we specify in the target thread's call to `pthread_exit`. a thread can only be joined once. it is an error to join a thread that has already been joined:
```c
void* thread_routine(void* arg) {
   int x = (int)arg;
   return x;
}

int main() {
   int n = 8;
   pthread_t threads[n];
   for (int i = 0; i < n; i++) {
      pthread_create(&threads[i], NULL, thread_routine, (void*)i);
   }

   // join threads
   for (int i = 0; i < n; i++) {
      int ret_val;
      pthread_join(thread[i], (void*)ret_val);
      printf("ret_val is: %d\n", ret_val);
   }
   return 0;
}
```
you can run this code in `pthreads/joining_threads.c`

there are also other synchronization mechanisms, such as `mutexes` and `condition variables`. we will go over these later.

when a thread is created, one if its attributes defines weather it is "joinable", or "detached". if a thread is joinable, then another thread can call `pthread_join` on it. if a thread is detached, then it cannot be joined.

we can also detach an originally joined thread using `pthread_detach()`. this will allow the thread to run independently of the calling thread.

#### why join or detach?

joining a thread is useful because it allows us to obtain the thread's termination status. furthermore, it allows for resource clean up. if a thread is not joined and it is not detached, its resources remain allocated until the process terminates, which can lead to resource leaks. we want our threads to be cleaned up after they are done. if a thread is detached, then its resources are cleaned up automatically.

joining threads can also be used as a "synchronization" mechanism. it ensures that certain tasks are all completed before we proceed. this can help in coordinating the execution flow of a multithreaded program.

here is an example of making a thread joinable:

```c
int main (int argc, char *argv[]) {
   pthread_t thread[NUM_THREADS];
   pthread_attr_t attr;
   int rc;
   long t;
   void *status;

   /* Initialize and set thread detached attribute */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   for(t = 0; t < NUM_THREADS; t++) {
      printf("Main: creating thread %ld\n", t);
      rc = pthread_create(&thread[t], &attr, some_func, (void *)t);
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
}
```

### stack management

each thread has its own stack. the stack is used to store local variables and function call information. the stack size is usually limited, and if you exceed the stack size, you will get a stack overflow error.

the POSIX standard does not dictate the size of a thread's stack. this is implementation dependent and varies. exceeding the stack size is very easy to do and results in either program termination or undefined behavior/corrupted data.

safe and portable programs do not depend upon the default stack limit, but instead, explicitly set the stack size using `pthread_attr_set_stack_size` routine. again, when we say "routine", we mean a body of instructions such as a function.

furthermore, the pthread_attr_getstackaddr and pthread_attr_setstackaddr routines can be used by applications in an environment where the stack for a thread must be placed in some particular region of memory.

the following example demonstrates how to set the stack size for a thread:

```c
#include <pthread.h>
#include <stdio.h>

#define NTHREADS 4
#define N 1000
#define MEGEXTRA 1000000

pthread_attr_t attr;

void* do_work(void *thread_id) {
   double A[N][N];
   int i, j;
   long tid;
   size_t my_stack_size;

   tid = (long)thread_id;
   pthread_attr_get_stack_size(&attr, &my_stack_size);
   printf("Thread %ld: stack size = %li bytes \n", tid, my_stack_size);
   for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
         A[i][j] = ((i * j) / 3.452) + (N - i);
      }
   }
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   pthread_t threads[NTHREADS];
   size_t stack_size;
   int rc;
   long t;

   pthread_attr_init(&attr);
   pthread_attr_get_stack_size(&attr, &stack_size);
   printf("Default stack size = %li\n", stack_size);

   stack_size = sizeof(double)*N*N+MEGEXTRA;
   printf("Amount of stack needed per thread = %li\n", stack_size);
   pthread_attr_set_stack_size (&attr, stack_size);

   printf("Creating threads with stack size = %li bytes\n", stack_size);
   for(t=0; t<NTHREADS; t++){
      rc = pthread_create(&threads[t], &attr, do_work, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);s
         exit(-1);
      }
   }
   printf("Created %ld threads.\n", t);
   pthread_exit(NULL);
}
```

we see that we are setting the stack size using `pthread_attr_set_stack_size`.

### more pthread routines
- `pthread_self()`: returns the thread ID of the calling thread
- `pthread_equal(pthread_t t1, pthread_t t2)`: compares two thread IDs
- `pthread_cancel(pthread_t thread)`: sends a cancellation request to the specified thread
- `pthread_once(pthread_once_t *once_control, void (*init_routine)(void))`: ensures that a routine is called only once


## decomposition and tasks

- decomposition: diving the computation in a program into tasks that could be executed in parallel.


- we say a "task" is a unit of computation that can be extracted from the main program.

## matrix vector multiplication

we can consider the problem of having to multiply a matrix M by a vector v.

```
M = | 1 2 3 |
    | 4 5 6 |
    | 7 8 9 |

v = | 1 |
    | 2 |
    | 3 |
```

the multiplication `Mv` would produce a row vector of size 3.

```

```




## task dependencies
tasks are not independent if they depend on other tasks

- a task might need data provided by other tasks, and we would have to wait until that input is ready

we can easily model task dependencies with a directed graph. each node represents a task, and each edge represents a dependency.

## granularity

### fine grained
we say that our tasks are "fine-grained" if we have multiple small tasks

### coarse grained
we say that our tasks are "coarse-grained" if we have fewer, larger tasks

### tasks communication

ideally we have zero communication between tasks, but realistically we will need to communicate to bring things together.


for fine grained tasks, we will have a lot of communication overhead. for coarse grained tasks, we will have less communication overhead and more computation in each task.

we would need to consider the tradeoff between computation and communication.

## degree of concurrency

we calculate two kinds of degrees of concurrency:

1. the maximum degree of concurrency

this is the maximum number of tasks that can be executed at the same time.

2. the average degree of concurrency

this is the average number of tasks that can be executed at the same time. we can calculate summing the parallelism of tasks at each level and dividing by the number of levels.

## task interactions

a limiting factor to how much parallelism can help us.

task interactions are not just dependencies, but rather just communication in general. for example if we have something stored in task A that we need to access for other tasks, we would need to communicate that data. and this doesn't necessarily need to be a "dependency", because we wouldn't have to "wait" for task A to finish before we access this data.

for showing this we would use a graph with more edges for interactions. essentially a superset of the dependencies graph.

## mapping tasks to processes

- mapping is the job of assigning tasks to processes

recall that a process is an instance of a program running on a computer. we would want to map tasks that communicate/depend with each other a lot to the same process to lessen overhead.

similiarly, we can map processes to processors. typically we have a 1-1 mapping, but we can have multiple processes on one processor.

### what is a processor ? 
recall that a processor is a physical chip that executes instructions. a processor can have multiple cores, and each core can execute instructions independently. 

## data decomposition

- we want to partition the data based on which computations are performed
- use the data partitioning to perform the decomposition of computation into tasks

we have several partitioning strategies:
- partition output data
- partition input data
- partition both input and output data
- partition intermediate data

## exploratory decomposition
- a common approach for problems that involve a wide search space for potential solutions
- essentially, we search for a solution in parallel
- example: path finding, sokoban, etc.



## speculative decomposition
- similar to speculative execution in CPUs
- suppose we have some branches that may or may not be taken
- we can execute all of those branches in parallel and do some computation
- we pick the correct branch and discard the rest
 

## hybrid decomposition
this is a simple idea. for example, we can combine input data decomposition with task decomposition. we first partition the input data, and then we partition the tasks based on the input data partitions.

## characteristics of tasks

we now discuss some defining characteristics of tasks 
- task generation: whether a task is generated dynamically or statically
- task sizes: whether the task sizes will be uniform (all the same size) or non-uniform (different sizes)
- size of data for each task

### task generation

**static task generation**

static task generation is when we will know all the tasks in advance for a problem.

for example, for **mergesort**, we will always be splitting the tasks in a binary fashion, so we can know all the tasks in advance.

**dynamic task generation**

dynamic task generation is when the number of tasks we will generate can vary for the problem based on the input we get.

for example **quicksort**, we could have different kinds of generations depending on the pivot we choose.

### task sizes and data associated with each task

task sizes are obviously proportional to how much time it will take to finish the task. 

**uniform task sizes**

will roughly all take the same amount of time to finish.

**non-uniform task sizes**

will take different amounts of time to finish.

for example again, mergesort will have uniform task sizes, while quicksort will have non-uniform task sizes.

the same idea applies for the data associated with each task.

## characteristics of task interactions

- static vs dynamic
- regular vs irregular
- read only vs read write
- one way vs two way

### static vs dynamic

**static task interactions**

each task interacts at predetermined times with a predetermined set of tasks. 

**dynamic task interactions**

the interactions are not predetermined and can change based on the input. these are harder to write parallel programs for.

### regular vs irregular

**regular task interactions**

if the interaction "patterns" have a spatial structure that can easily be exploited to split up the tasks.

**irregular task interactions**

if the interaction "patterns" do not have a spatial structure that can easily be exploited to split up the tasks.

### read only vs read write

**read only task interactions**

these are interactions where each task may only have to read from other tasks. 

for example in a matrix multiplication, each task may only need to read from other tasks, but never write to them. the write happens at the end, but that's not between the concurrent tasks, that's just a dependency.

**read write task interactions**

these are interactions where each task may have to read and write to other tasks. 

for example in a graph traversal, each task may have to read and write to other tasks. consider a parallel BFS, we would need to update the queue which the other tasks would rely on.

# measuring performance

## gprof
`gprof` is a performance analysis tool for linux. there are many other tools like `perf`, `valgrind`, etc. `gprof` is a good tool for profiling C programs.

to use `gprof`, you need to compile your program with the `-pg` flag. for example, if you have a file called `program.c`, you would compile it like so:

```bash
gcc -pg program.c
```

then you would run your program like normal. after you run your program, you will see a file called `gmon.out` in your directory. you can then run `gprof` on your program to see the profiling information. for example, if you have a program called `program`, you would run `gprof` like so:

```bash
gprof ./program
```

you can also save the output to a file like so:

```bash
gprof ./program > output.txt
```

when we do this, `gprof` automatically looks for the `gmon.out` file in the current directory. so if you didn't compile with the `-pg` flag, you will get an error when you run `gprof`. suppose you have multiple `gmon.out` files (gmon1.out, gmon2.out, ... gmonk.out), you can specify which one to use like so:

```bash
gprof ./program gmon1.out > output.txt
```

now let us go over the output of `gprof`. the output of `gprof` is divided into two parts: the flat profile and the call graph.