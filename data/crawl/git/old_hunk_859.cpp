	return res;
}

static int pick_commits(struct todo_list *todo_list, struct replay_opts *opts)
{
	int res;

	setenv(GIT_REFLOG_ACTION, action_name(opts), 0);
	if (opts->allow_ff)
