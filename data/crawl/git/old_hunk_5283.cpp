	if (finish_command(&cp))
		die("git status --porcelain failed");

	for (i = LOCAL_REPO_ENV_SIZE; env[i]; i++)
		free((char *)env[i]);
	strbuf_release(&buf);
	return dirty_submodule;
}
