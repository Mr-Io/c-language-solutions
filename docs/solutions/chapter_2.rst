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

  * We have used the qualifier `const` for the first time:
     
    .. code-block :: c

      	const int lim = MAXLINE;

    It simply indicates that the value of `lim` will not 
    be changed. The compiler makes an
    error if you try to modify a read-only variable. 
    You should initialize
    read-only variables as it is the only way to assign a useful
    value to them.


.. note:: 

    `const` can be applied to variables to specify that its value
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

      long unsigned strnlen(const char *s, long unsigned n);

    From this exercise onwards,
    we will make use of the `const` qualifier when a variable
    should remain constant. 

..  add info about initialization of 
    local, global and static variables and 
    keywork.


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

  * We make use of `getword` function from :ref:`exercise-1_22` 
    for outputing.

..  add info about type conversion, casting
    and implicit casting.