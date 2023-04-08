Chapter 3
=========

Exercise 3-1
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_3/exercise-3_01/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    binsearch:        1062 clock ticks 
    binsearch1test:    777 clock ticks 

Notes:

    * We use ``clock`` function from ``<stdlib>`` to give an approximate 
      measure of CPU time (in clock ticks) used for
      ``binsearch`` and ``binsearch1test`` functions.
    * ``binsearch1test`` is ~1.4x faster than ``binsearch``. This suggest
      that the compiler cannot predict very accurately 
      that the last branch of `if-else` statement in ``binsearch`` is
      only hit once per call at most. So it may cause some 
      missprediction penalty, increasing the CPU time. 
      This can be researched further; 
      `Computer Systems - A Programmer's Perspective`_ 
      is a good introductory book in the subject. 

.. _`Computer Systems - A Programmer's Perspective`: http://csapp.cs.cmu.edu/3e/home.html
      
.. note:: 
      
      **Profiling** is used to learn where a program spent its time,
      to *identify* the parts we should focus on in our optimization
      efforts. 
      It is based on stack sampling technique.

      **Benchmarking** is used to *measure*  two or more competing 
      options, in order to compare them. 
      Different techniques may be used.

      Using a profiler like `gprof`_ to measure the differences in
      run-time of the 2 functions would have been the wrong approach 
      since a profiler should not be used to *measure* performance.

.. _gprof: https://ftp.gnu.org/old-gnu/Manuals/gprof-2.9.1/html_mono/gprof.html

Exercise 3-2
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_3/exercise-3_02/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    \Difficult      subjects cannot be described    with light prose
    \\Difficult\tsubjects cannot be described\twith light prose\n
    \Difficult      subjects cannot be described    with light prose

Notes:

    * Notice that, while we do not need to define the size of ``t``
      because it is allocated by ``getline`` function,
      we do need to define the size of array ``s`` 
      (dynamic memory allocation is not used until solutions
      of :ref:`chapter-5`)

Exercise 3-3
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_3/exercise-3_03/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    Normal usage: a-z k-p 0-9 1-4
    Normal usage: abcdefghijklmnopqrstuvwxyz klmnop 0123456789 1234
    Some things that should not convert: d-c a-4 3-1 b-9 a-Z a--z -z 
    Some things that should not convert: d-c a-4 3-1 b-9 a-Z a--z -z 
    Interesting case: a-z0-9      
    Interesting case: abcdefghijklmnopqrstuvwxyz0123456789
    Interesting cases: -a-d- -4-5- a-b-c-d
    Interesting cases: -abcd- -45- abcd

Notes:

    * We added an additional parameter to the original ``expand`` declaration
      to specify ``s2`` size and avoid buffer overflowing, 
      since it is not possible to know a priori how much
      the string ``s1`` will be expanded. 

.. _exercise-3_04:

Exercise 3-4
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_3/exercise-3_04/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    1234
    1234
    -4321
    -4321
    -2147483648
    -2147483648

Notes:

    * The largest negative number cannot be handled in the book 
      version of ``itoa`` because  ``n = -n;`` fail; 
      there is no positive representation of it
      (``abs(INT_MAX) < abs(INT_MIN)``).
      We convert any negative value into a positive one 
      by bit manipulation instead of using the unary ``-`` operator. 
      We use ``unsigned`` type to manipulate bits, knowing
      that every absolute value of an integer 
      in a two's complement representation can be represented in 
      an unsigned representation.
    * Notice that the maximum lenght of ``s`` 
      is not an aleatory number;
      we use the maximum string length of an integer of at 
      least 8 bytes in a 2 complement representation
      (2**63 has 20 digits including ``-``).
      More precise would have been 
      to take into account the byte length
      of an ``int`` type using ``sizeof`` 
      and to calculate the maximum number of digits.
    * We reuse ``reverse`` function from :ref:`exercise-1_19`.

.. scanf behaviour when input int is too large? Undefined.
   scanf cannot be reliable used for the purpose of input validation.

Useful References:

    * `Unsigned and Signed Encodings`_ 
    * `Two's-Complement Encodings`_


Exercise 3-5
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_3/exercise-3_05/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    15 16
    F
    15 2
    1111
    2147483647 2
    1111111111111111111111111111111
    28 28
    10
    27 28
    R
    111 -3
    error itob: invalid base (-3)


Notes:

    * We use the same estructure as 
      :ref:`exercise-3_04`. One important difference between 
      ``itoa`` and ``itob`` is that ``itob`` return
      an ``int`` to report errors to the caller. 

Useful References:

    * `Unsigned and Signed Encodings`_ 
    * `Two's-Complement Encodings`_ 

Exercise 3-6
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_3/exercise-3_06/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    t 
    1234 1
    1234
    1234 5
     1234
    -123 5
     -123
    -2147483648 15
        -2147483648
    12345 999
    error itoa: 999 too big (max. width: 100)

Notes:

    * We use the code of :ref:`exercise-3_04` 
      and instead of modifying ``itoa`` we make a wrapper function
      ``itoa_v2``.

Useful References:

    * `Unsigned and Signed Encodings`_ 
    * `Two's-Complement Encodings`_ 


.. _Two's-Complement Encodings: https://en.wikipedia.org/wiki/Two's_complement
.. _Unsigned and Signed Encodings: https://onlinetoolz.net/unsigned-signed 