		die("'%s' does not appear to be a git repository", argv[1]);

	/* put received options in sent_argv[] */
	sent_argc = 1;
	sent_argv[0] = "git-upload-archive";
	for (p = buf;;) {
		/* This will die if not enough free space in buf */
		len = packet_read_line(0, p, (buf + sizeof buf) - p);
		if (len == 0)
			break;	/* got a flush */
		if (sent_argc > MAX_ARGS - 2)
			die("Too many options (>%d)", MAX_ARGS - 2);

		if (p[len-1] == '\n') {
			p[--len] = 0;
		}
		if (len < strlen(arg_cmd) ||
		    strncmp(arg_cmd, p, strlen(arg_cmd)))
			die("'argument' token or flush expected");

		len -= strlen(arg_cmd);
		memmove(p, p + strlen(arg_cmd), len);
		sent_argv[sent_argc++] = p;
		p += len;
		*p++ = 0;
	}
	sent_argv[sent_argc] = NULL;

	/* parse all options sent by the client */
	return write_archive(sent_argc, sent_argv, prefix, 0, NULL, 1);
}

__attribute__((format (printf, 1, 2)))