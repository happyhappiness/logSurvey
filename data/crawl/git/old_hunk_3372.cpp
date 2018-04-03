	if (inetd_mode || serve_mode)
		return execute();

	if (detach)
		daemonize();
	else
		sanitize_stdfds();

	if (pid_file)
