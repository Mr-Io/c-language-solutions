Next steps after K&R
====================
When you finish K&R, the next step is to make bigger
and more complex C programs and
to introduce yourself to system programming.


This section contains a list with fundamental topics
of a modern computer science course on computer systems.
There is also information of how each topic enhances
our C programming knowledge and skills.


The idea is that each one seek and study each topic
from the sources and at the pace that he considered.


Bit-level representation of data
--------------------------------
Understand the representation of unsigned, two's complements and
IEEE floating point.


This applies directly to C programming:
   * Tradeoff between using the IEEE floating point for decimal operations (with rounding floating errors) vs using an exact decimal library 
     (efficiency).
   * Choose between detecting, avoiding or ignoring overlows of integers and overflows/underflows of floating numbers.
   * Manipulate data values at the bit-level if necesary. 
   * Understand the casting behaviour of each data type pair.


Assembly
--------
Have an idea of how
functions and other constructs are translated to assembly within
the compiler process (no need to code in assembly). Understand how the stack allows the implementation of functions.


This applies directly to C programming:
   * Differentiate between local variables in the stack (or register)
     and global variables in the heap and what it implies.
     (stackoverflow anyone?)
   * Know how to forge buffer overflows attacks
     , the need to avoid unsafe functions and when it is safe to use them.
   * Know how to modify C code
     to enable microarchitecture optimizations.


Physical Memory
---------------
Understand the principle of locality and differentiate between
registers, main memory and disk. Understand why caching works.


This applies directly to C programming:
   * Avoid low-level trashing.
   * Identify the most efficient way to traverse a data structure.


Linking
-------
Understand the steps of a compiler driver: preprocessor, compiler, assembler
and linker, and the different types of files: source, preprocessed, assembly, object file,
static library, shared library and executable file. Understand how linking works at
compile, load and run time, and the importance of global-scope symbols (nonstatic global
variables and nonstatic functions).


This applied directly to C programming:
   * Know how to modularize and structure a program.
   * Know what to include in a header file and when to break the rules.
   * Know When to create and use static and shared libraries.


Virtual Memory
--------------
Understand what are the differences between allocated and not allocated
addresses and how file permission is implemented. 
Differentiate between allocated addresses cached on RAM
vs not cached. Understand memory mapping (anonymous and backed-up
by files) and swapping in and out.


This applied directly to C programming:
   * Know what causes a segmentation fault, protection fault and page fault.
   * When and how to use ``mmap``.
   * know why dynamic allocation exists (eg. ``malloc``) and for what types of programs it pays to build a custom memory allocator.
   * *extra for linux users: what is the swap area used for, how large should it be and how the swappiness value affects it*


Input/Output and Network Programming
------------------------------------
Know precisely what is I/O. Understand the difference between UNIX I/O and the standard I/O library and why the last one is needed. Understand sockets and the difference between slow and fast files types.


This applies directly to C programming:
   * Know when to use UNIX I/O vs standard I/O library.
   * Know when it is worth making your own I/O library to increase efficency with buffers while dealing with 
     with short-counts, blocking and errors on signal interrupts. 


Concurrent programming
----------------------
Understand system calls, processes and signals.
Identify concurrent logic flows and its implications.
Understand the different states of a process:
running, sleeping, stopped and zombie.
Understand process hierarchy, process group id and process session id.
Understand the difference between background and foreground jobs in a shell.


This allow us to make concurrent programs:
   * Deal with slow I/O using multiprocessing, multithreading or I/O multiplexing.
   * Use multiprocessing or multithreading to leverage processors with multiple physical and logical cores.
   * Distinguish between reentrant, async-safe and thread-safe functions. 
   * Know how to design reentrant functions to take full advantage of processors in a multithreading environment.










