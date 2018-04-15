				ret = PyObject_CallFunction(c->callback, "NO",
					cpy_oconfig_to_pyconfig(item, NULL), c->data); /* New reference. */
			if (ret == NULL)
				cpy_log_exception("loading module");
			else
				Py_DECREF(ret);
		} else {