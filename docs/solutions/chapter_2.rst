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

    FLT_EPSILON:           1.192093e-07
    FLT_MIN:               1.175494e-38
    FLT_MAX:               3.402823e+38

    DBL_EPSILON:           2.220446e-16
    DBL_MIN:              2.225074e-308
    DBL_MAX:              1.797693e+308


Notes:

    * We have no way of computing the ranges of the various 
      floating-point types (at least until :ref:`chapter-6`)
      because we cannot manipulate bits of floating-point variables
      and casting from integer to floating-point modifies the bits.


