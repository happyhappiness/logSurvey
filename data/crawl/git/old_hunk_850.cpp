	if (res)
		return error(_("unusable instruction sheet: '%s'"), todo_file);

	if (!is_rebase_i(opts)) {
		enum todo_command valid =
			opts->action == REPLAY_PICK ? TODO_PICK : TODO_REVERT;