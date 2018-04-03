	if (detach) {
		if (daemonize())
			die("--detach not supported on this platform");
	}

	if (pid_file)
		write_file(pid_file, "%"PRIuMAX, (uintmax_t) getpid());
