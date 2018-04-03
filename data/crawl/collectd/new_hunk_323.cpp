	const char *name;
	cpy_callback_t *prev = NULL, *tmp;

	Py_INCREF(arg);
	name = cpy_unicode_or_bytes_to_string(&arg);
	if (name == NULL) {
		PyErr_Clear();
		if (!PyCallable_Check(arg)) {
			PyErr_SetString(PyExc_TypeError, "This function needs a string or a callable object as its only parameter.");
			Py_DECREF(arg);
			return NULL;
		}
		cpy_build_name(buf, sizeof(buf), arg, NULL);
