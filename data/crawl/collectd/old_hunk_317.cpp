
static PyObject *cpy_notice(PyObject *self, PyObject *args) {
	const char *text;
	if (PyArg_ParseTuple(args, "s", &text) == 0) return NULL;
	Py_BEGIN_ALLOW_THREADS
	plugin_log(LOG_NOTICE, "%s", text);
	Py_END_ALLOW_THREADS