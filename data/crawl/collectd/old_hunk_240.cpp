	Py_BEGIN_ALLOW_THREADS;
	ret = plugin_dispatch_values(&value_list);
	Py_END_ALLOW_THREADS;
	if (ret != 0) {
		PyErr_SetString(PyExc_RuntimeError, "error dispatching values, read the logs");
		return NULL;
	}
	free(value);
	Py_RETURN_NONE;
}

