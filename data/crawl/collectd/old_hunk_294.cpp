	CPY_LOCK_THREADS
		if (PyImport_ImportModule("readline") == NULL) {
			/* This interactive session will suck. */
			PyErr_Print(); /* FIXME */
		}
		PyRun_InteractiveLoop(stdin, "<stdin>");
	CPY_RELEASE_THREADS
