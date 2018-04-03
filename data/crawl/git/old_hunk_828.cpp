	close(fd);

	res = parse_insn_buffer(todo_list->buf.buf, todo_list);
	if (res)
		return error(_("unusable instruction sheet: '%s'"), todo_file);

	if (!todo_list->nr &&
	    (!is_rebase_i(opts) || !file_exists(rebase_path_done())))