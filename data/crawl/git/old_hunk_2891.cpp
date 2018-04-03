			status_printf_ln(s, color,
				_("  (use \"git rebase --abort\" to check out the original branch)"));
		}
	} else if (state->rebase_in_progress || !stat(git_path("MERGE_MSG"), &st)) {
		print_rebase_state(s, state, color);
		if (s->hints)
			status_printf_ln(s, color,
