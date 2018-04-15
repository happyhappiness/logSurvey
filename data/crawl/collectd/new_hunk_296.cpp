	PyType_Ready(&ValuesType);
	sys = PyImport_ImportModule("sys"); /* New reference. */
	if (sys == NULL) {
		cpy_log_exception("python initialization");
		return 1;
	}
	sys_path = PyObject_GetAttrString(sys, "path"); /* New reference. */
	Py_DECREF(sys);
	if (sys_path == NULL) {
		cpy_log_exception("python initialization");
		return 1;
	}
	module = Py_InitModule("collectd", cpy_methods); /* Borrowed reference. */
