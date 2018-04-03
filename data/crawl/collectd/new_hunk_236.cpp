			NULL, &plugin, NULL, &host, &t, &severity))
		return NULL;

	notification.time = t;
	notification.severity = severity;
	sstrncpy(notification.message, message ? message : self->message, sizeof(notification.message));
	sstrncpy(notification.host, host ? host : self->data.host, sizeof(notification.host));
	sstrncpy(notification.plugin, plugin ? plugin : self->data.plugin, sizeof(notification.plugin));
	sstrncpy(notification.plugin_instance, plugin_instance ? plugin_instance : self->data.plugin_instance, sizeof(notification.plugin_instance));
	sstrncpy(notification.type, type ? type : self->data.type, sizeof(notification.type));
	sstrncpy(notification.type_instance, type_instance ? type_instance : self->data.type_instance, sizeof(notification.type_instance));
	notification.meta = NULL;
	FreeAll();
	PyMem_Free(message);

	if (notification.type[0] == 0) {
		PyErr_SetString(PyExc_RuntimeError, "type not set");
		return NULL;
	}
	ds = plugin_get_ds(notification.type);
	if (ds == NULL) {
		PyErr_Format(PyExc_TypeError, "Dataset %s not found", notification.type);
		return NULL;
	}

	if (notification.time < 1)
		notification.time = time(0);
	if (notification.host[0] == 0)