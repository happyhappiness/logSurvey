	strbuf_release(&pattern);
}

static void wt_status_print_verbose(struct wt_status *s)
{
	struct rev_info rev;
