Chapter 2 
=========

Exercise 2-1
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_2/exercise-2_01/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    (In this machine 'char == signed char')
                        standard header      direct computation
                        ---------------      ------------------
    UCHAR_MAX:                      255                     255
    SCHAR_MIN:                     -128                    -128
    SCHAR_MAX:                      127                     127
    CHAR_MIN:                      -128                    -128
    CHAR_MAX:                       127                     127

    USHRT_MAX:                    65535                   65535
    SHRT_MIN:                    -32768                  -32768
    SHRT_MAX:                     32767                   32767
    UINT_MAX:                4294967295              4294967295
    INT_MIN:                -2147483648             -2147483648
    INT_MAX:                 2147483647              2147483647
    ULONG_MAX:     18446744073709551615    18446744073709551615
    LONG_MIN:      -9223372036854775808    -9223372036854775808
    LONG_MAX:       9223372036854775807     9223372036854775807

    FLT_MIN:               1.175494e-38            1.401298e-45
    FLT_MAX:               3.402823e+38            3.402823e+38

    DBL_MIN:              2.225074e-308           4.940656e-324
    DBL_MAX:              1.797693e+308           1.797693e+308 


Notes:

    * Since casting between integer and floats change the bit 
      patterns of the variable, we defined 2 functions that do
      "special casts" without changing the bit pattern
      of the variable:
        
        * ``uint2float()`` cast from ``unsigned int`` to ``float``.
        * ``uint2double()`` cast from ``long unsigned int`` to ``double``.

      We are not suppose to know how those 2 functions
      works until we see ``union`` in :ref:`chapter-6`
      (another way to do it would be using pointers which are
      explained in :ref:`chapter-5`).

    * Notice that the direct computation of 
      the minimum floating-point number 
      of ``float`` and ``double`` give different results than
      the standard headers.
      This is because we have computed the smaller floating-point
      number that we can use before underflowing to 0, while 
      the standard header only defines the smallest *normalized* 
      floating-point number. 
    
Useful References:

    * `Unsigned and Signed Encodings <https://onlinetoolz.net/unsigned-signed>`_
    * `Two's-Complement Encodings <https://en.wikipedia.org/wiki/Two's_complement>`_
    * `IEEE Floating-Point Representation <https://www.h-schmidt.net/FloatConverter/IEEE754.html>`_


Exercise 2-2
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_2/exercise-2_02/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    short-circuiting of && and || is nice.
    short-circuiting of && and || is nice.
  
Notes:

  * We have used the qualifier ``const`` for the first time:
     
    .. code-block :: c

      	const int lim = MAXLINE;

    It simply indicates that the value of ``lim`` will not 
    be changed. The compiler makes an
    error if you try to modify a read-only variable. 
    You should initialize
    read-only variables as it is the only way to assign a useful
    value to them.


.. note:: 

    ``const`` can be applied to variables to specify that its value
    will not be changed during its lifetime. 
    When applied to an array, it indicates that its elements will
    not be altered:

    .. code-block:: c

      const int arr[5] = {1, 2, 3, 4, 5};
      arr[3] = 2; /* error */
    
    It can be applied to function parameters and it is particulary 
    useful to indicate that a function does not change 
    the elements of some argument array:

    .. code-block:: c

      long unsigned strnlen(const char s[], long unsigned n);

    From this exercise onwards,
    we will make use of the ``const`` qualifier when a variable
    should remain constant. 

..  add info about initialization of 
    local, global and static variables and 
    keywork.

..  inline functions: A reasonable rule of thumb is only use static inline 
    and for functions that have less than 3 lines of code in them.
    Prefer static inline functions to macros.

Exercise 2-3
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_2/exercise-2_03/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    0x1 0X2 0xa 0xFF ff 5 hello 0x11 0xFg
    1
    2
    10
    255
    255
    5
    -1
    17
    -1

Notes:

  * We make use of ``getword`` function from :ref:`exercise-1_22` 
    for outputing.

..  add info about type conversion, casting
    and implicit casting.

Exercise 2-4
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_2/exercise-2_04/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    Confusion is part of programming
    aeiou
    Cnfsn s prt f prgrmmng

..  add info about the use of unitary operators ++ --, 
    best code practices?

Exercise 2-5
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_2/exercise-2_05/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    fly slyly in the sky.
    aeiou
    position: 10

Notes:

  * We make use of the structure of previous solution; only a
    singe function is changed. This is an outcome of 
    making solutions code modular (by using functions for 
    each specific job).

..  possibly talk about modularity, examples and why is it good

Exercise 2-6
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_2/exercise-2_06/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    0xF 1 1 0x0
    0x0000000D
    0x0 4 1 0xFF
    0x00000010

Notes:

  * For position ``p`` we start counting from the right
    (being the rightmost position ``0``), as it is done 
    with the code example of Section 2.9 K&R.
  * It is good practice to use ``unsigned`` when manipulating bits 
    because rightshifting negative values is 
    implementation-defined. For example:
    
    .. code-block:: c

      a >> n;

    may have different results with different compilers
    when ``a`` is negative.

Exercise 2-7
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_2/exercise-2_07/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    0x0 1 1
    0x00000002
    0x0 0 1
    0x00000001
    0x10 3 4
    0x0000001F

Exercise 2-8
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_2/exercise-2_08/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    0x1 1
    0x80000000
    0x3 2
    0xC0000000
    0xFF 8
    0xFF000000
    0xFF 16
    0x00FF0000

Exercise 2-9
------------
*main.c*

.. literalinclude :: ../../solutions/chapter_2/exercise-2_09/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    0xF
    4
    0x1
    1
    0x3
    2
    0xF0F0
    8

Exercise 2-10
-------------
*main.c*

.. literalinclude :: ../../solutions/chapter_2/exercise-2_10/main.c
    :language: c
    :tab-width: 4

Compilation and run:

.. code-block :: console

    $ gcc main.c
    $ ./a.out
    EXPLICIT IS BETTER THAN IMPLICIT.
    explicit is better than implicit.
    Simple Is Better Than Complex.
    simple is better than complex.
    CoMpLeX Is bEtTeR ThAn cOmPlIcAtEd.
    complex is better than complicated.

Notes: 

  * We use for the first time the terniary operator:
    
    .. code-block:: c

        return (c < 'A' || c > 'Z') ? c : c + 'a' - 'A';
    
    is equivalent to:

    .. code-block:: c

        if (c < 'A' || c > 'Z'){
          return c;
        }else{
          return c + 'a' - 'A';
        }  
