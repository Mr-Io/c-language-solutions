Chapter 2 
=========

Exercise 2-1.
-------------
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

    * In order to determine the ranges by direct computation 
      it is necessary to know the bit representation of the different
      data types.
      Some useful references are 
      `Unsigned and Signed Encodings <https://onlinetoolz.net/unsigned-signed>`_,
      `Two's-Complement Encodings <https://en.wikipedia.org/wiki/Two's_complement>`_ and
      `IEEE Floating-Point Representation <https://www.h-schmidt.net/FloatConverter/IEEE754.html>`_. 

    * Since casting between integer and floats change the bit 
      patterns of the variable, we defined 2 functions that do
      "special casts" without changing the bit pattern
      of the variable:
        
        * `uint2float()` cast from `unsigned int` to `float`.
        * `uint2double()` cast from `long unsigned int` to `double`.

      We are not suppose to know how those 2 functions
      works until we see `unions` in :ref:`chapter-6`
      (another way to do it would be using pointers which are
      explained in :ref:`chapter-5`).

    * Notice that the direct computation of 
      the minimum floating-point number 
      of `float` and `double` give different results than
      the standard headers.
      This is because we have computed the smaller floating-point
      number that we can use before underflowing to 0, while 
      the standard header only defines the smallest *normalized* 
      floating-point number. 

Exercise 2-2.
-------------
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

..  add info about initialization of 
    local, global and static variables and 
    const keywork.