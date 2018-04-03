		/* avoid splitting a message in the middle */
		setvbuf(stderr, NULL, _IOFBF, 4096);

	if (inetd_mode && (detach || group_name || user_name))
		die("--detach, --user and --group are incompatible with --inetd");

	if (inetd_mode && (listen_port || (listen_addr.nr > 0)))
		die("--listen= and --port= are incompatible with --inetd");