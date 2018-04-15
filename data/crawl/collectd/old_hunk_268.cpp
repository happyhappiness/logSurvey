		cpy_log_exception("python initialization");
		return 1;
	}
	module = Py_InitModule("collectd", cpy_methods); /* Borrowed reference. */
	PyModule_AddObject(module, "Config", (void *) &ConfigType); /* Steals a reference. */
	PyModule_AddObject(module, "Values", (void *) &ValuesType); /* Steals a reference. */
	PyModule_AddObject(module, "Notification", (void *) &NotificationType); /* Steals a reference. */
