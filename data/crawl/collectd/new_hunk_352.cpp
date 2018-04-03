	CPY_LOCK_THREADS
		if (PyImport_ImportModule("readline") == NULL) {
			/* This interactive session will suck. */
			cpy_log_exception("interactive session init");
		}
		PyRun_InteractiveLoop(stdin, "<stdin>");
	CPY_RELEASE_THREADS
