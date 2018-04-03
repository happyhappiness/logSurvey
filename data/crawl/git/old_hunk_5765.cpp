
	cmd->pid = mingw_spawnvpe(cmd->argv[0], cmd->argv, env);
	failed_errno = errno;
	if (cmd->pid < 0 && errno != ENOENT)
		error("cannot spawn %s: %s", cmd->argv[0], strerror(errno));

	if (cmd->env)
