		struct todo_item *item = todo_list->items + todo_list->current;
		if (save_todo(todo_list, opts))
			return -1;
		res = do_pick_commit(item->command, item->commit, opts);
		todo_list->current++;
		if (res)
			return res;