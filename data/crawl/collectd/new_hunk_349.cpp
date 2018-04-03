				CPY_RETURN_FROM_THREADS 0;
			}
			if (PyErr_Occurred() != NULL) {
				cpy_log_exception("value building for write callback");
				CPY_RETURN_FROM_THREADS 0;
			}
		}
