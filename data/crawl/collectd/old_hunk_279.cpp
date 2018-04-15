		else
			Py_DECREF(ret);
	}
	Py_Finalize();
	return 0;
}

static void *cpy_interactive(void *data) {
	CPY_LOCK_THREADS
		if (PyImport_ImportModule("readline") == NULL) {
			/* This interactive session will suck. */
			cpy_log_exception("interactive session init");
		}
		PyRun_InteractiveLoop(stdin, "<stdin>");
	CPY_RELEASE_THREADS
	NOTICE("python: Interactive interpreter exited, stopping collectd ...");
	raise(SIGINT);
	return NULL;
}

static int cpy_init(void) {
	cpy_callback_t *c;
	PyObject *ret;
	static pthread_t thread;
	
	PyEval_InitThreads();
	/* Now it's finally OK to use python threads. */
