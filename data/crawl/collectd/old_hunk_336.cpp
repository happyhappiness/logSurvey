	Py_RETURN_NONE;
}

static PyObject *Values_repr(PyObject *s) {
	PyObject *ret, *valuestring = NULL;
	Values *self = (Values *) s;
