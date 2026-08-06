# Memory Maps Analysis

## stack_example.c

Execution Point 1:
- main creates the first stack frame.
- Heap is empty.

Execution Point 2:
- walk_stack creates a new stack frame.
- Each recursive call has its own local variables.
- Variables are destroyed when the function returns.

Execution Point 3:
- dump_frame creates another stack frame.
- p_local points to local_int.
- No heap allocation exists.

## aliasing_example.c

Execution Point 1:
- malloc allocates an array on the heap.
- Pointer a points to the heap.

Execution Point 2:
- b = a makes both pointers refer to the same heap allocation.
- No new memory is allocated.

Execution Point 3:
- free(a) releases the heap allocation.
- Both a and b become dangling pointers.
- Reading b[2] is an invalid read.
- Writing b[3] is an invalid write.

## AI Review

AI explanation:
After free(a), b becomes a dangling pointer.

Correction:
Both a and b become dangling pointers because both point to the same freed heap allocation.
