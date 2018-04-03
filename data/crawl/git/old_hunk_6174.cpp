			/* Have we already had a message ID? */
			if (rev.message_id) {
				/*
				 * If we've got the ID to be a reply
				 * to, discard the current ID;
				 * otherwise, make everything a reply
				 * to that.
				 */
				if (rev.ref_message_id)
					free(rev.message_id);
				else
					rev.ref_message_id = rev.message_id;
			}
			gen_message_id(&rev, sha1_to_hex(commit->object.sha1));
		}
		if (!use_stdout && reopen_stdout(numbered_files ? NULL :
				get_oneline_for_filename(commit, keep_subject),
				rev.nr, rev.total))
			die("Failed to create output files");
		shown = log_tree_commit(&rev, commit);
		free(commit->buffer);
