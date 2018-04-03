	if (!use_message && renew_authorship)
		die("--reset-author can be used only with -C, -c or --amend.");
	if (use_message) {
		unsigned char sha1[20];
		static char utf8[] = "UTF-8";
		const char *out_enc;
		char *enc, *end;
		struct commit *commit;

		if (get_sha1(use_message, sha1))
			die("could not lookup commit %s", use_message);
		commit = lookup_commit_reference(sha1);
		if (!commit || parse_commit(commit))
			die("could not parse commit %s", use_message);

		enc = strstr(commit->buffer, "\nencoding");
		if (enc) {
			end = strchr(enc + 10, '\n');
			enc = xstrndup(enc + 10, end - (enc + 10));
		} else {
			enc = utf8;
		}
		out_enc = git_commit_encoding ? git_commit_encoding : utf8;

		if (strcmp(out_enc, enc))
			use_message_buffer =
				reencode_string(commit->buffer, out_enc, enc);

		/*
		 * If we failed to reencode the buffer, just copy it
