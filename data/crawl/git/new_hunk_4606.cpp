
		if (!use_stdout && reopen_stdout(numbered_files ? NULL : commit,
						 &rev))
			die(_("Failed to create output files"));
		shown = log_tree_commit(&rev, commit);
		free(commit->buffer);
		commit->buffer = NULL;