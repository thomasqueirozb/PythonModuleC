import testc


def testc_print():
    assert testc.print() == None


def testc_print_int():
    assert testc.print_int(123456) == None


def testc_return_1():
    retval = testc.return_1()
    assert retval == 1
    assert type(retval) == int


def testc_return_True():
    retval = testc.return_true()
    assert retval == True
    assert type(retval) == bool


def testc_raise_testc_error():
    try:
        testc.raise_testc_error()
    except testc.TestcError:
        return
    assert 0
