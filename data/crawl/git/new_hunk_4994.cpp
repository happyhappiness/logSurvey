	if (!use_message && renew_authorship)
		die("--reset-author can be used only with -C, -c or --amend.");
	if (use_message) {
		const char *out_enc;
		struct commit *commit;

		commit = lookup_commit_reference_by_name(use_message);
		if (!commit)
			die("could not lookup commit %s", use_message);
		out_enc = get_commit_output_encoding();
		use_message_buffer = logmsg_reencode(commit, out_enc);

		/*
		 * If we failed to reencode the buffer, just copy it
