					struct wt_status_state *state,
					const char *color)
{
	status_printf_ln(s, color, _("You are currently reverting a commit."));
	if (advice_status_hints) {
		if (has_unmerged(s))
			status_printf_ln(s, color,
