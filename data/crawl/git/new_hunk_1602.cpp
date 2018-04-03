	status_printf_ln(s, c, "%s", "");
}

static void wt_longstatus_print_other_header(struct wt_status *s,
					     const char *what,
					     const char *how)
{
	const char *c = color(WT_STATUS_HEADER, s);
	status_printf_ln(s, c, "%s:", what);
