		return NULL;
	}

	conn = xcalloc(1, sizeof(*conn));

	strbuf_init(&cmd, MAX_CMD_LEN);
	strbuf_addstr(&cmd, prog);
	strbuf_addch(&cmd, ' ');
	sq_quote_buf(&cmd, path);
	if (cmd.len >= MAX_CMD_LEN)
		die("command line too long");

	conn->in = conn->out = -1;
	conn->argv = arg = xcalloc(6, sizeof(*arg));
	if (protocol == PROTO_SSH) {
		const char *ssh = getenv("GIT_SSH");
		if (!ssh) ssh = "ssh";

		*arg++ = ssh;
		if (port) {
			*arg++ = "-p";
			*arg++ = port;
		}
		*arg++ = host;
	}
	else {
		/* remove these from the environment */
		const char *env[] = {
			ALTERNATE_DB_ENVIRONMENT,
			DB_ENVIRONMENT,
			GIT_DIR_ENVIRONMENT,
			GIT_WORK_TREE_ENVIRONMENT,
			GRAFT_ENVIRONMENT,
			INDEX_ENVIRONMENT,
			NULL
		};
		conn->env = env;
		*arg++ = "sh";
		*arg++ = "-c";
	}
	*arg++ = cmd.buf;
	*arg = NULL;

	if (start_command(conn))
		die("unable to fork");

	fd[0] = conn->out; /* read from child's stdout */
	fd[1] = conn->in;  /* write to child's stdin */
	strbuf_release(&cmd);
	if (free_path)
		free(path);
	return conn;
}

int finish_connect(struct child_process *conn)
{
	int code;
	if (!conn)
		return 0;

	code = finish_command(conn);
	free(conn->argv);
	free(conn);
	return code;
}