		Py_CLEAR(v->values);
		v->values = list;
		Py_CLEAR(v->meta);
		v->meta = dict;  /* Steals a reference. */
		ret = PyObject_CallFunctionObjArgs(c->callback, v, c->data, (void *) 0); /* New reference. */
		Py_XDECREF(v);
		if (ret == NULL) {
			cpy_log_exception("write callback");
		} else {
