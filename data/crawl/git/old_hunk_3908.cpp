				struct wt_status_state *state,
				const char *color)
{
	status_printf_ln(s, color, _("You are currently bisecting."));
	if (advice_status_hints)
		status_printf_ln(s, color,
			_("  (use \"git bisect reset\" to get back to the original branch)"));
	wt_status_print_trailer(s);
}

static void wt_status_print_state(struct wt_status *s)
{
	const char *state_color = color(WT_STATUS_HEADER, s);
	struct wt_status_state state;
	struct stat st;

