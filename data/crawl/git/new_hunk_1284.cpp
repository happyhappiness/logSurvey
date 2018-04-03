	struct pretty_print_context pp = {0};
	struct commit *head = list[0];

	if (!cmit_fmt_is_mail(rev->commit_format))
		die(_("Cover letter needs email format"));

	committer = git_committer_info(0);

	if (!use_stdout &&
	    open_next_file(NULL, rev->numbered_files ? NULL : "cover-letter", rev, quiet))
		return;

	log_write_email_headers(rev, head, &pp.subject, &pp.after_subject,