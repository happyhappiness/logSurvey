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
		strbuf_addstr(&cmd, prog);
		strbuf_addch(&cmd, ' ');
		sq_quote_buf(&cmd, path);
		if (cmd.len >= MAX_CMD_LEN)
			die("command line too long");

		dup2(pipefd[1][0], 0);
		dup2(pipefd[0][1], 1);
		close(pipefd[0][0]);
		close(pipefd[0][1]);
		close(pipefd[1][0]);
		close(pipefd[1][1]);
		if (protocol == PROTO_SSH) {
			const char *ssh, *ssh_basename;
			ssh = getenv("GIT_SSH");
			if (!ssh) ssh = "ssh";
			ssh_basename = strrchr(ssh, '/');
			if (!ssh_basename)
				ssh_basename = ssh;
			else
				ssh_basename++;

			if (!port)
				execlp(ssh, ssh_basename, host, cmd.buf, NULL);
			else
				execlp(ssh, ssh_basename, "-p", port, host,
				       cmd.buf, NULL);
		}
		else {
			unsetenv(ALTERNATE_DB_ENVIRONMENT);
			unsetenv(DB_ENVIRONMENT);
			unsetenv(GIT_DIR_ENVIRONMENT);
			unsetenv(GIT_WORK_TREE_ENVIRONMENT);
			unsetenv(GRAFT_ENVIRONMENT);
			unsetenv(INDEX_ENVIRONMENT);
			execlp("sh", "sh", "-c", cmd.buf, NULL);
		}
		die("exec failed");
	}
	fd[0] = pipefd[0][0];
	fd[1] = pipefd[1][1];
	close(pipefd[0][1]);
	close(pipefd[1][0]);
	if (free_path)
		free(path);
	return conn;
}

int finish_connect(struct child_process *conn)
{
	if (!conn)
		return 0;

	while (waitpid(conn->pid, NULL, 0) < 0) {
		if (errno != EINTR)
			return -1;
	}
	free(conn);
	return 0;
}