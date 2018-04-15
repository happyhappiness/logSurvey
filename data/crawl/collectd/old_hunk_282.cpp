	PyType_Ready(&PluginDataType);
	ValuesType.tp_base = &PluginDataType;
	PyType_Ready(&ValuesType);
	sys = PyImport_ImportModule("sys"); /* New reference. */
	if (sys == NULL) {
		cpy_log_exception("python initialization");
