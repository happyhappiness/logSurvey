	Py_XDECREF(n);
}

static int cpy_read_callback(user_data_t *data) {
	cpy_callback_t *c = data->data;
	PyObject *ret;

	CPY_LOCK_THREADS
		ret = PyObject_CallFunctionObjArgs(c->callback, c->data, (void *) 0); /* New reference. */
		if (ret == NULL) {
			/* FIXME */
			PyErr_Print();
		} else {
			Py_DECREF(ret);
		}
