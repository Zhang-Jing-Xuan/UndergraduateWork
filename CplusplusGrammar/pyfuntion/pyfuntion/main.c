//
//  main.c
//  pyfuntion
//
//  Created by admin on 2021/1/11.
//  Copyright © 2021年 admin. All rights reserved.
//

#include <Python/Python.h>

int great_function_from_python(int a) {
    int res=0;
    PyObject *pModule,*pFunc;
    PyObject *pArgs, *pValue;
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    
    pModule = PyImport_Import(PyString_FromString("great_module"));

    /* great_module.great_function */
    pFunc = PyObject_GetAttrString(pModule, "great_function");

    /* build args */
    pArgs = PyTuple_New(1);
    PyTuple_SetItem(pArgs,0, PyInt_FromLong(a));

    /* call */
    pValue = PyObject_CallObject(pFunc, pArgs);

    res = (int)PyInt_AsLong(pValue);
    return res;
}

int main(int argc, char *argv[]) {
    Py_Initialize();
    printf("%d\n",great_function_from_python(2));
    Py_Finalize();
}
