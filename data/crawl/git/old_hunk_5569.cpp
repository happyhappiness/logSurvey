	if (force_author && !strchr(force_author, '>'))
		force_author = find_author_by_nickname(force_author);

	if (logfile || message.len || use_message)
		use_editor = 0;
	if (edit_flag)
