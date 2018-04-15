			NULL, &plugin, NULL, &host, &time, &interval, &meta))
		return NULL;

	sstrncpy(value_list.host, host ? host : self->data.host, sizeof(value_list.host));
	sstrncpy(value_list.plugin, plugin ? plugin : self->data.plugin, sizeof(value_list.plugin));
	sstrncpy(value_list.plugin_instance, plugin_instance ? plugin_instance : self->data.plugin_instance, sizeof(value_list.plugin_instance));
	sstrncpy(value_list.type, type ? type : self->data.type, sizeof(value_list.type));
	sstrncpy(value_list.type_instance, type_instance ? type_instance : self->data.type_instance, sizeof(value_list.type_instance));
	FreeAll();
	if (value_list.type[0] == 0) {
		PyErr_SetString(PyExc_RuntimeError, "type not set");
		FreeAll();
		return NULL;
	}
	ds = plugin_get_ds(value_list.type);
	if (ds == NULL) {
		PyErr_Format(PyExc_TypeError, "Dataset %s not found", value_list.type);
		return NULL;
	}
	if (values == NULL || (PyTuple_Check(values) == 0 && PyList_Check(values) == 0)) {
