			}
		} else {
			free(value);
			PyErr_Format(PyExc_RuntimeError, "unknown data type %d for %s", ds->ds->type, type);
			return NULL;
		}
		if (PyErr_Occurred() != NULL) {