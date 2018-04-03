	/* open connection to IMAP server */

	if (srvc->tunnel) {
		const char *argv[4];
		struct child_process tunnel = {0};

		imap_info("Starting tunnel '%s'... ", srvc->tunnel);

		argv[0] = "sh";
		argv[1] = "-c";
		argv[2] = srvc->tunnel;
		argv[3] = NULL;

		tunnel.argv = argv;
		tunnel.in = -1;
		tunnel.out = -1;
		if (start_command(&tunnel))
			die("cannot start proxy %s", argv[0]);

		imap->buf.sock.fd[0] = tunnel.out;
		imap->buf.sock.fd[1] = tunnel.in;

		imap_info("ok\n");
	} else {