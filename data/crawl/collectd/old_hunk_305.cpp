	return cpy_register_generic(&cpy_init_callbacks, args, kwds);
}

static PyObject *cpy_register_shutdown(PyObject *self, PyObject *args, PyObject *kwds) {
	return cpy_register_generic(&cpy_shutdown_callbacks, args, kwds);
}

static PyObject *cpy_Error(PyObject *self, PyObject *args) {
	const char *text;
	if (PyArg_ParseTuple(args, "s", &text) == 0) return NULL;
	plugin_log(LOG_ERR, "%s", text);
	Py_RETURN_NONE;
}

static PyObject *cpy_Warning(PyObject *self, PyObject *args) {
	const char *text;
	if (PyArg_ParseTuple(args, "s", &text) == 0) return NULL;
	plugin_log(LOG_WARNING, "%s", text);
	Py_RETURN_NONE;
}

static PyObject *cpy_Notice(PyObject *self, PyObject *args) {
	const char *text;
	if (PyArg_ParseTuple(args, "s", &text) == 0) return NULL;
	plugin_log(LOG_NOTICE, "%s", text);
	Py_RETURN_NONE;
}

static PyObject *cpy_Info(PyObject *self, PyObject *args) {
	const char *text;
	if (PyArg_ParseTuple(args, "s", &text) == 0) return NULL;
	plugin_log(LOG_INFO, "%s", text);
	Py_RETURN_NONE;
}

