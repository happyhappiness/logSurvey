static int fetch_remote(const char *name)
{
	const char *argv[] = { "fetch", name, NULL };
	if (run_command_v_opt(argv, RUN_GIT_CMD))
		return error("Could not fetch %s", name);
	return 0;