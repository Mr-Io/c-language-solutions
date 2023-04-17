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

Rest of exercises
-----------------

The documentation is not complete, but the solution
code of the rest of the exercises can be consulted here:

https://github.com/Mr-Io/c-language-solutions/tree/master/solutions/chapter_5

