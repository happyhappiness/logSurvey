	 * This will make sure that SIGINT won't kill collectd but
	 * still interrupt syscalls like sleep and pause. */

	PyEval_AcquireThread(state);
	if (PyImport_ImportModule("readline") == NULL) {
		/* This interactive session will suck. */
		cpy_log_exception("interactive session init");
	}
	cur_sig = PyOS_setsig(SIGINT, python_sigint_handler);
	/* We totally forked just now. Everyone saw that, right? */
	PyOS_AfterFork();
	PyRun_InteractiveLoop(stdin, "<stdin>");
	PyOS_setsig(SIGINT, cur_sig);
	PyErr_Print();
	PyEval_ReleaseThread(state);
	NOTICE("python: Interactive interpreter exited, stopping collectd ...");
	pthread_kill(main_thread, SIGINT);
	return NULL;
}

static int cpy_init(void) {
	PyObject *ret;
	static pthread_t thread;

	if (!Py_IsInitialized()) {
