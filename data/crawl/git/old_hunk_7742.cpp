	strbuf_insert(&sb, 0, reflog_msg, strlen(reflog_msg));
	strbuf_insert(&sb, strlen(reflog_msg), ": ", 2);

	if (!ref_lock)
		die("cannot lock HEAD ref");
	if (write_ref_sha1(ref_lock, commit_sha1, sb.buf) < 0)
		die("cannot update HEAD ref");

	unlink(git_path("MERGE_HEAD"));
	unlink(git_path("MERGE_MSG"));

	if (lock_file.filename[0] && commit_locked_index(&lock_file))
		die("failed to write new index");

	rerere();

	run_hook(index_file, "post-commit", NULL);

	if (!quiet)
		print_summary(prefix, commit_sha1);
