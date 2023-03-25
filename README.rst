Solutions to The C Programming Language - 2nd Edition
=====================================================
.. ini-badges

.. todo: add shields (status bars (travis), code style, tech/framework used, license, version, test coverage…)

|generic shield|

.. |generic shield| image:: https://img.shields.io/badge/shields-todo.svg
    :target: https://shields.io/

.. end-badges

**This is a comprehensive solution guide for the exercises 
of the classic book**  
`The C Programming Language - 2nd Edition <https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628>`_,
**usually referred to as K&R**.

Even though the last edition of K&R (2nd edition) was published in 1988, 
it is still condidered today, by many, 
the very best single book on C, both for learning, and for reference.

The authors *Brian W. Kernighan* and *Dennis M. Ritchie* 
not only presented C in an elegant and pragmatic style, but also
designed a series of exercises on each chapter to help reinforce its knowledge.

.. 1-2 paragraph descrition. what the project is about and motivation (why the project exist)
.. why the project stand out

.. ini-links

This repository is just a tribute to K&R. 
The exercises of the books are solved following modern
good practices but also trying to stay true to the
elegant K&R C style. 
The solutions are provided in 2 forms and you may be interested in one or both of them:
  * `solutions <https://github.com/Mr-Io/c-language-solutions/tree/master/solutions>`_:
    If you just want to read the code.
  * `documentation`_: If you want to read the solution in a "book-style" fashion 
    were each exercise and solution is commented, compiled and executed.
    (work in progress)

.. end-links

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
  * Prefer subscriptor `[]` rather than the use of pointer 
    arithmetics.
  * Avoid the use of `typedef`.

Compiler, C version and OS
--------------------------
Currently, there are 4 `ISO versions of C <https://stackoverflow.com/a/17209532/13695519>`_.
In this repository **the code is compiled using C17**.
Anyway, the code will compile just fine in any C ISO
and, my recommendation is just to
use the C version that your compiler uses by default
(which is generally the newest one).

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

How to contribute
-----------------
This repository is simple, it only has the main branch and
you are very welcome to contribute to it; 
just follow the simple
`fork and pull request <https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request-from-a-fork>`_
method. 

The repository has been created recently and 
there are a lot of thing to do:
  * Improve solutions code: 

    * bugs
    * style
    * error handling
    * integer arithmetics overflow
    * floating arithmetics underflow/overflow
    * floating rounding error
    * refactor
    * etc... 

  * Use 
    `Sphinx <https://www.sphinx-doc.org/en/master/>`_
    to build the web and documentation 
    (work in progress).
  * Correct english grammar and/or spelling or improve the wording.

Changes or improvements unrelated to this are also welcome
and may be done with a pull request.

Once your pull request is merged, 
your contributions will be publicly visible 
on the GitHub repo and on the 
`web page`_,
wich is automatically updated on each commit.


.. _`documentation`: https://c-solutions.netlify.app/
.. _`web page`: https://c-solutions.netlify.app/
