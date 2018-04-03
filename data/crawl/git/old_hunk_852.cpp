	return run_command_v_opt(argv, RUN_GIT_CMD);
}

int sequencer_continue(struct replay_opts *opts)
{
	struct todo_list todo_list = TODO_LIST_INIT;
