Chapter 1 
=========

Exercise 1-1
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_01/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    Hello, World


Notes:
    * In c, `main` is special, 
      your program begins executing at the beginning of `main`. 
      This mean that every program must have a `main` somewhere.

Exercise 1-2
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_02/main.c
    :language: c
    :tab-width: 4

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

Exercise 1-3
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_03/main.c
    :language: c
    :tab-width: 4

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

Exercise 1-4
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_04/main.c
    :language: c
    :tab-width: 4

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
 

Exercise 1-5
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_05/main.c
    :language: c
    :tab-width: 4

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
    
      (as long as `continue` statements are not used)


Exercise 1-6
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_06/main.c
    :language: c
    :tab-width: 4

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

Exercise 1-7
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_07/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    value of EOF: -1

Notes:
    * We knew that `EOF` is an `int` (or can be casted to an `int`
      without problem) because it is used as
      the error return value of functions that return `int`.

    * Notice we do not check for errors with `printf`.
      In general, it is common practice to not check for errors 
      when the the purpose of the function is to write to stdout
      (`putchar`, `printf`, ...)

.. note::

    It is reasonable to assume that writing to standard 
    output will not fail. If it does fail, how would 
    you tell the user, anyway?


Exercise 1-8
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_08/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    hello there
    General kenobi...
    Number of blanks, tabs and newlines: 4

Exercise 1-9
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_09/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    This     is  a line   with   a    lot of    blanks!
    This is a line with a lot of blanks!

Exercise 1-10
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_10/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    \Difficult      subjects cannot be described    with light prose
    \\Difficult\tsubjects cannot be described\twith light prose

Exercise 1-11
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_11/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    Beautiful is better than ugly.
    Explicit is better than implicit.
    Simple is better than complex.
    Complex is better than complicated.
    characters: 132
    lines:      4
    words:      20

Notes:
    * The kinds of input most likely to uncover bugs are those 
      that test boundary conditions. 
      *-to be updated with code test practices-*

Exercise 1-12
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_12/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    Very complex system may arise from very simple rules
    Very
    complex
    system
    may
    arise
    from
    very
    simple
    rules


Exercise 1-13
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_13/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    The world is a dangerous place to live; 
    not because of the people who are evil, 
    but because of the people who don't do anything about it.
    Vertical histogram
    ------------------
     0:
     1:|
     2:|||||
     3:|||||||||
     4:
     5:||||||
     6:||
     7:||
     8:|
     9:|
    Horizontal Histogram
    --------------------
              |                   
              |                   
              |                   
              |     |             
           |  |     |             
           |  |     |             
           |  |     |             
           |  |     |  |  |       
        |  |  |     |  |  |  |  | 
     0  1  2  3  4  5  6  7  8  9 

Notes:
    * In C, all elements of an array has the same type and the
      array size never changes during the array lifetime. Before
      C99, the array must be of constant fixed size 
      but since C99 the array size can be an integer expression
      evaluated everytime the array is allocated. 

Exercise 1-14
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_14/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    " In 1965, Gordon Moore, a founder of Intel Corporation, extrapolated from the chip technology of
    the day (by which they could fabricate circuits with around 64 transistors on a single chip) to predict
    that the number of transistors per chip would double every year for the next 10 years. This prediction
    became known as Moore’s Law. As it turns out, his prediction was just a little bit optimistic, but also too
    short-sighted. Over more than 50 years, the semiconductor industry has been able to double transistor
    counts on average every 18 months."     
    Vertical Histogram
    ------------------
    ":||
    (:|
    ):|
    ,:||||||
    -:|
    .:||||
    0:||
    1:|||
    4:|
    5:||
    6:||
    8:|
    9:|
    A:|
    C:|
    G:|
    I:||
    L:|
    M:||
    O:|
    T:|
    a:|||||||||||||||||||||||||||
    b:||||||||||
    c:|||||||||||||||||
    d:|||||||||||||||
    e:||||||||||||||||||||||||||||||||||||||||||
    f:|||||||
    g:||||
    h:|||||||||||||||||||||
    i:|||||||||||||||||||||||||||||
    j:|
    k:|
    l:||||||||||||
    m:|||||||
    n:||||||||||||||||||||||||||
    o:||||||||||||||||||||||||||||||||||||||||||||
    p:||||||||||
    r:|||||||||||||||||||||||||||||||||||
    s:|||||||||||||||||||||||||||||
    t:||||||||||||||||||||||||||||||||||||||||||||||
    u:|||||||||||||||
    v:||||
    w:||||||
    x:||
    y:||||||||||

Notes:
    * The most common single-byte character encoding is 
      `ASCII <https://theasciicode.com.ar/>`_. However, 
      this code will work no matter the character encoding
      used, even if there were negative `c` values 
      representing valid characters. We are making use of the 
      fact that *negative numbers in a*
      `two's-complement representation <https://en.wikipedia.org/wiki/Two's_complement>`_ 
      *map to large positive numbers in an
      unsigned representation*.
    * We only print "printable" characters 
      (excluding space). 
      The function `isprint` from `<ctype.h>`
      determines if a character is printable. 
      (page 249 K&R)
 
Exercise 1-15
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_15/main.c
    :language: c
    :tab-width: 4

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

Notes:
    * We are introduced to functions definitions. If a function 
      is overly large or complex maybe it should be splited; 
      *a function should do just one thing and do it well*.
    * Function parameters are local variables, if you modify them 
      inside a function the original variable is not affected. 
      They are just private, temporary copies. 

