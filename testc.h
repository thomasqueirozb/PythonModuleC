#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *TestcError;
PyObject *testc_print_int(PyObject *self, PyObject *args);
PyObject *testc_print(PyObject *self, PyObject *args);
PyObject *testc_return_1(PyObject *self, PyObject *args);
PyObject *testc_return_true(PyObject *self, PyObject *args);
PyObject *testc_raise_testc_error(PyObject *self, PyObject *args);

static PyMethodDef TestcMethods[] = {
    {"print", testc_print, METH_NOARGS, "Print from c"},
    {"print_int", testc_print_int, METH_VARARGS, "Print integer from c"},
    {"return_1", testc_return_1, METH_NOARGS, "Returns 1"},
    {"return_true", testc_return_true, METH_NOARGS, "Returns True"},
    {"raise_testc_error", testc_raise_testc_error, METH_NOARGS, "Raises TestcError"},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef testcmodule = {PyModuleDef_HEAD_INIT, "testc", /* name of module */
                                         NULL, /* module documentation, may be NULL */
                                         -1,   /* size of per-interpreter state of the module, or -1
                                                  if the module keeps state in global variables. */
                                         TestcMethods};
