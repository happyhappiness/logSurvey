		NULL,
		NULL,
	};
	const char *env[LOCAL_REPO_ENV_SIZE + 3];
	struct strbuf buf = STRBUF_INIT;
	unsigned dirty_submodule = 0;
	const char *line, *next_line;

	for (i = 0; i < LOCAL_REPO_ENV_SIZE; i++)
		env[i] = local_repo_env[i];

	strbuf_addf(&buf, "%s/.git/", path);
	if (!is_directory(buf.buf)) {
		strbuf_release(&buf);
		/* The submodule is not checked out, so it is not modified */
		return 0;

	}
	strbuf_reset(&buf);

	strbuf_addf(&buf, "GIT_WORK_TREE=%s", path);
	env[i++] = strbuf_detach(&buf, NULL);
	strbuf_addf(&buf, "GIT_DIR=%s/.git", path);
	env[i++] = strbuf_detach(&buf, NULL);
	env[i] = NULL;

	if (ignore_untracked)
		argv[2] = "-uno";

	memset(&cp, 0, sizeof(cp));
	cp.argv = argv;
	cp.env = env;
	cp.git_cmd = 1;
	cp.no_stdin = 1;
	cp.out = -1;
	if (start_command(&cp))
		die("Could not run git status --porcelain");

