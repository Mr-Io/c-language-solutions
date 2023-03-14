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
    * In c, **main** is special, your program begins executing at the beginning of main. 
      this mean that every program must have a **main** somewhere.

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
    * In (page 193 K&R) it is stated that if the character following the \\ is not one of those specified,
      the behavior is undefined. Most compiler do a warning when a escape sequence is not recognized.

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
    * Hotice the equivalence between `while` and `for` 
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

