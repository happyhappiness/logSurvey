	return 0;
}

static int pick_revisions(struct replay_opts *opts)
{
	struct commit_list *todo_list = NULL;
