		PyErr_SetString(PyExc_TypeError, "callback needs a be a callable object.");
		return NULL;
	}
	if (name == NULL) {
		PyObject *mod;
		
		mod = PyObject_GetAttrString(callback, "__module__");
		if (mod != NULL) name = PyString_AsString(mod);
		if (name == NULL) {
			PyErr_SetString(PyExc_ValueError, "No module name specified and "
				"callback function does not have a \"__module__\" attribute.");
			return NULL;
		}
	}
	Py_INCREF(callback);
	Py_XINCREF(data);
	c = malloc(sizeof(*c));
	c->name = strdup(name);
	c->callback = callback;
	c->data = data;
	c->next = NULL;
	user_data = malloc(sizeof(*user_data));
	user_data->free_func = cpy_destroy_user_data;
	user_data->data = c;
	plugin_register_log(name, cpy_log_callback, user_data);
	Py_RETURN_NONE;
}

static PyObject *cpy_register_shutdown(PyObject *self, PyObject *args, PyObject *kwds) {
