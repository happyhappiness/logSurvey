	const char *encoding = "utf-8";
	struct diff_options opts;
	int need_8bit_cte = 0;

	if (rev->commit_format != CMIT_FMT_EMAIL)
		die("Cover letter needs email format");

	if (!use_stdout && reopen_stdout(numbered_files ?
				NULL : "cover-letter", 0, rev->total))
		return;

	head_sha1 = sha1_to_hex(head->object.sha1);

	log_write_email_headers(rev, head_sha1, &subject_start, &extra_headers,
				&need_8bit_cte);

	committer = git_committer_info(0);

	msg = body;
	pp_user_info(NULL, CMIT_FMT_EMAIL, &sb, committer, DATE_RFC2822,
