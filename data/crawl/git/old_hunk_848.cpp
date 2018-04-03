	}

	if (is_rebase_i(opts)) {
		struct strbuf buf = STRBUF_INIT;

		/* Stopped in the middle, as planned? */
		if (todo_list->current < todo_list->nr)
			return 0;

		if (opts->verbose) {
			struct rev_info log_tree_opt;
			struct object_id orig, head;
