	free_list(&subjects);
}

int fmt_merge_msg(int merge_summary, struct strbuf *in, struct strbuf *out) {
	int limit = 20, i = 0, pos = 0;
	char line[1024];
	char *p = line, *sep = "";
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
		char *newline;

		p = in->buf + pos;
		newline = strchr(p, '\n');
		len = newline ? newline - p : strlen(p);
		pos += len + !!newline;
		i++;
		p[len] = 0;
		if (handle_line(p))
			die ("Error in line %d: %.*s", i, len, p);
	}

	strbuf_addstr(out, "Merge ");
	for (i = 0; i < srcs.nr; i++) {
		struct src_data *src_data = srcs.payload[i];
		const char *subsep = "";

		strbuf_addstr(out, sep);
		sep = "; ";

		if (src_data->head_status == 1) {
			strbuf_addstr(out, srcs.list[i]);
			continue;
		}
		if (src_data->head_status == 3) {
			subsep = ", ";
			strbuf_addstr(out, "HEAD");
		}
		if (src_data->branch.nr) {
			strbuf_addstr(out, subsep);
			subsep = ", ";
			print_joined("branch ", "branches ", &src_data->branch,
					out);
		}
		if (src_data->r_branch.nr) {
			strbuf_addstr(out, subsep);
			subsep = ", ";
			print_joined("remote branch ", "remote branches ",
					&src_data->r_branch, out);
		}
		if (src_data->tag.nr) {
			strbuf_addstr(out, subsep);
			subsep = ", ";
			print_joined("tag ", "tags ", &src_data->tag, out);
		}
		if (src_data->generic.nr) {
			strbuf_addstr(out, subsep);
			print_joined("commit ", "commits ", &src_data->generic,
					out);
		}
		if (strcmp(".", srcs.list[i]))
			strbuf_addf(out, " of %s", srcs.list[i]);
	}

	if (!strcmp("master", current_branch))
		strbuf_addch(out, '\n');
	else
		strbuf_addf(out, " into %s\n", current_branch);

	if (merge_summary) {
		struct commit *head;
		struct rev_info rev;

		head = lookup_commit(head_sha1);
		init_revisions(&rev, NULL);
		rev.commit_format = CMIT_FMT_ONELINE;
		rev.ignore_merges = 1;
		rev.limited = 1;

		for (i = 0; i < origins.nr; i++)
			shortlog(origins.list[i], origins.payload[i],
					head, &rev, limit, out);
	}
	return 0;
}

int cmd_fmt_merge_msg(int argc, const char **argv, const char *prefix)
{
	FILE *in = stdin;
	struct strbuf input, output;
	int ret;

	git_config(fmt_merge_msg_config, NULL);

	while (argc > 1) {
		if (!strcmp(argv[1], "--log") || !strcmp(argv[1], "--summary"))
			merge_summary = 1;
		else if (!strcmp(argv[1], "--no-log")
				|| !strcmp(argv[1], "--no-summary"))
			merge_summary = 0;
		else if (!strcmp(argv[1], "-F") || !strcmp(argv[1], "--file")) {
			if (argc < 3)
				die ("Which file?");
			if (!strcmp(argv[2], "-"))
				in = stdin;
			else {
				fclose(in);
				in = fopen(argv[2], "r");
				if (!in)
					die("cannot open %s", argv[2]);
			}
			argc--; argv++;
		} else
			break;
		argc--; argv++;
	}

	if (argc > 1)
		usage(fmt_merge_msg_usage);

	strbuf_init(&input, 0);
	if (strbuf_read(&input, fileno(in), 0) < 0)
		die("could not read input file %s", strerror(errno));
	strbuf_init(&output, 0);

	ret = fmt_merge_msg(merge_summary, &input, &output);
	if (ret)
		return ret;
	printf("%s", output.buf);
	return 0;
}
