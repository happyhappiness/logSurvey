		wt_status_print_submodule_summary(s, 1);  /* unstaged */
	}
	if (s->show_untracked_files) {
		wt_status_print_other(s, &s->untracked, "Untracked", "add");
		if (s->show_ignored_files)
			wt_status_print_other(s, &s->ignored, "Ignored", "add -f");
	} else if (s->commitable)
		status_printf_ln(s, GIT_COLOR_NORMAL, "Untracked files not listed%s",
			advice_status_hints
			? " (use -u option to show untracked files)" : "");

	if (s->verbose)
		wt_status_print_verbose(s);
	if (!s->commitable) {
		if (s->amend)
			status_printf_ln(s, GIT_COLOR_NORMAL, "No changes");
		else if (s->nowarn)
			; /* nothing */
		else if (s->workdir_dirty)
			printf("no changes added to commit%s\n",
				advice_status_hints
				? " (use \"git add\" and/or \"git commit -a\")" : "");
		else if (s->untracked.nr)
			printf("nothing added to commit but untracked files present%s\n",
				advice_status_hints
				? " (use \"git add\" to track)" : "");
		else if (s->is_initial)
			printf("nothing to commit%s\n", advice_status_hints
				? " (create/copy files and use \"git add\" to track)" : "");