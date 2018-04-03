		status_printf_ln(s, color,
			_("  (use \"git am --abort\" to restore the original branch)"));
	}
	wt_status_print_trailer(s);
}

static char *read_line_from_git_path(const char *filename)
