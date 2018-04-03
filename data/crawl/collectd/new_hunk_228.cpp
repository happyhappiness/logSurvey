			NULL, &plugin, NULL, &host, &time, &interval, &meta))
		return -1;
	
	if (type && plugin_get_ds(type) == NULL) {
		PyErr_Format(PyExc_TypeError, "Dataset %s not found", type);
		FreeAll();
		return -1;
	}

	sstrncpy(self->data.host, host ? host : "", sizeof(self->data.host));
	sstrncpy(self->data.plugin, plugin ? plugin : "", sizeof(self->data.plugin));
	sstrncpy(self->data.plugin_instance, plugin_instance ? plugin_instance : "", sizeof(self->data.plugin_instance));
	sstrncpy(self->data.type, type ? type : "", sizeof(self->data.type));
	sstrncpy(self->data.type_instance, type_instance ? type_instance : "", sizeof(self->data.type_instance));
	self->data.time = time;

	FreeAll();

	if (values == NULL) {
		values = PyList_New(0);
		PyErr_Clear();
