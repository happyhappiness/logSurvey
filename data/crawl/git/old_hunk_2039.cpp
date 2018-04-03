	{
		int err = pthread_create(&async->tid, NULL, run_thread, async);
		if (err) {
			error("cannot create thread: %s", strerror(err));
			goto error;
		}
	}