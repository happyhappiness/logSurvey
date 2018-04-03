		free(target_host);
		if (free_path)
			free(path);
		return 0;
	}

	if (pipe(pipefd[0]) < 0 || pipe(pipefd[1]) < 0)
		die("unable to create pipe pair for communication");
	pid = fork();
	if (pid < 0)
		die("unable to fork");
	if (!pid) {
		struct strbuf cmd;

		strbuf_init(&cmd, MAX_CMD_LEN);
