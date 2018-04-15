	PyType_Ready(&ValuesType);
	NotificationType.tp_base = &PluginDataType;
	PyType_Ready(&NotificationType);
	sys = PyImport_ImportModule("sys"); /* New reference. */
	if (sys == NULL) {
		cpy_log_exception("python initialization");
