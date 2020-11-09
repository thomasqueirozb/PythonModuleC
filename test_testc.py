import testc


def test_testc_print():
    assert testc.print() == None


def test_testc_print_int():
    assert testc.print_int(123456) == None


def test_testc_return_1():
    retval = testc.return_1()
    assert retval == 1
    assert type(retval) == int


def test_testc_return_True():
    retval = testc.return_true()
    assert retval == True
    assert type(retval) == bool


def test_testc_raise_testc_error():
    try:
        testc.raise_testc_error()
    except testc.TestcError:
        return
    assert 0
