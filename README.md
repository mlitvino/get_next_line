# get_next_line 

The aim of this project is to create a function that can read a line ending with a newline character ('\n') from a file descriptor without knowing its size in advance.
One of the goals of this project is to learn about a fascinating new C programming concept: static variables, and to gain a deeper understanding of memory allocation.
This includes understanding how they are allocated, whether to stack memory or heap memory, how buffers are manipulated and their life cycle, and the unexpected complexity involved in using one or many static variables.

## Execution

    gcc main.c get_next_line.c
    ./a.out text.txt
