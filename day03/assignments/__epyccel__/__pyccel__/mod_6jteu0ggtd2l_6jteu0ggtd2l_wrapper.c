#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include "cwrapper_ndarrays.h"


int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *jacobi_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray a = {.shape = NULL};
    t_ndarray b = {.shape = NULL};
    t_ndarray x = {.shape = NULL};
    int64_t n;
    double eps;
    double stand;
    int64_t iteration;
    PyArrayObject *a_tmp;
    PyArrayObject *b_tmp;
    PyArrayObject *x_tmp;
    PyObject *n_tmp;
    PyObject *eps_tmp;
    PyObject *stand_tmp;
    PyObject *iteration_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "a",
        "b",
        "x",
        "n",
        "eps",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!O!OO", kwlist, &PyArray_Type, &a_tmp, &PyArray_Type, &b_tmp, &PyArray_Type, &x_tmp, &n_tmp, &eps_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(a_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        a = pyarray_to_ndarray(a_tmp);
    }
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 1, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
    }
    if (!pyarray_check(x_tmp, NPY_DOUBLE, 1, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        x = pyarray_to_ndarray(x_tmp);
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
    if (PyIs_NativeFloat(eps_tmp))
    {
        eps = PyDouble_to_Double(eps_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    jacobi(a, b, x, n, eps, &stand, &iteration);
    stand_tmp = Double_to_PyDouble(&stand);
    iteration_tmp = Int64_to_PyLong(&iteration);
    result = Py_BuildValue("OO", stand_tmp, iteration_tmp);
    Py_DECREF(stand_tmp);
    Py_DECREF(iteration_tmp);
    free_pointer(a);
    free_pointer(b);
    free_pointer(x);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_6jteu0ggtd2l_6jteu0ggtd2l_methods[] = {
    {
        "jacobi",
        (PyCFunction)jacobi_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_6jteu0ggtd2l_6jteu0ggtd2l_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_6jteu0ggtd2l_6jteu0ggtd2l_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_6jteu0ggtd2l_6jteu0ggtd2l",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_6jteu0ggtd2l_6jteu0ggtd2l_methods,
    mod_6jteu0ggtd2l_6jteu0ggtd2l_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_6jteu0ggtd2l_6jteu0ggtd2l(void)
{
    import_array();
    return PyModuleDef_Init(&mod_6jteu0ggtd2l_6jteu0ggtd2l_module);
}
