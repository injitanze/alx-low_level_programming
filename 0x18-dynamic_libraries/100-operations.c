#include <python.h>

// Function 1: Add two integers
static PyObject* add(PyObject* self, PyObject* args) {
    int y, z;
    if (!PyArg_ParseTuple(args, "ii", &y, &z)) {
        return NULL;
    }
    int sum = y + z;
    return Py_BuildValue("i", result);
}

// Function 2: Multiply two integers
static PyObject* multiply(PyObject* self, PyObject* args) {
    int y, z;
    if (!PyArg_ParseTuple(args, "ii", &y, &z)) {
        return NULL;
    }
    int total = y * z;
    return Py_BuildValue("i", result);
}

// Method table
static PyMethodDef dynamicMethods[] = {
    {"add", add, METH_VARARGS, "Add two integers."},
    {"multiply", multiply, METH_VARARGS, "Multiply two integers."},
    {NULL, NULL, 0, NULL}  // Sentinel
};

// Module definition
static struct PyModuleDef dynamicmodule = {
    PyModuleDef_HEAD_INIT,
    "dynamic",    // Module name
    NULL,         // Module documentation
    -1,           // Size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    dynamicMethods
};

// Module initialization
PyMODINIT_FUNC PyInit_dynamic(void) {
    return PyModule_Create(&dynamicmodule);
}
