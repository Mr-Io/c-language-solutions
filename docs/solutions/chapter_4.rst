Chapter 4
=========

Exercise 4-1
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_01/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out
    Knowledge is power
    ow
    position of last occurence: 14

Exercise 4-2
------------
*main.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_02/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

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
    
    In general, it is usual to start library file names
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

.. _exercise-4_0307:

Exercises 4-3, 4-4, 4-5, 4-6
----------------------------
*main.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_03-07/main.c
    :language: c
    :tab-width: 4


* ``getopt`` was vulnerable to buffer overflows, wo we added the
  ``n`` parameter and change its name to ``gettoken``.
  Same as ``getopt``, 
  ``gettoken`` saves the value of a token in ``s`` 
  and returns its type.
  The type of token is used in the 
  switch case statement to decide which operation to do next. 
* The modulus operator ``%`` (indicated in exercise 4-3) is added 
  in the switch case statement the same way as the rest of operators.
* The commands of exercise 4-4 and the math functionalities 
  of exercise 4-5 are added using the different types 
  returned by ``gettoken``: 
  ``SIN``, ``POW``, ``EXP``, ``DUP``... 
  wich are defined in *tokenizer.h*.
  This could have been done in another way if we could use pointers to 
  functions, making the switch case much shorter. Exercises with
  pointers are solved in :ref:`chapter-5`.
* The stack is always visible, 
  we do not need to pop an element to see its value 
  and ``\n`` no longer removes an item from the stack, 
  it needs to be done explicitly with *del* command. 
* To add the variable functionality from exercise 4-6 
  it would have been best to allow the stack 
  to hold variables ``a-z`` aside from doubles values.
  However without using unions or structs from :ref:`chapter-6` the 
  implementation would have been messy. 
  What we did instead is make variables work in a simple way:
  when we enter a variable for the first time it saves the previous
  number, the next time we use the same variable it evaluates to
  the number saved. The list of saved variables is also visible
  while using the calculator.

*tokenizer.h*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_03-07/tokenizer.h
    :language: c
    :tab-width: 4

*tokenizer.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_03-07/tokenizer.c
    :language: c
    :tab-width: 4

* ``getopt`` functionality is refactored in different functions.
  As we have said ``gettoken`` is the interface; a 
  safe function that saves a token in ``s`` and returns its value. 
  ``getword`` is used to retrieve a word from the stdin 
  (a modified version of :ref:`exercise-1_16`)
  and ``isnumber``, ``ismath`` and ``isvar`` are used to determine
  its type. All the possible types are defined in *tokenizer.h*
  for other files to use.

* Notice that in the header, we only includes the functions
  that are intended to be used externally by other files. 
  It does not include 
  ``getword``, ``isnumber``, ``ismath`` and ``isvar`` 
  since those are intended for internal use only.

.. todo: note about what to include in header files

*stack.h*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_03-07/stack.h
    :language: c
    :tab-width: 4

*stack.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_03-07/stack.c
    :language: c
    :tab-width: 4


* Additional functions has been added to the stack module to
  implement the additional functionality that the exercises required. 
  An argument could be made about implementing 
  duplicate and swap logic in main instead of here. 

*myio.h*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_03-07/myio.h
    :language: c
    :tab-width: 4

*myio.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_03-07/myio.c
    :language: c
    :tab-width: 4

* ``ungets`` routine is implemented in *myio* module. It just uses
  ``ungetch`` to implement its functionality, it does not touch
  ``buff`` directly.

*variables.h*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_03-07/variables.h
    :language: c
    :tab-width: 4

*variables.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_03-07/variables.c
    :language: c
    :tab-width: 4

* We make another module (*variables.h* and *variables.c*)
  to implement variable evaluation logic. It is used directly by *main.c*.



Compilation and run:

.. code-block :: console

    $ gcc main.c variables.c tokenizer.c myio.c stack.c
    $ ./a.out

.. _exercise-4_08:

Exercise 4-8
------------
Same as :ref:`exercise-4_0307` but with the following modifications
to ``myio.h``  and ``myio.c``:

*myio.h*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_08/myio.h
    :language: c
    :tab-width: 4

*myio.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_08/myio.c
    :language: c
    :tab-width: 4

Notes:

    * There is no longer a buffer array, just one character buffer. 
      ``ibuf`` no longer represent the position in the buffer, 
      it only indicates if there is a character saved in the buffer
      or not.
    * ``getch`` and ``ungetch`` are modified to work 
      with the new versions of ``buffchar`` and ``ibuf``.
    * ``ungets`` get removed since it depended on having a buffer
      array (it was not used anyways).

.. _exercise-4_09:

Exercise 4-9
------------
Same as :ref:`exercise-4_08` but modifying *myio.c*: 

*myio.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_09/myio.c
    :language: c
    :tab-width: 4
    :emphasize-lines: 7,21

Notes:

    * We just changed the type of ``buffchar`` 
      from ``int`` to ``char``,
      this way it can hold ``EOF`` values aside from characters.
    * Notice that ``ungetch`` no longer return error when
      trying to push ``EOF``.

Exercise 4-10
-------------
Same as :ref:`exercise-4_09` but modifying *myio.c*:


*myio.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_10/myio.c
    :language: c
    :tab-width: 4

Notes:

    * Until now, we were using ``getchar`` from *stdlib* 
      to read from the standard input. 
      This exercise consist on organizing the code to use
      ``getline`` instead of ``getchar`` for reading from
      the standard input. 
      The only functions that depends on ``getchar`` are 
      ``getch`` and ``ungetch`` and, instead of getting rid of
      them and refactoring the whole program, we just make them
      use ``getline`` instead. 

Exercise 4-11
-------------
Same as :ref:`exercise-4_0307` but modifying ``getword``
from *tokenizer.c* and removing *myio.h* and *myio.c*: 

*tokenizer.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_10/tokenizer.c
    :language: c
    :tab-width: 4

Notes:
    * remember that * ``getch`` and ``ungetch`` were just 
      wrappers around ``getchar`` (or ``getline``) 
      from the standard library
      to implememt the "unget character" functionality
      (which the standard library already have btw). 
      Since we do not need that functionality anymore, 
      we can get rid of them and of the whole *myio* module 
      (*myio.h* and *myio.c*).

Exercise 4-12
-------------
*main.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_12/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out
    1234
    1234
    -1234
    -1234
  
Notes:

    * Refer to :ref:`exercise-3_04` to understand why we use
      bitwise operators to handle negative numbers and to understand
      why we dont need to implement buffer overflow control even
      when ``CINTLEN`` is just 20.

.. todo: talk about recursion, leap of faith and
          outperformance of iterative solutions.
          (recursion is even considered a code smell - references -)


Exercise 4-13
-------------
*main.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_13/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out
    Hello!
    !olleH
    Is this working fine??
    ??enif gnikrow siht sI

Notes:

    * We used getline from standard library to read lines from input,
      see notes on :ref:`exercise-1_17` to remember its usage.




Exercise 4-14
-------------
*main.c*

.. literalinclude:: ../../solutions/chapter_4/exercise-4_14/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block:: console

    $ gcc main.c
    $ ./a.out

