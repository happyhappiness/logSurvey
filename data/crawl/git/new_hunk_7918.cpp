		free(target_host);
		if (free_path)
			free(path);
		return NULL;
	}

	if (pipe(pipefd[0]) < 0 || pipe(pipefd[1]) < 0)
		die("unable to create pipe pair for communication");
	conn = xcalloc(1, sizeof(*conn));
	conn->pid = fork();
	if (conn->pid < 0)
		die("unable to fork");
	if (!conn->pid) {
		struct strbuf cmd;

		strbuf_init(&cmd, MAX_CMD_LEN);
