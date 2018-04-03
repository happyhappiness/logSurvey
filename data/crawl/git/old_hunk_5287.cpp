	run_command(&sm_summary);
}

static void wt_status_print_untracked(struct wt_status *s)
{
	int i;
	struct strbuf buf = STRBUF_INIT;

	if (!s->untracked.nr)
		return;

	wt_status_print_untracked_header(s);
	for (i = 0; i < s->untracked.nr; i++) {
		struct string_list_item *it;
		it = &(s->untracked.items[i]);
		color_fprintf(s->fp, color(WT_STATUS_HEADER, s), "#\t");
		color_fprintf_ln(s->fp, color(WT_STATUS_UNTRACKED, s), "%s",
				 quote_path(it->string, strlen(it->string),
