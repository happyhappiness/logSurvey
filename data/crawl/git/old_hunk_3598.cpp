	if (advice_status_hints) {
		if (has_unmerged(s))
			status_printf_ln(s, color,
				_("  (fix conflicts and run \"git commit\")"));
		else
			status_printf_ln(s, color,
				_("  (all conflicts fixed: run \"git commit\")"));
	}
	wt_status_print_trailer(s);
}