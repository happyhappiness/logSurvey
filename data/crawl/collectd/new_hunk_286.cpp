		PyErr_SetString(PyExc_TypeError, "callback needs a be a callable object.");
		return NULL;
	}
	cpy_build_name(buf, sizeof(buf), callback, name, short_name);

	Py_INCREF(callback);
	Py_XINCREF(data);
	c = malloc(sizeof(*c));
	c->name = strdup(buf);
	c->callback = callback;
	c->data = data;
	c->next = *list_head;
	*list_head = c;
	Py_XDECREF(mod);
	return PyString_FromString(buf);
}

static PyObject *cpy_flush(cpy_callback_t **list_head, PyObject *args, PyObject *kwds) {
	int timeout = -1;
	const char *plugin = NULL, *identifier = NULL;
	static char *kwlist[] = {"plugin", "timeout", "identifier", NULL};
	
	if (PyArg_ParseTupleAndKeywords(args, kwds, "|ziz", kwlist, &plugin, &timeout, &identifier) == 0) return NULL;
	Py_BEGIN_ALLOW_THREADS
	plugin_flush(plugin, timeout, identifier);
	Py_END_ALLOW_THREADS
	Py_RETURN_NONE;
}

static PyObject *cpy_register_config(PyObject *self, PyObject *args, PyObject *kwds) {
	return cpy_register_generic(&cpy_config_callbacks, args, kwds, 1);
}

static PyObject *cpy_register_init(PyObject *self, PyObject *args, PyObject *kwds) {
	return cpy_register_generic(&cpy_init_callbacks, args, kwds, 0);
}

typedef int reg_function_t(const char *name, void *callback, void *data);

static PyObject *cpy_register_generic_userdata(void *reg, void *handler, PyObject *args, PyObject *kwds, int short_name) {
	char buf[512];
	reg_function_t *register_function = (reg_function_t *) reg;
	cpy_callback_t *c = NULL;
