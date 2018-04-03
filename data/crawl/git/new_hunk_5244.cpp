	string_list_clear(&subjects, 0);
}

static void do_fmt_merge_msg_title(struct strbuf *out,
	const char *current_branch) {
	int i = 0;
	char *sep = "";

	strbuf_addstr(out, "Merge ");
	for (i = 0; i < srcs.nr; i++) {
