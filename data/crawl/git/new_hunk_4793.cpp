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