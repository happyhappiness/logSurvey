			todo_list->buf.len - offset) < 0)
		return error_errno(_("Could not write to '%s'"), todo_path);
	if (commit_lock_file(&todo_lock) < 0)
		return error(_("Error wrapping up '%s'."), todo_path);
	return 0;
}