.. note::

    `main` is a function like any other, so it may return a
    a value to its caller 
    (the environment in which the  program was executed). 
    From this exercise onwards,
    we will return 0 to imply normal termination 
    and non-zero values to signal erroneous termination.

     

Exercise 1-16
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_16/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    The more you know, the more you realize you know nothing.
    Imagination is more important than knowledge.  For knowledge is limited, whereas imagination embraces the entire world, stimulating progress, giving birth to evolution
    The greatest enemy of knowledge is not ignorance, it is the illusion of knowledge.
    If people never did silly things, nothing intelligent would ever get done.

    longest line(168):Imagination is more important than kno


Notes:

    * We have changed the name of `getname` to `mygetname` because
      there is a previous declaration of `getline` in `<stdio>`. 

Exercise 1-17
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_17/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    The more you know, the more you realize you know nothing.
    Imagination is more important than knowledge.  For knowledge is limited, whereas imagination embraces the entire world, stimulating progress, giving birth to evolution
    168:Imagination is more important than knowledge.  For knowledge is limited, where
    The greatest enemy of knowledge is not ignorance, it is the illusion of knowledge.
    83:The greatest enemy of knowledge is not ignorance, it is the illusion of knowle
    If people never did silly things, nothing intelligent would ever get done.o

Notes:

    * This exercise is extremely easy after we defined the
      function getline in the previous exercise. 
      This is the purpose of well defined functions.

Exercise 1-18
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_18/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    Hello
    5:Hello
    This has a lot of blanks at the end                                                  
    35:This has a lot of blanks at the end

Notes:

    * We could have modified the function `mygetline` to achieve
      the functionality we wanted. However, that would be against
      the principle of *functions must do one thing and do it well*,
      which is what `mygetline` already does. 

Exercise 1-19
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_19/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    Hello!
    !olleH
    Is this working fine??
    ??enif gnikrow siht sI

Notes:

    * We make use of the previous functions 
      `getline` and `stripline` to get the lines 
      without trailing blanks, tabs and newlines. 
      This way `reverse` function logic is only about reversing
      the string.
    * Notice that we do not use an auxiliary char array
      to reverse the string, making it more memory efficient
      (at the expense maybe of some code readability). 
      Is this better? Depends, but we could argue
      that `reverse` function *does one thing and does it well*.
      

Exercise 1-20
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_20/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    This    line has        spaces and tabs intercalated    but the output will have        only spaces.
    This    line has        spaces and tabs intercalated    but the output will have        only spaces.
    
Exercise 1-21
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_21/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    this      line has      lots of spaces and      tabs   but the output have      only the minimum tab    necessary.
    this      line has      lots of spaces and      tabs   but the output have      only the minimum tab    necessary.
    
.. _exercise-1_22:

Exercise 1-22
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_22/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    The longest word in any of the major English language dictionaries is pneumonoultramicroscopicsilicovolcanoconiosis (45 letters), a word that refers to a lung disease contracted from the inhalation of very fine silica particles,[12] specifically from a volcano; medically, it is the same as silicosis. The word was deliberately coined to be the longest word in English, and has since been used[citation needed] in a close approximation of its originally intended meaning, lending at least some degree of validity to its claim.[6]
    The longest word in any of the major 
    English language dictionaries is 
    pneumonoultramicroscopicsilicovolcanoc
    oniosis (45 letters), a word that 
    refers to a lung disease contracted 
    from the inhalation of very fine silica 
    particles,[12] specifically from a 
    volcano; medically, it is the same as 
    silicosis. The word was deliberately 
    coined to be the longest word in 
    English, and has since been 
    used[citation needed] in a close 
    approximation of its originally 
    intended meaning, lending at least some 
    degree of validity to its claim.[6]
    
Exercise 1-23
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_23/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    /*/* this is a ///* comment */-now it is not
    -now it is not
    "/*this comment is inside quotes!*/"
    "/*this comment is inside quotes!*/"

Exercise 1-24
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_1/exercise-1_24/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out 
    ()[[{()(){}}(([][]))]]
    Balanced separators
    ((){}()
    Unbalanced separators
    (}){}[]
    Unbalanced separators

Notes:

    * We make use of the structure of the previous
      solution 1-23. We just check the balance of the
      separators with `check_separators` whenever we are outside
      strings, constant characters and comments.
    * A `stack data structure <https://en.wikipedia.org/wiki/Stack_(abstract_data_type)>`_
      is implemented with `separatorstack` and `pos` global
      variables and `pushsep` and `popsep` functions. Due to
      its features, its the best data structure to check for
      unbalanced separators.
    * This is the first exercise where we use global variables.
      Until now, variables were local; they are defined inside
      a block `{}`, they came into existence
      only when the block is entered and dissapear when the
      block is exited. Global variables are defined outside
      any block, can be used in any block (previous declaration)
      and remain in existence after the block exited. 
    * In general, it is best to avoid the use of global variable
      and use only when you really need them. This is because
      global variables introduce 
      `side effects <https://en.wikipedia.org/wiki/Side_effect_(computer_science)>`_
      in functional programming.

 .. note::

    **Definition** is where memory is set aside for the variable
    (only once per variable).

    **Declaration** just tell the compiler that the variable exist
    and its type (as many declaration as needed per variable).

    *Local variables* are defined at the beginning of a block 
    and they do not need to be declared since
    their usage is always within the definition scope.

    *Global variables* are defined outside any block and they
    need to be declared if they are used in a block outside
    the definition scope 
    (usage before its definition or usage in other file).
