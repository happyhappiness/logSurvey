		numbered = 1;
	if (numbered)
		rev.total = total + start_number - 1;
	rev.add_signoff = add_signoff;
	if (in_reply_to)
		rev.ref_message_id = clean_message_id(in_reply_to);
	while (0 <= --nr) {
		int shown;
		commit = list[nr];
		rev.nr = total - nr + (start_number - 1);
		/* Make the second and subsequent mails replies to the first */
		if (thread) {
			if (rev.message_id) {
				if (rev.ref_message_id)
					free(rev.message_id);
				else
					rev.ref_message_id = rev.message_id;
			}
			gen_message_id(&rev, sha1_to_hex(commit->object.sha1));
		}
		if (!use_stdout)
			if (reopen_stdout(commit, rev.nr, keep_subject,
					  numbered_files))
				die("Failed to create output files");
		shown = log_tree_commit(&rev, commit);
		free(commit->buffer);
		commit->buffer = NULL;
