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
