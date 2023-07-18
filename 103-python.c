#include <stdio.h>
#include <stdlib.h>
#include <Python.h>


void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        printf("[*] Python list info\n  [ERROR] Invalid List Object\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);

    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PyList_GetItem(p, i);
        const char *type = Py_TYPE(item)->tp_name;
        printf("Element %ld: %s\n", i, type);
    }
}

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        printf("[.] bytes object info\n  [ERROR] Invalid Bytes Object\n");
        return;
    }

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", PyBytes_Size(p));
    printf("  trying string: %s\n", PyBytes_AsString(p));

    printf("  first %ld bytes: ", PyBytes_Size(p) + 1 > 10 ? 10 : PyBytes_Size(p) + 1);
    for (Py_ssize_t i = 0; i < 10 && i < PyBytes_Size(p); i++) {
        printf("%02x ", (unsigned char)PyBytes_AsString(p)[i]);
    }
    printf("\n");
}

void print_python_float(PyObject *p) {
    if (!PyFloat_Check(p)) {
        printf("[.] float object info\n  [ERROR] Invalid Float Object\n");
        return;
    }

    printf("[.] float object info\n");

    double value = PyFloat_AsDouble(p);
    printf("  value: %f\n", value);
}

