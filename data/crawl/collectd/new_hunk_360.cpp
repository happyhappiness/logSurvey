		return NULL;
	}
	if (name == NULL) {
		mod = PyObject_GetAttrString(callback, "__module__"); /* New reference. */
		if (mod != NULL) name = PyString_AsString(mod);
		if (name == NULL) {
			Py_XDECREF(mod);
			PyErr_SetString(PyExc_ValueError, "No module name specified and "
				"callback function does not have a \"__module__\" attribute.");
			return NULL;
