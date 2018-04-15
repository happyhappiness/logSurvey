				CPY_RETURN_FROM_THREADS 0;
			}
			if (PyErr_Occurred() != NULL) {
				PyErr_Print();
				CPY_RETURN_FROM_THREADS 0;
			}
		}
