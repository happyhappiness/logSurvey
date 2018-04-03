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

static PyObject *cpy_Debug(PyObject *self, PyObject *args) {
#ifdef COLLECT_DEBUG
	const char *text;
	if (PyArg_ParseTuple(args, "s", &text) == 0) return NULL;
	plugin_log(LOG_DEBUG, "%s", text);
#endif
	Py_RETURN_NONE;
}

static PyMethodDef cpy_methods[] = {
	{"Debug", cpy_Debug, METH_VARARGS, "This is an unhelpful text."},
	{"Info", cpy_Info, METH_VARARGS, "This is an unhelpful text."},
	{"Notice", cpy_Notice, METH_VARARGS, "This is an unhelpful text."},
	{"Warning", cpy_Warning, METH_VARARGS, "This is an unhelpful text."},
	{"Error", cpy_Error, METH_VARARGS, "This is an unhelpful text."},
	{"register_init", (PyCFunction) cpy_register_init, METH_VARARGS | METH_KEYWORDS, "This is an unhelpful text."},
	{"register_config", (PyCFunction) cpy_register_config, METH_VARARGS | METH_KEYWORDS, "This is an unhelpful text."},
	{"register_shutdown", (PyCFunction) cpy_register_shutdown, METH_VARARGS | METH_KEYWORDS, "This is an unhelpful text."},