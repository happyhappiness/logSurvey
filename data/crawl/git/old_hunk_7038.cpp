	free_list(&subjects);
}

int cmd_fmt_merge_msg(int argc, const char **argv, const char *prefix)
{
	int limit = 20, i = 0;
	char line[1024];
	FILE *in = stdin;
	const char *sep = "";
	unsigned char head_sha1[20];
	const char *current_branch;

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

	/* get current branch */
	current_branch = resolve_ref("HEAD", head_sha1, 1, NULL);
	if (!current_branch)
		die("No current branch");
	if (!prefixcmp(current_branch, "refs/heads/"))
		current_branch += 11;

	while (fgets(line, sizeof(line), in)) {
		i++;
		if (line[0] == 0)
			continue;
		if (handle_line(line))
			die ("Error in line %d: %s", i, line);
	}

	printf("Merge ");
	for (i = 0; i < srcs.nr; i++) {
		struct src_data *src_data = srcs.payload[i];
		const char *subsep = "";

		printf(sep);
		sep = "; ";

		if (src_data->head_status == 1) {
			printf(srcs.list[i]);
			continue;
		}
		if (src_data->head_status == 3) {
			subsep = ", ";
			printf("HEAD");
		}
		if (src_data->branch.nr) {
			printf(subsep);
			subsep = ", ";
			print_joined("branch ", "branches ", &src_data->branch);
		}
		if (src_data->r_branch.nr) {
			printf(subsep);
			subsep = ", ";
			print_joined("remote branch ", "remote branches ",
					&src_data->r_branch);
		}
		if (src_data->tag.nr) {
			printf(subsep);
			subsep = ", ";
			print_joined("tag ", "tags ", &src_data->tag);
		}
		if (src_data->generic.nr) {
			printf(subsep);
			print_joined("commit ", "commits ", &src_data->generic);
		}
		if (strcmp(".", srcs.list[i]))
			printf(" of %s", srcs.list[i]);
	}

	if (!strcmp("master", current_branch))
		putchar('\n');
	else
		printf(" into %s\n", current_branch);

	if (merge_summary) {
		struct commit *head;
		struct rev_info rev;

		head = lookup_commit(head_sha1);
		init_revisions(&rev, prefix);
		rev.commit_format = CMIT_FMT_ONELINE;
		rev.ignore_merges = 1;
		rev.limited = 1;

		for (i = 0; i < origins.nr; i++)
			shortlog(origins.list[i], origins.payload[i],
					head, &rev, limit);
	}

	/* No cleanup yet; is standalone anyway */

	return 0;
}
