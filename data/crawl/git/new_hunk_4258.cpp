	return 0;
}

static int sequencer_continue(struct replay_opts *opts)
{
	struct commit_list *todo_list = NULL;

	if (!file_exists(git_path(SEQ_TODO_FILE)))
		return error(_("No %s in progress"), action_name(opts));
	read_populate_opts(&opts);
	read_populate_todo(&todo_list, opts);

	/* Verify that the conflict has been resolved */
	if (!index_differs_from("HEAD", 0))
		todo_list = todo_list->next;
	return pick_commits(todo_list, opts);
}

static int pick_revisions(struct replay_opts *opts)
{
	struct commit_list *todo_list = NULL;
