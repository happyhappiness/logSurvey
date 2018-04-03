	else if (async->out)
		close(async->out);
#else
	async->proc_in = proc_in;
	async->proc_out = proc_out;
	async->tid = (HANDLE) _beginthreadex(NULL, 0, run_thread, async, 0, NULL);
	if (!async->tid) {
		error("cannot create thread: %s", strerror(errno));
		goto error;
	}
#endif
	return 0;
