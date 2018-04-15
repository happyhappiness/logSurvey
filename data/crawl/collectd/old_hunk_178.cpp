			NULL, &plugin, NULL, &host, &t, &severity))
		return NULL;

	if (type[0] == 0) {
		PyErr_SetString(PyExc_RuntimeError, "type not set");
		return NULL;
	}
	ds = plugin_get_ds(type);
	if (ds == NULL) {
		PyErr_Format(PyExc_TypeError, "Dataset %s not found", type);
		return NULL;
	}

	notification.time = t;
	notification.severity = severity;
	sstrncpy(notification.message, message, sizeof(notification.message));
	sstrncpy(notification.host, host, sizeof(notification.host));
	sstrncpy(notification.plugin, plugin, sizeof(notification.plugin));
	sstrncpy(notification.plugin_instance, plugin_instance, sizeof(notification.plugin_instance));
	sstrncpy(notification.type, type, sizeof(notification.type));
	sstrncpy(notification.type_instance, type_instance, sizeof(notification.type_instance));
	notification.meta = NULL;
	if (notification.time < 1)
		notification.time = time(0);
	if (notification.host[0] == 0)