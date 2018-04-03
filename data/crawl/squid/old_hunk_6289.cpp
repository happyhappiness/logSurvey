        f->select_fds > l->select_fds ?
	(f->select_time - l->select_time) / (f->select_fds - l->select_fds)
	: 0.0);
    storeAppendPrintf(sentry, "cpu_time = %f seconds\n", ct);
    storeAppendPrintf(sentry, "wall_time = %f seconds\n", dt);
    storeAppendPrintf(sentry, "cpu_usage = %f%%\n", dpercent(ct, dt));
