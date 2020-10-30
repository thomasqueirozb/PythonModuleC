# Python C Module example

I created this because there are no easy pre-made examples online on python modules/libraries written in C for python.

I built this using the official documentation which can be found [here](https://docs.python.org/3/extending/extending.html).

## What it includes

- Custom exception (`TestcError`)
- Function that raises the custom exception `TestcError` (`testc_raise_testc_error`)
- Function that uses printf (`testc_print`)
- Function that uses printf to print the first argument as long as it is an integer (`testc_print_int`)
- Function that returns the integer 1 (`testc_return_1`)
- Function that returns the boolean True (`testc_return_true`)

**Note:** the function declaration in C are named `testc_functionname` while in python you would write:

```python
import testc
testc.funtionname()
```

## Creating your own module

This module is named _testc_. If you wish to copy this, you need to change all occurences of _testc_ (be aware of capitalized versions of testc)
