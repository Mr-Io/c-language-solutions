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

.. _DRY: <https://en.wikipedia.org/wiki/Don%27t_repeat_yourself>

Our objective is to optimize the code as much as we can
as long as we do not reduce code readability and modularity. 
For that, we resume optimization in 4 levels:
   * **Level 0**: Use appropiate data structures and algorithms. 
   * **Level 1**: Exploit hardware parallelism (multiproccesing, multithreading, etc..).
   * **Level 2**: Coding principles so that a compiler can generate efficient code.
   * **Level 3**: Exploit single-flow processor microarchitecture to 
     maximize performance on the target machine.

Level 0 optimization is a must for every program,
even to the point that we can consider some program 
to only work correctly when
the appropiate data structures and algorithms are used. 
In K&R, computer science knowledge is somewhat assumed on the lector.
The good news is that we dont need to be experts of the subject,
it can be learned
and/or researched while reading and doing the exercises.
`CLRS`_ is an excellent reference book for that.

.. _CLRS: https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/ 

Level 1 optimization is not relevant for this repository.

Level 3 optimization involves loop unrolling, 
vector instruction optimizations, usage of functional
style when branch prediction is not possible, 
and other techniques that; 1. make the optimization not portable 
(only maximized for the target machine) and 2. make the code order
of magnitude more complex and less readable. 
Therefore, only in very specific application is used and 
certainly not in these solutions. 
    
For Level 2 optimization we need to follow a few simple coding principles
to generate efficient C code for the compiler to optimize.
The solutions follow these principles which are:

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

  * *Declare struct members of the same type together*

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


.. include:: ../README.rst
    :start-after: ini-contri
    :end-before: end-contri


.. toctree::
   :maxdepth: 1

   solutions/index

