# Parallel Programming

## why learn parallel programming?

parallel programming s very useful in many fields for optimization.

## implicit parallelism in CPU architectures

we have some big questions to consider:
- how to effectively use a higher transistor count
- how to mitigate the memory speed gap (hierarchy of memories)

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

so you might ask, why risk taking that hit? why not just go with option 1. well the answer is because brances are very common in code, and if we just wait, we will end up losing a lot of opportunities for parallelism. moreover, branch predictions are usually very accurate.

### superscalar executions

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

### underutilization of superscalar processor

the performance of a superscalar processor is ultimately just determined by how many instructions we can execute at the same "level" of time. we call this "instruction level parallelism" (ILP).

## memory system performance

performance depends on both cpu speed and memory system parameters.

latency is just the time taken to serve a memory request (for example 100ns)

bandwith is the rate at which data can be served from memory (for example 10GB/s)

here's an analogy for water comingo ut of a pipe:

1. latency = how fast water comes out of the pipe
- better latency => needs more water pressure
2. bandwith = how much water can come out of the pipe at the same time
- better bandwith => need wider pipe


### performance impact

lets consider an example. say we have:
- 1 core cpu @4GHz clock rate
- say CPU is capable of executing 4 instructions per cycle

this means the peak processing rate is **16 GFLOPS** (billion floating point operations per second).

however, from having to access memory, we may have significantly less performance.

### improving latency with caches

so to avoid the loss of performance from DRAM, we can use caches. caches are small, fast memory units that store frequently accessed data. they are much faster than DRAM. 

## hiding memory latency

a common technique to hide memory latency is to use **pre-fetching**. this is where we predict what data we will need in the future and load it into the cache before we need it.

load data from emory in advance (eeither in hardware or software), so that when we need it, it's already in the cache.

**an issue**: the data could be updated between load and use,
- would need to reload it once again

### hardware prefetching

we can do this using "stream buffers".
- on a cache miss, fetch **x** subsequent addresses into a buffer size of size **x**, i.e, the stream buffer.
    - note that by cache miss, we mean that the data we need is not in the cache, so we need to go to memory to get it.

### software prefetching

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
    preftech(a[i + s]);
    a[i] = 2 * a[i];
}
```

let's make some assumptions to demonstrate this idea of prefetching:

- assume that each elemente is on its own cac he line
- prefetch the "stride" s elements ahead of time

for example, if each iteration takes 7 cycles and a cache miss is 49 cycles, then we can hide the latency of the cache miss by prefetching the data 7 elements ahead of time.

to clarify, when we say each iteration takes 7 cycles, we mean that the the processor takes 7 cycles to execute the code in one loop. 

## threads

threads are a way to have multiple tasks running concurrently. threads are lightweight processes that share the same memory space. threads are useful for parallelism.
 

### why threads over processes?

processes take a lot more overhead. in short, threads are just more lightweight. the main difference is that threads share the same memory space, while processes do not.

threads are all the same process, but they have different stacks. so they all have the same PID, but they have different TIDs. whereas processes all have their own PID and don't share memory space.

### pthreads

a standard interface for creating and managing threads in C is called **pthreads**. pthreads is a library that allows us to create and manage threads.

here is an example of how to create a thread in C using pthreads:

```c
#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS     5

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
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

so we have a few things going on here. first of all, we are using the `<pthread.h>` library. 

from this library, we are using `pthread_create` to create threads. this function takes 4 arguments:
1. the thread object
2. the thread attributes
3. the function to run
4. the arguments to pass to the function

in this case, we are creating 5 threads, and each thread is running the `PrintHello` function. the `PrintHello` function takes a `void *` argument, so we need to cast it to a `long` before we can use it.

