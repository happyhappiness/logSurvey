	status_printf_ln(s, c, "%s", "");
}

static void wt_status_print_dirty_header(struct wt_status *s,
					 int has_deleted,
					 int has_dirty_submodules)
{
	const char *c = color(WT_STATUS_HEADER, s);

