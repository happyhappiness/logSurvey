		if (advice_status_u_option && 2000 < s->untracked_in_ms) {
			status_printf_ln(s, GIT_COLOR_NORMAL, "");
			status_printf_ln(s, GIT_COLOR_NORMAL,
				 _("It took %.2f seconds to enumerate untracked files."
				   "  'status -uno'"),
				 s->untracked_in_ms / 1000.0);
			status_printf_ln(s, GIT_COLOR_NORMAL,
				 _("may speed it up, but you have to be careful not"
				   " to forget to add"));
			status_printf_ln(s, GIT_COLOR_NORMAL,
				 _("new files yourself (see 'git help status')."));
		}
	} else if (s->commitable)
		status_printf_ln(s, GIT_COLOR_NORMAL, _("Untracked files not listed%s"),