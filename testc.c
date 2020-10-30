#define PY_SSIZE_T_CLEAN
#include "testc.h"
#include <Python.h>

PyObject *testc_print(PyObject *self, PyObject *args) {
    /* if (!PyArg_ParseTuple(args, "")) return NULL; */
    printf("Print from C!\n");
    return Py_None;
}

PyObject *testc_print_int(PyObject *self, PyObject *args) {

    /* int *i = malloc(sizeof(int)); */
    int i;

    if (!PyArg_ParseTuple(args, "i", &i)) return NULL;
    printf("Print from C! -- %i\n", i);
    /* printf("Print from C! -- %i\n", *i); */
    return Py_None;
}

PyObject *testc_return_1(PyObject *self, PyObject *args) { return PyLong_FromLong(1l); }

PyObject *testc_return_true(PyObject *self, PyObject *args) { return Py_True; }

PyObject *testc_raise_testc_error(PyObject *self, PyObject *args) {
    PyErr_SetString(TestcError, "Error from C");
    return NULL;
}

PyMODINIT_FUNC PyInit_testc(void) {
    PyObject *m;

    m = PyModule_Create(&testcmodule);
    if (m == NULL) return NULL;

    TestcError = PyErr_NewException("testc.TestcError", NULL, NULL);
    Py_XINCREF(TestcError);
    if (PyModule_AddObject(m, "TestcError", TestcError) < 0) {
        Py_XDECREF(TestcError);
        Py_CLEAR(TestcError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
