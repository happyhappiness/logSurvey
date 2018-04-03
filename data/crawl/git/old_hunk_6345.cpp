	const char *encoding = "utf-8";
	struct diff_options opts;
	int need_8bit_cte = 0;
	char filename[PATH_MAX];

	if (rev->commit_format != CMIT_FMT_EMAIL)
		die("Cover letter needs email format");

	if (numbered_files)
		sprintf(filename, "0");
	else
		sprintf(filename, "%04d-cover-letter%s", 0, fmt_patch_suffix);

	if (!use_stdout && reopen_stdout(filename, rev))
		return;

	head_sha1 = sha1_to_hex(head->object.sha1);

	log_write_email_headers(rev, head_sha1, &subject_start, &extra_headers,
				&need_8bit_cte);

	committer = git_committer_info(0);

	msg = body;
	pp_user_info(NULL, CMIT_FMT_EMAIL, &sb, committer, DATE_RFC2822,
		     encoding);
