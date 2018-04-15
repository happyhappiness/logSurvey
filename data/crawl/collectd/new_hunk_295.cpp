	for (c = cpy_init_callbacks; c; c = c->next) {
		ret = PyObject_CallFunctionObjArgs(c->callback, c->data, (void *) 0); /* New reference. */
		if (ret == NULL)
			cpy_log_exception("init callback");
		else
			Py_DECREF(ret);
	}
