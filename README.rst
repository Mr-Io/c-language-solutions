Solutions to The C Programming Language - 2nd Edition
=====================================================
.. ini-badges

.. todo: add shields (status bars (travis), code style, tech/framework used, test coverage…)

.. image:: https://img.shields.io/badge/language-C17-blue
  :target: https://en.cppreference.com/w/cpp/17

.. image:: https://img.shields.io/badge/compiler-gcc-orange
  :target: https://gcc.gnu.org/

.. image:: https://img.shields.io/netlify/d704dae8-20ba-4fe2-9dba-0c3564ef402e
  :target: https://clanguage.solutions/

.. image:: https://img.shields.io/github/license/Mr-Io/c-language-solutions
  :target: https://choosealicense.com/licenses/mit/


.. end-badges


.. ini-intro

**This is a comprehensive solution guide for the exercises 
of the classic book**  `The C Programming Language - 2nd Edition`_,
**usually referred to as K&R**.

.. _The C Programming Language - 2nd Edition: https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628

Even though the last edition of K&R (2nd edition) was published in 1988, 
it is still condidered today, by many, 
the very best single book on C, both for learning, and for reference.

The authors *Brian W. Kernighan* and *Dennis M. Ritchie* 
not only presented C in an elegant and pragmatic style, but also
designed a series of exercises on each chapter to help reinforce its knowledge.

The exercises of the book are solved 
staying true to comtemporary K&R C style 
while 
applying modern coding practices.

This repository is just a tribute to K&R. 

.. 1-2 paragraph descrition. what the project is about and motivation (why the project exist)
.. why the project stand out

.. end-intro 

.. ini-links

The solutions are provided in 2 forms and you may be interested in one or both of them:

  * `solutions`_: If you just want to read the code.
  * `documentation`_: If you want to read the solutions in a "book-style" fashion 
    were each exercise and solution is commented, compiled and executed.
    (work in progress)

.. _solutions: https://github.com/Mr-Io/c-language-solutions/tree/master/solutions
.. _documentation: https://clanguage.solutions/

.. end-links

.. ini-cstyle

C Code style
------------
There are lots of C style guides, 
and usually, each project follow its own style, 
for example the 
`linux kernel code style <https://www.kernel.org/doc/html/v4.10/process/coding-style.html>`_ 
or the `style guide for the official python implementation <https://peps.python.org/pep-0007/>`_.

¿Which one to follow? Well, the most important rule regarding code style is: 
*check the surrounding code and try to imitate it*.

Following this principle, we will follow the style implicit in K&R, 
which is known as *K&R style*.
However, in certain situations it became overly terse, 
so we will allow ourselves certain liberties and 
follow some modern "good practices":

  * Prefer slightly more descriptive names than K&R. 
  * Use braces even when C permits them to be omitted.
  * Avoid the use of ``typedef``.

.. end-cstyle

Unsafe Functions
~~~~~~~~~~~~~~~~

.. ini-unsafe

In the solutions, the following unsafe functions are forbidden:

  * ``gets``, ``getwd``
  * ``strcpy``, ``strcat``, ``sprintf`` 

And the following functions must specify a maximun field width 
when formatting string input:

  *  ``scanf``, ``fscanf``, ``vscanf``, ``vfscanf``

.. end-unsafe


Check `unsafe functions docs`_ 
for a more extensive explanation of unsafe functions.

.. _unsafe functions docs: https://clanguage.solutions/#unsafe-functions


C Code optimization
-------------------
We optimize the code of the solutions as much as we can
as long as we do not compromise code readability. 
The solutions use appropiate data structures and algorithms for
the particular problem. 

Additionaly, the solutions follow these 3 coding practices: 
  * *Minimize function calls (and any computation) in loops*
  * *Minimize pointer derefencing (including subscript operator) in loops*
  * *Group struct members of the same type together*

Check `C optimization docs`_ for a more extensive explanation. 

.. _C optimization docs: https://clanguage.solutions/#c-code-optimization

.. ini-comp

Compiler, C version and OS
--------------------------
Currently, there are many `ISO versions of C`_,
in this repository **the code is compiled using
C18 with GNU-specific extensions** (-std=gnu18), 
which is the default in gcc.
Anyway, the code will compile just fine in any C ISO
and, my recommendation is just to
use the C version that your compiler uses by default
(which is generally the newest one).

.. _ISO versions of C: https://www.iso-9899.info/wiki/The_Standard

Regarding compilers, the 2 most popular ones for C are 
`GCC <https://gcc.gnu.org/>`_
and `Clang <https://llvm.org/>`_.
Both of them supports a huge number of extensions and features over the 
language standards. 
GCC is the default compiler for the linux kernel and is even considered
the `defacto-standard open source compiler <https://clang.llvm.org/features.html#gcccompat>`_.
Both of them would be fine but the one used **in this repository is GCC**. 
This is important because in some
exercises of chapter 8 we use 
some specific features of it.

GCC is shipped with almost every Linux distribution, 
it can be easily installed in macOS and
its also supported in Windows 
(with `MinGW <https://www.mingw-w64.org/>`_).

The target OS also became important in chapter 8,
because system calls are used in the solutions.
In this repository, **Linux is used to run the code**, 
but any Unix-like OS like macOS will do just fine. 
Windows is not a Unix-like OS but it can support 
Linux natively with 
`WSL <https://learn.microsoft.com/es-es/windows/wsl/install>`_.

.. end-comp

.. ini-contri

How to contribute
-----------------
One of the repository goals is to be welcoming to beginners 
and to people starting to learn C and GitHub. If it is your first
time consider following a guide to `make your first contribution`_.

.. _make your first contribution: https://github.com/firstcontributions/first-contributions

This repository has only the main branch and
you are very welcome to contribute to it; 
just follow the simple
`fork and pull request <https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request-from-a-fork>`_
method. 

Here is a list of topics that are perfect to start with:
  * Improve solutions code: 

    * bugs
    * style
    * error handling
    * avoid unsafe standard functions (due to overflow) 
    * check integer arithmetics overflow
    * check floating arithmetics underflow/overflow
    * check floating rounding errors
    * refactor
    * optimize using coding principles
    * etc... 

.. todos: 
    consider -ftrapv when compiling, this abort at run time
    if the processor detects any *integer* arithmetic overflow
    instead of continuing executing.

  * Use 
    `Sphinx <https://www.sphinx-doc.org/en/master/>`_
    to build the web and documentation 
    (work in progress).
  * Correct english grammar and/or spelling or improve the wording.
  * Add appropiate badges to the repository.

Changes or improvements unrelated to this are also welcome
and may be done with a pull request.

Once your pull request is merged, 
your contributions will be publicly visible 
on the GitHub repo and on the 
`web page`_,
wich is automatically updated on each commit.

.. _web page: https://clanguage.solutions

.. end-contri
