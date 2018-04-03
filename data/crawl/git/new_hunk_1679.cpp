{
	if (has_unmerged(s)) {
		status_printf_ln(s, color, _("You have unmerged paths."));
		if (s->hints) {
			status_printf_ln(s, color,
					 _("  (fix conflicts and run \"git commit\")"));
			status_printf_ln(s, color,
					 _("  (use \"git merge --abort\" to abort the merge)"));
		}
	} else {
		status_printf_ln(s, color,
			_("All conflicts fixed but you are still merging."));