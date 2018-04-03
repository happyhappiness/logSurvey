	int ret = 0;
	struct child_process cp = CHILD_PROCESS_INIT;
	const struct submodule *sub;

	if (!is_submodule_initialized(path))
		return 0;

	sub = submodule_from_path(null_sha1, path);

	if (!sub)
