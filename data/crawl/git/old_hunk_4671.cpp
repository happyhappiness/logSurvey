		force_author = find_author_by_nickname(force_author);

	if (force_author && renew_authorship)
		die("Using both --reset-author and --author does not make sense");

	if (logfile || message.len || use_message || fixup_message)
		use_editor = 0;
