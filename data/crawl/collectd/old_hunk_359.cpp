	return PyString_FromString(buf);
}

static PyObject *cpy_register_log(PyObject *self, PyObject *args, PyObject *kwds) {
	return cpy_register_generic_userdata(plugin_register_log, cpy_log_callback, args, kwds);
}
