 	PyObject *values = self->values, *meta = self->meta;
 	double time = self->data.time;
 	int interval = self->interval;
-	const char *host = self->data.host;
-	const char *plugin = self->data.plugin;
-	const char *plugin_instance = self->data.plugin_instance;
-	const char *type = self->data.type;
-	const char *type_instance = self->data.type_instance;
-	const char *dest = NULL;
+	char *host = NULL, *plugin = NULL, *plugin_instance = NULL, *type = NULL, *type_instance = NULL, *dest = NULL;
 	
 	static char *kwlist[] = {"destination", "type", "values", "plugin_instance", "type_instance",
 			"plugin", "host", "time", "interval", "meta", NULL};
-	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|etOetetetetdiO", kwlist,
+	if (!PyArg_ParseTupleAndKeywords(args, kwds, "et|etOetetetetdiO", kwlist, NULL, &dest,
 			NULL, &type, &values, NULL, &plugin_instance, NULL, &type_instance,
 			NULL, &plugin, NULL, &host, &time, &interval, &meta))
 		return NULL;
 
-	if (type[0] == 0) {
+	sstrncpy(value_list.host, host ? host : self->data.host, sizeof(value_list.host));
+	sstrncpy(value_list.plugin, plugin ? plugin : self->data.plugin, sizeof(value_list.plugin));
+	sstrncpy(value_list.plugin_instance, plugin_instance ? plugin_instance : self->data.plugin_instance, sizeof(value_list.plugin_instance));
+	sstrncpy(value_list.type, type ? type : self->data.type, sizeof(value_list.type));
+	sstrncpy(value_list.type_instance, type_instance ? type_instance : self->data.type_instance, sizeof(value_list.type_instance));
+	FreeAll();
+	if (value_list.type[0] == 0) {
 		PyErr_SetString(PyExc_RuntimeError, "type not set");
 		return NULL;
 	}
-	ds = plugin_get_ds(type);
+	ds = plugin_get_ds(value_list.type);
 	if (ds == NULL) {
-		PyErr_Format(PyExc_TypeError, "Dataset %s not found", type);
+		PyErr_Format(PyExc_TypeError, "Dataset %s not found", value_list.type);
 		return NULL;
 	}
 	if (values == NULL || (PyTuple_Check(values) == 0 && PyList_Check(values) == 0)) {
