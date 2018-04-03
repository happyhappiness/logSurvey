		if (strcmp(name, tmp->name) == 0)
			break;
	
	Py_DECREF(arg);
	if (tmp == NULL) {
		PyErr_Format(PyExc_RuntimeError, "Unable to unregister %s callback '%s'.", desc, name);
		return NULL;
