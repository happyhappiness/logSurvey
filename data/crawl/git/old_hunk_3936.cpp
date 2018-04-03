		if (cleanup_mode == CLEANUP_ALL)
			status_printf(s, GIT_COLOR_NORMAL,
				_("Please enter the commit message for your changes."
				" Lines starting\nwith '#' will be ignored, and an empty"
				" message aborts the commit.\n"));
		else /* CLEANUP_SPACE, that is. */
			status_printf(s, GIT_COLOR_NORMAL,
				_("Please enter the commit message for your changes."
				" Lines starting\n"
				"with '#' will be kept; you may remove them"
				" yourself if you want to.\n"
				"An empty message aborts the commit.\n"));
		if (only_include_assumed)
			status_printf_ln(s, GIT_COLOR_NORMAL,
					"%s", only_include_assumed);
