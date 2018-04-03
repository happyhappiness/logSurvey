	/* open connection to IMAP server */

	if (srvc->tunnel) {
		imap_info("Starting tunnel '%s'... ", srvc->tunnel);

		if (socketpair(PF_UNIX, SOCK_STREAM, 0, a)) {
			perror("socketpair");
			exit(1);
		}

		pid = fork();
		if (pid < 0)
			_exit(127);
		if (!pid) {
			if (dup2(a[0], 0) == -1 || dup2(a[0], 1) == -1)
				_exit(127);
			close(a[0]);
			close(a[1]);
			execl("/bin/sh", "sh", "-c", srvc->tunnel, NULL);
			_exit(127);
		}

		close(a[0]);

		imap->buf.sock.fd[0] = a[1];
		imap->buf.sock.fd[1] = dup(a[1]);

		imap_info("ok\n");
	} else {