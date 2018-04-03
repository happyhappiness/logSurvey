		Py_DECREF(list);
		ret = PyObject_CallFunctionObjArgs(c->callback, v, c->data, (void *) 0); /* New reference. */
		if (ret == NULL) {
			/* FIXME */
			PyErr_Print();
		} else {
			Py_DECREF(ret);
		}
