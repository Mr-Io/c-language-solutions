Chapter 1 
=========

Exercise 1-1.
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_01/main.c
    :language: c

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    Hello, World


Notes:
    * In c, `main` is special, 
      your program begins executing at the beginning of `main`. 
      This mean that every program must have a `main` somewhere.

Exercise 1-2.
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_02/main.c
    :language: c

Compilation and run:

.. code-block :: console

    $ gcc main.c
    main.c: In function ‘main’:
    main.c:8:32: warning: unknown escape sequence: '\y'
        8 |         printf("\\y -> -\y- \n");
          | 
    $ ./a.out
    \t -> -	- 
    \b -> - 
    \a -> -- 
    \y -> -y- 

Notes:
    * On page 193 K&R, it is stated that if 
      the escape sequence is not recognized 
      the behavior is undefined.
      Most compiler just do a warning and ignore the \\.

Exercise 1-3.
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_03/main.c
    :language: c

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    Fahrenheit  Celsius
    ----------  -------
             0    -17.8
            20     -6.7
            40      4.4
            60     15.6
            80     26.7
           100     37.8
           120     48.9
           140     60.0
           160     71.1
           180     82.2
           200     93.3
           220    104.4
           240    115.6
           260    126.7
           280    137.8
           300    148.9

Exercise 1-4.
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_04/main.c
    :language: c

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    Celsius Fahrenheit
    ------- ----------
          0       32.0
         20       68.0
         40      104.0
         60      140.0
         80      176.0
        100      212.0
        120      248.0
        140      284.0
        160      320.0
        180      356.0
        200      392.0
        220      428.0
        240      464.0
        260      500.0
        280      536.0
        300      572.0
 

Exercise 1-5.
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_05/main.c
    :language: c

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    Fahrenheit  Celsius
    ----------  -------
           300    148.9
           280    137.8
           260    126.7
           240    115.6
           220    104.4
           200     93.3
           180     82.2
           160     71.1
           140     60.0
           120     48.9
           100     37.8
            80     26.7
            60     15.6
            40      4.4
            20     -6.7
             0    -17.8
 

Notes:
    * Notice the equivalence between `while` and `for` 
      iteration statements:
      
      .. code-block:: c

        for (expr_1 ; expr_2 ; expr_3){
            statement
        }
      
      is exactly the same as:

      .. code-block:: c
 
        expr_1;
        while(expr_2){
            statement
            expr_3;
        }


Exercise 1-6.
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_06/main.c
    :language: c

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    hello there
    111111111111

Notes:
    * Any assignment in C evaluates to 
      the value of the left hand side after after the assignment. 
      For example the expression 
      
      .. code-block:: c

        c = getchar() 
        
      evaluates to the return value of `getchar()`.
      And since the evaluation is done right to left
      this make this kind of expressions possible:

      .. code-block:: c

        a = c = getchar();

    * This is the first time we are exposed to error handling in C. 
      Usually functions return a special value when an error occur,
      for example `getchar()` return `EOF`.
      If we want to make a function call such as:

      .. code-block:: c

        c = getchar() 
    
      the idiom to make the error handling is:

      .. code-block:: c

        if ((c = getchar()) != EOF){
            /* error handling */
        }
      
    * Because of 
      `operator precedence <https://en.cppreference.com/w/c/language/operator_precedence>`_,
      the parentheses around the assignment in the previous code
      are necessary, always use them. Without them:

      .. code-block:: c

        c = getchar() != EOF;
    
      is equivalent to: 

      .. code-block:: c

        c = (getchar() != EOF);
      
      (`c` is either `0` or `1`) 

    .. note::
        From this exercise onwards, 
        all solutions must handle errors. 
        You can use your
        `system reference manuals <https://man7.org/linux/man-pages/man1/man.1.html>`_ 
        to check what the functions you are using 
        return on error.


Exercise 1-7.
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_07/main.c
    :language: c

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    value of EOF: -1

Notes:
    * We knew that `EOF` is an `int` because it is used as
      the error return value of functions that return `int`.