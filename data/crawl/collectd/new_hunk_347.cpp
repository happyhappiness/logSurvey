	Py_XDECREF(n);
}

static void cpy_log_exception(const char *context) {
	int l = 0, i;
	const char *typename = NULL, *message = NULL;
	PyObject *type, *value, *traceback, *tn, *m, *list;
	
	PyErr_Fetch(&type, &value, &traceback);
	PyErr_NormalizeException(&type, &value, &traceback);
	if (type == NULL) return;
	tn = PyObject_GetAttrString(type, "__name__"); /* New reference. */
	m = PyObject_GetAttrString(value, "message"); /* New reference. */
	if (tn != NULL)
		typename = PyString_AsString(tn);
	if (m != NULL)
		message = PyString_AsString(m);
	if (typename == NULL)
		typename = "NamelessException";
	if (message == NULL)
		message = "N/A";
	ERROR("Unhandled python exception in %s: %s: %s", context, typename, message);
	Py_XDECREF(tn);
	Py_XDECREF(m);
	if (!cpy_format_exception) {
		PyErr_Clear();
		Py_XDECREF(type);
		Py_XDECREF(value);
		Py_XDECREF(traceback);
		return;
	}
	if (!traceback) {
		PyErr_Clear();
		return;
	}
	list = PyObject_CallFunction(cpy_format_exception, "NNN", type, value, traceback);
	if (list)
		l = PyObject_Length(list);
	for (i = 0; i < l; ++i) {
		char *s;
		PyObject *line;
		
		line = PyList_GET_ITEM(list, i);
		s = strdup(PyString_AsString(line));
		Py_DECREF(line);
		if (s[strlen(s) - 1] == '\n')
			s[strlen(s) - 1] = 0;
		ERROR("%s", s);
		free(s);
	}
	PyErr_Clear();
}

static int cpy_read_callback(user_data_t *data) {
	cpy_callback_t *c = data->data;
	PyObject *ret;

	CPY_LOCK_THREADS
		ret = PyObject_CallFunctionObjArgs(c->callback, c->data, (void *) 0); /* New reference. */
		if (ret == NULL) {
			cpy_log_exception("read callback");
		} else {
			Py_DECREF(ret);
		}
