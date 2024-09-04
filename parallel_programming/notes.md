# Parallel Programming

## Why learn parallel programming?

parallel programming s very useful in many fields for optimization.

## implicit parllelism in CPU arcjotecutres

we have some big decisions to consider:
- a
- b

## pipelining
recall that an instruction involves multiple micro-actions and stages, for example:
- F: fetch
- D: decode
- E: execute
- W: write back

before, instructions would be instructed one after the other, but now we can have multiple instructions in different stages at the same time. the concept is that while one instruction is being fetched, another is being decoded, and another is being executed, and another is being written back, we can have these all happening concurrently.

