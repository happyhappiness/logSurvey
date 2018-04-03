			rev.message_id = message_id;
		}
		if (!use_stdout)
			if (reopen_stdout(commit, rev.nr, keep_subject,
					  numbered_files))
				die("Failed to create output files");
		shown = log_tree_commit(&rev, commit);
		free(commit->buffer);