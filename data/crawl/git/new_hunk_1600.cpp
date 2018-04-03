	status_printf_ln(s, c, "%s", "");
}

static void wt_longstatus_print_cached_header(struct wt_status *s)
{
	const char *c = color(WT_STATUS_HEADER, s);

