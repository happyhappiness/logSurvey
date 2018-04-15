	const char *name;
	cpy_callback_t *prev = NULL, *tmp;

	if (PyUnicode_Check(arg)) {
		arg = PyUnicode_AsEncodedString(arg, NULL, NULL);
		if (arg == NULL)
			return NULL;
		name = PyString_AsString(arg);
		Py_DECREF(arg);
	} else if (PyString_Check(arg)) {
		name = PyString_AsString(arg);
	} else {
		if (!PyCallable_Check(arg)) {
			PyErr_SetString(PyExc_TypeError, "This function needs a string or a callable object as its only parameter.");
			return NULL;
		}
		cpy_build_name(buf, sizeof(buf), arg, NULL);
