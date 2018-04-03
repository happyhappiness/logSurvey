	else if (is_absolute_path(trace)) {
		int fd = open(trace, O_WRONLY | O_APPEND | O_CREAT, 0666);
		if (fd == -1) {
			warning("could not open '%s' for tracing: %s\n"
				"         Defaulting to tracing on stderr...",
				trace, strerror(errno));
			key->fd = STDERR_FILENO;
		} else {
			key->fd = fd;
			key->need_close = 1;
		}
	} else {
		warning("unknown trace value for '%s': %s\n"
			"         If you want to trace into a file, then please set %s\n"
			"         to an absolute pathname (starting with /)\n"
			"         Defaulting to tracing on stderr...",
			key->key, trace, key->key);
		key->fd = STDERR_FILENO;
	}

	key->initialized = 1;