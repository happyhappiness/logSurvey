	CPY_RELEASE_THREADS
}

static PyObject *cpy_register_generic(cpy_callback_t **list_head, PyObject *args, PyObject *kwds) {
	cpy_callback_t *c;
	const char *name = NULL;
	PyObject *callback = NULL, *data = NULL, *mod = NULL;
