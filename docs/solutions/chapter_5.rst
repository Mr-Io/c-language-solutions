.. _chapter-5:

Chapter 5
=========

.. _exercise-5_01:

Exercise 5-1
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_01/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out
    > 3214
    Number: 3214
    > -2145
    Number: -2145
    > Hello
    Not a number!

Notes:

    * To keep familiarizing ourselves with the C standard library, 
      we use ``getc`` and ``ungetc``
      from ``<stdio.h>`` instead of 
      ``getch`` and ``ungetch`` defined in :ref:`exercise-4_0307`.
      One difference between them is that the
      ones from the standard library needs an additional 
      argument to specify where the input comes from 
      (``stdin`` in this case). 
      The solutions of exercises of :ref:`chapter-7` 
      are all about input and output.
    
    * ``ungetc`` may fail to push some ``c`` values. 
      Specifically, if the value of ``c`` equals 
      that of the macro ``EOF``, 
      the operation fails and the input stream is unchanged.
      This behaviour is alright, so
      we do not protect ``ungetc`` from receiving ``EOF`` and
      we also do not check for ``ungetc`` errors. 


Exercise 5-2
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_02/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out
    > 1424
    Number: 1424.000000
    > -12.134
    Number: -12.134000
    > .124
    Number: 0.124000
    > 123.
    Number: 123.000000
    > . 
    Not a number!

Notes:

    * Same considerations as :ref:`exercise-5_01`. 


Exercise 5-3
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_03/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out
    I saw her duck 
    for cover
    I saw her duck for cover

Notes:

    * We change the name of ``strcat`` to ``mystrcat`` 
      because there is a previous declaration of ``strcat``
      in ``<stdio>``.
    * It is responsibility of the caller to check that ``s`` 
      has enough space to concatenate the string ``t`` at its end.


Exercise 5-4
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_04/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out
    The way to start
    to start
    match: 1
    this is not real
    unreal
    match: 0

Notes:

    * We change the name of ``strcat`` to ``mystrcat`` 
      because there is a previous declaration of ``strcat``
      in ``<stdio>``.
    * It is responsibility of the caller to check that ``s`` 
      has enough space to concatenate the string ``t`` at its end.

Exercise 5-5
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_05/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out
    abcda
    abcda
    Comparison result: 0
    Concatenation result: abcdaabcda
    Copy results: abcda

Notes:

    * The description of the functions has been taken from the
      `man pages`_.

.. _man pages: https://www.kernel.org/doc/man-pages/

.. _exercise-5_06:

Exercise 5-6
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_06/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c 
    $ ./a.out
    > 123.25 Hello there!
    > there
    019: 123.25 Hello there!
    rev: !ereht olleH 52.321
    int: 123
    str: 123
    pos: 13
    > 123.25
    ope: 123.25

Notes:

    * ``mygetline`` is a rewrite the one from :ref:`exercise-1_16` 
      but it does not store the ending ``\n`` char in the buffer. 
      ``atoi`` is a rewrite of the one defined in the standard library.
      ``itoa`` and ``reverse`` are rewrites of 
      the ones from :ref:`exercise-3_04`.
      ``strindex`` is a rewrite of the one defined in K&R page 69.
      ``getop`` is a rewrite of the one defined in K&R page 78.

Exercise 5-7
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_07/main.c
    :language: c
    :tab-width: 4

The text input is from `sampletext.txt`_, we use redirection (``< sampletext.txt``)
to use the contents of this file as standard input when executing the program.

.. _`sampletext.txt`: https://www.gutenberg.org/cache/epub/1581/pg1581.txt

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out < sampletext.txt
    mode    clocktics       nº lines
    ----    ---------       --------
     sta         5028          32768
     dyn         3061          32768

Notes:

    * ``mygetline`` is the same as the one in :ref:`exercise-5_06`.
    * We use ``getline`` from standard library to fill an array of pointer.
      We use ``mygetline`` to fill an array of arrays. 
      The former case is  ~1.6 faster, 
      this implies that ``getline`` from standard library
      is more efficient than ``mygetline``, even when it allocates
      memory dynamically. 
    * Notice the difference in the first argument of ``readline_static``
      and ``readline_dynamic``:

        * ``char **lineptr`` is used to pass an array of pointers.
        * ``char (*lines)[LINESIZE]`` is used to pass an array of arrays. 

      The parentheses in ``char (*lines)[LINESIZE]`` are 
      neccesary because ``char *lines[LINESIZE]`` is equivalent to 
      ``char *lines[]``, which is just the same as ``char **lines``
      (an array of pointers).

.. _`exercise-5_08`:

Exercise 5-8
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_08/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out 
    > year month day: 1991 6 19
    day of year: 170
    > year yearday: 1991 170
    date: 19/06/1991
    > year month day: 2023 13 5 
    error day_of_year: wrong input

