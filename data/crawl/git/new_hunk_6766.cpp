	return 0;
}

static int levenshtein_compare(const void *p1, const void *p2)
{
	const struct cmdname *const *c1 = p1, *const *c2 = p2;
	const char *s1 = (*c1)->name, *s2 = (*c2)->name;
	int l1 = (*c1)->len;
	int l2 = (*c2)->len;
	return l1 != l2 ? l1 - l2 : strcmp(s1, s2);
}

const char *help_unknown_cmd(const char *cmd)
{
	int i, n, best_similarity = 0;
	struct cmdnames main_cmds, other_cmds;

	memset(&main_cmds, 0, sizeof(main_cmds));
	memset(&other_cmds, 0, sizeof(main_cmds));

	load_command_list("git-", &main_cmds, &other_cmds);

	ALLOC_GROW(main_cmds.names, main_cmds.cnt + other_cmds.cnt,
		   main_cmds.alloc);
	memcpy(main_cmds.names + main_cmds.cnt, other_cmds.names,
	       other_cmds.cnt * sizeof(other_cmds.names[0]));
	main_cmds.cnt += other_cmds.cnt;
	free(other_cmds.names);

	/* This reuses cmdname->len for similarity index */
	for (i = 0; i < main_cmds.cnt; ++i)
		main_cmds.names[i]->len =
			levenshtein(cmd, main_cmds.names[i]->name, 0, 2, 1, 4);

	qsort(main_cmds.names, main_cmds.cnt,
	      sizeof(*main_cmds.names), levenshtein_compare);

	if (!main_cmds.cnt)
		die ("Uh oh. Your system reports no Git commands at all.");

	best_similarity = main_cmds.names[0]->len;
	n = 1;
	while (n < main_cmds.cnt && best_similarity == main_cmds.names[n]->len)
		++n;
	if (n == 1) {
		const char *assumed = main_cmds.names[0]->name;
		main_cmds.names[0] = NULL;
		clean_cmdnames(&main_cmds);
		fprintf(stderr, "WARNING: You called a Git program named '%s', "
			"which does not exist.\n"
			"Continuing under the assumption that you meant '%s'\n",
			cmd, assumed);
		return assumed;
	}

	fprintf(stderr, "git: '%s' is not a git-command. See 'git --help'.\n", cmd);

	if (best_similarity < 6) {
		fprintf(stderr, "\nDid you mean %s?\n",
			n < 2 ? "this": "one of these");

		for (i = 0; i < n; i++)
			fprintf(stderr, "\t%s\n", main_cmds.names[i]->name);
	}

	exit(1);
}

