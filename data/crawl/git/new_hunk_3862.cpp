		die("'%s' does not appear to be a git repository", argv[1]);

	/* put received options in sent_argv[] */
	argv_array_push(&sent_argv, "git-upload-archive");
	for (;;) {
		/* This will die if not enough free space in buf */
		len = packet_read_line(0, buf, sizeof(buf));
		if (len == 0)
			break;	/* got a flush */
		if (sent_argv.argc > MAX_ARGS)
			die("Too many options (>%d)", MAX_ARGS - 1);

		if (buf[len-1] == '\n') {
			buf[--len] = 0;
		}

		if (prefixcmp(buf, arg_cmd))
			die("'argument' token or flush expected");
		argv_array_push(&sent_argv, buf + strlen(arg_cmd));
	}

	/* parse all options sent by the client */
	return write_archive(sent_argv.argc, sent_argv.argv, prefix, 0, NULL, 1);
}

__attribute__((format (printf, 1, 2)))