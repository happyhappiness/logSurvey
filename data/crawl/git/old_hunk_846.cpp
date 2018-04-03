	return res;
}

static int do_pick_commit(enum todo_command command, struct commit *commit,
		struct replay_opts *opts, int final_fixup)
{
