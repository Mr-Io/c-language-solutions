Solutions K&R 2nd Edition
=========================

.. include:: ../README.rst
    :start-after: ini-badges
    :end-before: end-badges

.. include:: ../README.rst
    :start-after: ini-intro
    :end-before: end-intro

.. include:: ../README.rst
    :start-after: ini-cstyle
    :end-before: end-cstyle

Unsafe Functions
~~~~~~~~~~~~~~~~
There are some functions in the standard library that are vulnerable
to `buffer overflow`_ attacks. 

If you go to the `man pages`_ (as you should
whenever you use a function) there is a warning if the particular
function is unsafe (for example the first phrase in ``gets``
description section is literally "`Never use this function`_" ) but there are others
that may be vulnerable and have no warning whatsoever,
for example the seemingly correct ``scanf("%s", s)`` is also
vulnerable to buffer overflow and there is no warning on scanf man pages.

.. _buffer overflow: https://owasp.org/www-community/vulnerabilities/Buffer_Overflow
.. _man pages: https://man7.org/linux/man-pages/man1/man.1.html
.. _Never use this function: https://man7.org/linux/man-pages/man3/gets.3.html

.. include:: ../README.rst
    :start-after: ini-unsafe
    :end-before: end-unsafe


For example:

  .. code-block:: c

      char s[MAXSIZE];

      scanf("%*s", MAXSIZE-1, s);

.. note:: 
  
    Modern compiler and OS implement techniques to prevent
    buffer overflow attacks:
    
      * Stack randomization 
        (although brute force is still possible)
      * Limiting executable code regions 
        (although return oriented attacks may work)
      * Smash stack detection 
        (although it is implemented only for the
        functions that the compiler consider, for example gcc 11.3.0 
        use it for ``scanf`` but not for ``gets``)

    Even if buffer overflow attacks were impossible to mount
    (it is not) it is still a bug, so its better to just avoid it. 

.. include:: ../README.rst
    :start-after: ini-comp
    :end-before: end-comp


C Code optimization
-------------------

.. ini-copti

The most important thing of a program is to work correctly,
then to be readable and modular 
(`DRY`_ - Dont Repeat Yourself, easy maintenance, etc... )
and lastly to be efficient and fast.

.. _DRY: https://en.wikipedia.org/wiki/Don%27t_repeat_yourself

We resume optimization in 4 levels:
   * **Level 0**: Use appropiate data structures and algorithms. 
   * **Level 1**: Exploit hardware parallelism (multiproccesing, multithreading, etc..).
   * **Level 2**: Coding principles so that a compiler can generate efficient code.
   * **Level 3**: Exploit processor microarchitecture to 
     maximize performance on the target machine.

Level 0 optimization is a must for every program,
even to the point that we can consider some program 
to only work correctly when
the appropiate data structures and algorithms are used. 
In K&R, computer science knowledge is somewhat assumed.
We dont need to be experts of the subject though,
it can be learned and/or researched 
while reading and doing the exercises.
`CLRS`_ is an excellent reference book for that.
**The solutions use appropiate data structures and algorithms**.

.. _CLRS: https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/ 

*Level 1 optimization is not relevant for this repository*.
   
Level 2 optimization involve code principles so that 
the compiler can generate efficient code. 
**The solutions follow these 3 coding practices**:

  * *Minimize function calls (and any computation) in loops*
    
    For example instead of: 

    .. code-block :: c

      for (i = 0 ; i < strlen(s) ; ++i){
          s[i] = somefunc() + somefunc() + somefunc();
      }
    
    use auxiliary local variables to do this:

    .. code-block :: c

      int len = strlen(s);
      for (i = 0 ; i < len ; ++i){
          s[i] = 3*somefunc();
      }

  * *Minimize pointer derefencing (including subscript operator) in loops*

    For example instead of: 

    .. code-block :: c

      *res = 0;
      for (i = 0 ; i < strlen(s) ; ++i){
          *res += s[i];
      }
    
    use auxiliary local variables to do this:

    .. code-block :: c

      int tmp = 0; 
      for (i = 0 ; i < len ; ++i){
          tmp += s[i];
      }
      *res += tmp;

  * *Group struct members of the same type together*

    .. code-block :: c
      
      struct st {
          int a;
          int b;
          int c;
          char d;
          char e;
          double f;
          double g;
      };

    so that padding is minimized.

Until this point, readability of the solutions has not been 
compromised. However level 3 optimization involves techniques
like: loop unrolling, 
vector instruction optimizations, usage of functional
style when branch prediction is not possible,
minimize cache misses with locality... 
that; 1. make the optimization not portable 
(only maximized for the target machine) and 2. make the code order
of magnitude more complex and less readable. 
Therefore, only in very specific applications are used. 
*The solutions do not follow level 3 optimization techniques*. 

.. include:: ../README.rst
    :start-after: ini-contri
    :end-before: end-contri


.. toctree::
    :maxdepth: 1

    solutions/index

.. toctree::
    :maxdepth: 1

    next

