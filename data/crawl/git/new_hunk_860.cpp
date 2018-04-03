		struct todo_item *item = todo_list->items + todo_list->current;
		if (save_todo(todo_list, opts))
			return -1;
		if (item->command <= TODO_EDIT) {
			res = do_pick_commit(item->command, item->commit,
					opts);
			if (item->command == TODO_EDIT) {
				struct commit *commit = item->commit;
				if (!res)
					warning(_("stopped at %s... %.*s"),
						short_commit_name(commit),
						item->arg_len, item->arg);
				return error_with_patch(commit,
					item->arg, item->arg_len, opts, res,
					!res);
			}
		} else if (!is_noop(item->command))
			return error(_("unknown command %d"), item->command);

		todo_list->current++;
		if (res)
			return res;
	}

	if (is_rebase_i(opts)) {
		/* Stopped in the middle, as planned? */
		if (todo_list->current < todo_list->nr)
			return 0;
	}

	/*
	 * Sequence of picks finished successfully; cleanup by
	 * removing the .git/sequencer directory