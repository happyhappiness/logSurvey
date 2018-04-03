 	PyType_Ready(&ValuesType);
 	sys = PyImport_ImportModule("sys"); /* New reference. */
 	if (sys == NULL) {
-		ERROR("python module: Unable to import \"sys\" module.");
-		/* Just print the default python exception text to stderr. */
-		PyErr_Print();
+		cpy_log_exception("python initialization");
 		return 1;
 	}
 	sys_path = PyObject_GetAttrString(sys, "path"); /* New reference. */
 	Py_DECREF(sys);
 	if (sys_path == NULL) {
-		ERROR("python module: Unable to read \"sys.path\".");
-		PyErr_Print();
+		cpy_log_exception("python initialization");
 		return 1;
 	}
 	module = Py_InitModule("collectd", cpy_methods); /* Borrowed reference. */
