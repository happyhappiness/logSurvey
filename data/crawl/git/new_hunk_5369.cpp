	else if (async->out)
		close(async->out);
#else
	if (proc_in >= 0)
		set_cloexec(proc_in);
	if (proc_out >= 0)
		set_cloexec(proc_out);
	async->proc_in = proc_in;
	async->proc_out = proc_out;
	{
		int err = pthread_create(&async->tid, NULL, run_thread, async);
		if (err) {
			error("cannot create thread: %s", strerror(err));
			goto error;
		}
	}
#endif
	return 0;
