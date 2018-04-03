	info->message_id = strbuf_detach(&buf, NULL);
}

static void make_cover_letter(struct rev_info *rev,
		int use_stdout, int numbered, int numbered_files,
			      struct commit *origin, struct commit *head)
{
	const char *committer;
	const char *origin_sha1, *head_sha1;
	const char *argv[7];
	const char *subject_start = NULL;
	const char *body = "*** SUBJECT HERE ***\n\n*** BLURB HERE ***\n";
	const char *msg;
	const char *extra_headers = rev->extra_headers;
	struct strbuf sb;
	const char *encoding = "utf-8";

	if (rev->commit_format != CMIT_FMT_EMAIL)
		die("Cover letter needs email format");

	if (!use_stdout && reopen_stdout(numbered_files ?
				NULL : "cover-letter", 0, rev->total))
		return;

	origin_sha1 = sha1_to_hex(origin ? origin->object.sha1 : null_sha1);
	head_sha1 = sha1_to_hex(head->object.sha1);

	log_write_email_headers(rev, head_sha1, &subject_start, &extra_headers);

	committer = git_committer_info(0);

	msg = body;
	strbuf_init(&sb, 0);
	pp_user_info(NULL, CMIT_FMT_EMAIL, &sb, committer, DATE_RFC2822,
		     encoding);
	pp_title_line(CMIT_FMT_EMAIL, &msg, &sb, subject_start, extra_headers,
		      encoding, 0);
	pp_remainder(CMIT_FMT_EMAIL, &msg, &sb, 0);
	printf("%s\n", sb.buf);

	strbuf_release(&sb);

	/*
	 * We can only do diffstat with a unique reference point, and
	 * log is a bit tricky, so just skip it.
	 */
	if (!origin)
		return;

	argv[0] = "shortlog";
	argv[1] = head_sha1;
	argv[2] = "--not";
	argv[3] = origin_sha1;
	argv[4] = "--";
	argv[5] = NULL;
	fflush(stdout);
	run_command_v_opt(argv, RUN_GIT_CMD);

	argv[0] = "diff";
	argv[1] = "--stat";
	argv[2] = "--summary";
	argv[3] = head_sha1;
	argv[4] = "--not";
	argv[5] = origin_sha1;
	argv[6] = "--";
	argv[7] = NULL;
	fflush(stdout);
	run_command_v_opt(argv, RUN_GIT_CMD);

	fflush(stdout);
	printf("\n");
}

static const char *clean_message_id(const char *msg_id)
{
	char ch;
