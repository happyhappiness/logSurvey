		}

		if (!use_stdout &&
		    open_next_file(rev.numbered_files ? NULL : commit, NULL, &rev, quiet))
			die(_("Failed to create output files"));
		shown = log_tree_commit(&rev, commit);
		free_commit_buffer(commit);
