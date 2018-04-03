	return run_command_v_opt(fetch_argv, RUN_GIT_CMD);
}

static int set_url(int argc, const char **argv)
{
	int i, push_mode = 0, add_mode = 0, delete_mode = 0;