Exercise 5-9
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_09/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out 
    > year month day: 1991 6 19
    day of year: 170
    > year yearday: 1991 170
    date: 19/06/1991
    > year yearday: 2025 400
    error month_day: wrong input

Notes:

    * The solution is exactly the same as :ref:`exercise-5_08` but
      we replace every subscriptor ``[]`` operator knowing that:

      .. code-block:: c

        a[b]
    
      is equivalent to:

      .. code-block:: c

        *(a + b)

Exercise 5-9
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_08/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out 
    > year month day: 1991 6 19
    day of year: 170
    > year yearday: 1991 170
    date: 19/06/1991
    > year month day: 2023 13 5 
    error day_of_year: wrong input

Exercise 5-10
-------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_10/main.c
    :language: c
    :tab-width: 4

*stack.h*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_10/stack.h
    :language: c
    :tab-width: 4

*stack.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_10/stack.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc -o expr main.c stack.c
    $ ./expr 2 3 4 + '*' 

Notes:

    * *stack.h* and *stack.c* are the same as :ref:`exercise-4_0307`
      but with restricted functionality (only ``push`` and ``pop``).
    * ``isnumber`` is the same as the one 
      defined in :ref:`exercise-4_0307`, but we make use of the
      ``const`` qualifier to indicate that its argument 
      is read-only.
    * In Linux shell, ``*`` is a glob that refer to all the files
      in the current directory. Thus we need to use quotes ``'*'``
      to indicate the ``*`` asterisk character as a command-line
      argument.
    * Notice also when running any executable file we preceed 
      the file with ``./``, 
      this is done to indicate to the shell that 
      the program to execute is in the current directory 
      and it is NOT a built-in command or an executable file
      within some folder in a directory of the PATH 
      environmental variable.

.. note:: 

    The most common implementation to pass command-line arguments 
    *and environmental variables* to a program when it begin executing, 
    is to use ``main`` arguments and/or the external environmental
    variable ``environ``. 

    ``main`` is defined as follow:

    .. code-block:: c

        int main(int argc, char **argv, char **envp)
    
    where both ``argv`` and ``envp`` are both 
    NULL terminated arrays of pointer to strings.
    ``argv`` has the command-line argument values 
    (``argc`` just indicates its length) and 
    ``envp`` has the environmental variables.

    We can also access the environmental variables strings 
    through the external global variable ``environ`` wich is also
    a null-terminated array of strings 
    with the environmental variables:

    .. code-block:: c

        extern char **environ;

    ``environ`` has the advantage over ``envp`` that there is a set of 
    functions from the standard library for reading and modifying the
    environment: ``getenv``, ``setenv`` and ``unsetenv``.

    Nowadays, ``environ`` is the recommended way to access and edit
    environmental variables in a program. Moreover, while this is
    widely supported:

    .. code-block:: c

        int main(int argc, char **argv, char **envp)

    it is not guarantee to be present by the
    C99 standard or POSIX. While this one:

    .. code-block:: c

        int main(int argc, char **argv)

    is defined in the C99 standard.

Exercise 5-11, 5-12
-------------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_11_12/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc -o detab main.c
    $ gcc -o entab main.c
    $ ./detab 
    This    line has        spaces and tabs intercalated    but the output will have        only spaces.
    This    line has        spaces and tabs intercalated    but the output will have        only spaces.
    $ ./entab 
    this      line has      lots of spaces and      tabs   but the output have      only the minimum tab    necessary.
    this      line has      lots of spaces and      tabs   but the output have      only the minimum tab    necessary.

Notes:

    * The first string in ``argv`` is the name of the
      executable file used to run the program. Thus by compiling the 
      program with 2 different names *entab* and *detab* we can have
      different behaviour.

.. note:: 

    From this exercise onwards, we are going to give a proper name
    to the executable file when compiling (instead of leaving the
    default *a.out*) 

Exercise 5-13
-------------
*main.c*

.. literalinclude:: ../../solutions/chapter_5/exercise-5_13/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc -o tail main.c
    $ ./tail -3
    0
    1
    2
    3
    4

    2
    3
    4

Notes:

    * We make use of ``geline`` from standard library, 
      check :ref:`exercise-1_17` for idiomatic way to call the 
      function. In this case we make use of ``getline`` to fill
      an array of lines. To fully understand this function we
      still need to know dynamic memory allocation which is explained
      at the end of :ref:`chapter-6`. 
    * Notice that we use variable-length arrays, since the length
      of both ``lines_ptrs`` and ``lines_n`` arrays is unknown at
      compile time (only at run time). 
      This feature is from C99 onwards.

Rest of exercises
-----------------
The documentation is not complete, but the solution
code of the rest of the exercises can be consulted here:

https://github.com/Mr-Io/c-language-solutions/tree/master/solutions/chapter_5
