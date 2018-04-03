	if (logfile)
		f++;
	if (f > 1)
		die("Only one of -c/-C/-F/--fixup can be used.");
	if (message.len && f > 0)
		die("Option -m cannot be combined with -c/-C/-F/--fixup.");
	if (edit_message)
		use_message = edit_message;
	if (amend && !use_message && !fixup_message)
		use_message = "HEAD";
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

