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

    $ gcc - pg main.c
    $ ./a.out
    binsearch:        1062 clock ticks 
    binsearch1test:    777 clock ticks 

Notes:

    * We use `clock` function from `<stdlib>` to give an approximate 
      measure of CPU time (in clock ticks) used for
      `binsearch` and `binsearch1test` functions.
    * `binsearch1test` is ~1.4x faster than `binsearch`. This suggest
      that the compiler cannot predict very accurately 
      that the last branch of `if-else` statement in `binsearch` is
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

    $ gcc - pg main.c
    $ ./a.out
    \Difficult      subjects cannot be described    with light prose
    \\Difficult\tsubjects cannot be described\twith light prose\n
    \Difficult      subjects cannot be described    with light prose

Notes:

    * Notice that, while we do not need to define the size of `t`
      because it is allocated by `getline` function,
      we do need to define the size of array `s` 
      (dynamic memory allocation is not used until solutions
      of :ref:`chapter-5`)