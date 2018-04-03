		return NULL;
	}
	if (name == NULL) {
		PyObject *mod;
		
		mod = PyObject_GetAttrString(callback, "__module__");
		if (mod != NULL) name = PyString_AsString(mod);
		if (name == NULL) {
			PyErr_SetString(PyExc_ValueError, "No module name specified and "
				"callback function does not have a \"__module__\" attribute.");
			return NULL;
