#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>


int64_t bind_c_factorial_py(int64_t n);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *factorial_py_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int64_t n;
    int64_t fact;
    PyObject *n_tmp;
    PyObject *fact_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "n",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &n_tmp))
    {
        return NULL;
    }
    if (PyIs_NativeInt(n_tmp))
    {
        n = PyInt64_to_Int64(n_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    fact = bind_c_factorial_py(n);
    fact_tmp = Int64_to_PyLong(&fact);
    result = Py_BuildValue("O", fact_tmp);
    Py_DECREF(fact_tmp);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_kyugbhjfgt6e_kyugbhjfgt6e_methods[] = {
    {
        "factorial_py",
        (PyCFunction)factorial_py_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_kyugbhjfgt6e_kyugbhjfgt6e_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_kyugbhjfgt6e_kyugbhjfgt6e_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_kyugbhjfgt6e_kyugbhjfgt6e",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_kyugbhjfgt6e_kyugbhjfgt6e_methods,
    mod_kyugbhjfgt6e_kyugbhjfgt6e_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_kyugbhjfgt6e_kyugbhjfgt6e(void)
{
    import_array();
    return PyModuleDef_Init(&mod_kyugbhjfgt6e_kyugbhjfgt6e_module);
}
