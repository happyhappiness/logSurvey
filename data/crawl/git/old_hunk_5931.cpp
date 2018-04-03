	while (devnull_fd >= 0 && devnull_fd <= 2)
		devnull_fd = dup(devnull_fd);
	if (devnull_fd == -1)
		die("opening /dev/null failed (%s)", strerror(errno));
	close (devnull_fd);

	/*
