		if (save_todo(todo_list, opts))
			return -1;
		if (is_rebase_i(opts)) {
			unlink(rebase_path_message());
			unlink(rebase_path_author_script());
			unlink(rebase_path_stopped_sha());