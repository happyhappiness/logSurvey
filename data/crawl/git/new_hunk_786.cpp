		struct string_list yet_to_do = STRING_LIST_INIT_DUP;

		read_rebase_todolist("rebase-merge/done", &have_done);
		if (read_rebase_todolist("rebase-merge/git-rebase-todo",
					 &yet_to_do))
			status_printf_ln(s, color,
				_("git-rebase-todo is missing."));
		if (have_done.nr == 0)
			status_printf_ln(s, color, _("No commands done."));
		else {