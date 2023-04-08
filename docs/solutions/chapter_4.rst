Chapter 4
=========

Exercise 4-1
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_01/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    Knowledge is power
    ow
    position of last occurence: 14

Exercise 4-2
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_02/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
	234
    234.000000
    0.123
    0.123000
    1234.
    1234.000000
    123.123
    123.123000
    123.2e4
    1232000.000000
    123.123e-3
    0.123123
    -1234    
    -1234.000000
    -1234.0
    -1234.000000
    -1234.
    -1234.000000
    -1234.2e4
    -12342000.000000
    -1234.234e4
    -12342340.000000
    -1234.123e-4
    -0.123412

Notes:

    * The option ``-lm`` tell GCC to link the math library. 
      This is necesary because the math library is not included
      by default. 
   
.. note:: 
    
    In general, is a convention to start library file names
    with "lib". This way, ``-lname`` search
    for a library file named *libname.so* in a specific 
    list of directories.  We can add new directories to the list
    using the option ``-L/another/path/to/search``. 

    If we add the option ``-static`` it searchs and links 
    static libraries instead (``libname.a``).  

    The standard library *libc.so* is always included by default.

.. todo: warn about:
    - function declaration of wrong types in different files 
      (solved by relying on appropiate header files)
    - implicit function declaration
      (solved by compiler - it issued a warning)
    - declaration without expliciting the argument types 
      (solved by using always void when there are no arguments) 


Exercise 4-3
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_03/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out

Exercise 4-4
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_04/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out



Exercise 4-5
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_05/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out



Exercise 4-6
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_06/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out



Exercise 4-7
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_02/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out



Exercise 4-8
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_08/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out



Exercise 4-9
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_09/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out



Exercise 4-10
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_10/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out

Exercise 4-11
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_11/main.c
    :language: c
    :tab-width: 4


*getop.h*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_11/getop.h
    :language: c
    :tab-width: 4

*getop.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_11/getop.c
    :language: c
    :tab-width: 4

*stack.h*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_11/stack.h
    :language: c
    :tab-width: 4

*stack.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_11/stack.c
    :language: c
    :tab-width: 4





Compilation and run:

.. code-block :: console

    $ gcc main.c getop.c stack.c
    $ ./a.out



Exercise 4-12, 4-13
-------------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_12_13/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out



Exercise 4-14
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_4/exercise-4_14/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out

