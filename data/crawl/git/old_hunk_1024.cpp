	if (name_hint) {
		const char *format = archive_format_from_filename(name_hint);
		if (format)
			packet_write(fd[1], "argument --format=%s\n", format);
	}
	for (i = 1; i < argc; i++)
		packet_write(fd[1], "argument %s\n", argv[i]);
	packet_flush(fd[1]);

	buf = packet_read_line(fd[0], NULL);