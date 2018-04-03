	struct stat st;

	if (has_unmerged(s)) {
		status_printf_ln(s, color, _("You are currently rebasing."));
		if (advice_status_hints) {
			status_printf_ln(s, color,
				_("  (fix conflicts and then run \"git rebase --continue\")"));
