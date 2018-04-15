	 * This will make sure that SIGINT won't kill collectd but
	 * still interrupt syscalls like sleep and pause. */

	if (PyImport_ImportModule("readline") == NULL) {
		/* This interactive session will suck. */
		cpy_log_exception("interactive session init");
	}
	cur_sig = PyOS_setsig(SIGINT, python_sigint_handler);
	PyOS_AfterFork();
	PyEval_InitThreads();
	close(*(int *) pipefd);
	PyRun_InteractiveLoop(stdin, "<stdin>");
	PyOS_setsig(SIGINT, cur_sig);
	PyErr_Print();
	state = PyEval_SaveThread();
	NOTICE("python: Interactive interpreter exited, stopping collectd ...");
	pthread_kill(main_thread, SIGINT);
	return NULL;
}

static int cpy_init(void) {
	PyObject *ret;
	int pipefd[2];
	char buf;
	static pthread_t thread;

	if (!Py_IsInitialized()) {
