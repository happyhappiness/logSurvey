	string_list_clear(&subjects, 0);
}

static int do_fmt_merge_msg(int merge_summary, struct strbuf *in,
	struct strbuf *out) {
	int limit = 20, i = 0, pos = 0;
	char *sep = "";
	unsigned char head_sha1[20];
	const char *current_branch;

	/* get current branch */
	current_branch = resolve_ref("HEAD", head_sha1, 1, NULL);
	if (!current_branch)
		die("No current branch");
	if (!prefixcmp(current_branch, "refs/heads/"))
		current_branch += 11;

	/* get a line */
	while (pos < in->len) {
		int len;
		char *newline, *p = in->buf + pos;

		newline = strchr(p, '\n');
		len = newline ? newline - p : strlen(p);
		pos += len + !!newline;
		i++;
		p[len] = 0;
		if (handle_line(p))
			die ("Error in line %d: %.*s", i, len, p);
	}

	if (!srcs.nr)
		return 0;

	strbuf_addstr(out, "Merge ");
	for (i = 0; i < srcs.nr; i++) {
