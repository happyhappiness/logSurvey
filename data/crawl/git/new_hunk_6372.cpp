		}
		if (!use_stdout && reopen_stdout(numbered_files ? NULL :
				get_oneline_for_filename(commit, keep_subject),
				rev.nr, &rev))
			die("Failed to create output files");
		shown = log_tree_commit(&rev, commit);
		free(commit->buffer);