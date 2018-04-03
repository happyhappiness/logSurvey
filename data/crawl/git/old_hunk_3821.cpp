		wt_status_print_other(s, &s->untracked, _("Untracked files"), "add");
		if (s->show_ignored_files)
			wt_status_print_other(s, &s->ignored, _("Ignored files"), "add -f");
	} else if (s->commitable)
		status_printf_ln(s, GIT_COLOR_NORMAL, _("Untracked files not listed%s"),
			advice_status_hints
