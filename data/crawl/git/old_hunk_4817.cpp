	else if (argc == 2)
		filename = argv[1];
	else
		usage("test-line-buffer [file] < script");

	if (buffer_init(&stdin_buf, NULL))
		die_errno("open error");
	if (filename) {
		if (buffer_init(&file_buf, filename))
			die_errno("error opening %s", filename);
		input = &file_buf;
	}

