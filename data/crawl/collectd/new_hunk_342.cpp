	Py_RETURN_NONE;
}

static PyObject *cpy_unregister_generic(cpy_callback_t **list_head, PyObject *arg, const char *desc, int short_name) {
	char buf[512];
	const char *name;
	cpy_callback_t *prev = NULL, *tmp;

	if (PyString_Check(arg)) {
		name = PyString_AsString(arg);
	} else {
		if (!PyCallable_Check(arg)) {
			PyErr_SetString(PyExc_TypeError, "This function needs a string or a callable object as its only parameter.");
			return NULL;
		}
		cpy_build_name(buf, sizeof(buf), arg, NULL, short_name);
		name = buf;
	}
	for (tmp = *list_head; tmp; prev = tmp, tmp = tmp->next)
		if (strcmp(name, tmp->name) == 0)
			break;
	
	if (tmp == NULL) {
		PyErr_Format(PyExc_RuntimeError, "Unable to unregister %s callback '%s'.", desc, name);
		return NULL;
	}
	/* Yes, this is actually save. To call this function the calles has to
	 * hold the GIL. Well, save as long as there is only one GIL anyway ... */
	if (prev == NULL)
		*list_head = tmp->next;
	else
		prev->next = tmp->next;
	cpy_destroy_user_data(tmp);
	Py_RETURN_NONE;
}

typedef int cpy_unregister_function_t(const char *name);

static PyObject *cpy_unregister_generic_userdata(cpy_unregister_function_t *unreg, PyObject *arg, const char *desc, int short_name) {
	char buf[512];
	const char *name;

	if (PyString_Check(arg)) {
		name = PyString_AsString(arg);
	} else {
		if (!PyCallable_Check(arg)) {
			PyErr_SetString(PyExc_TypeError, "This function needs a string or a callable object as its only parameter.");
			return NULL;
		}
		cpy_build_name(buf, sizeof(buf), arg, NULL, short_name);
		name = buf;
	}
	if (unreg(name) == 0)
		Py_RETURN_NONE;
	PyErr_Format(PyExc_RuntimeError, "Unable to unregister %s callback '%s'.", desc, name);
	return NULL;
}

static PyObject *cpy_unregister_log(PyObject *self, PyObject *arg) {
	return cpy_unregister_generic_userdata(plugin_unregister_log, arg, "log", 0);
}

static PyObject *cpy_unregister_init(PyObject *self, PyObject *arg) {
	return cpy_unregister_generic(&cpy_init_callbacks, arg, "init", 0);
}

static PyObject *cpy_unregister_config(PyObject *self, PyObject *arg) {
	return cpy_unregister_generic(&cpy_config_callbacks, arg, "config", 1);
}

static PyObject *cpy_unregister_read(PyObject *self, PyObject *arg) {
	return cpy_unregister_generic_userdata(plugin_unregister_read, arg, "read", 0);
}

static PyObject *cpy_unregister_write(PyObject *self, PyObject *arg) {
	return cpy_unregister_generic_userdata(plugin_unregister_write, arg, "write", 0);
}

static PyObject *cpy_unregister_flush(PyObject *self, PyObject *arg) {
	return cpy_unregister_generic_userdata(plugin_unregister_flush, arg, "flush", 1);
}

static PyObject *cpy_unregister_shutdown(PyObject *self, PyObject *arg) {
	return cpy_unregister_generic(&cpy_shutdown_callbacks, arg, "shutdown", 0);
}

static PyMethodDef cpy_methods[] = {
	{"debug", cpy_debug, METH_VARARGS, "This is an unhelpful text."},
	{"info", cpy_info, METH_VARARGS, "This is an unhelpful text."},
