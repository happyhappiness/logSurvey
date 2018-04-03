	alias_string = alias_lookup(alias_command);
	if (alias_string) {
		if (alias_string[0] == '!') {
			const char **alias_argv;
			int argc = *argcp, i;

			commit_pager_choice();

			/* build alias_argv */
			alias_argv = xmalloc(sizeof(*alias_argv) * (argc + 1));
			alias_argv[0] = alias_string + 1;
			for (i = 1; i < argc; ++i)
				alias_argv[i] = (*argv)[i];
			alias_argv[argc] = NULL;

			ret = run_command_v_opt(alias_argv, RUN_USING_SHELL);
			if (ret >= 0)   /* normal exit */
				exit(ret);

			die_errno("While expanding alias '%s': '%s'",
			    alias_command, alias_string + 1);
		}
		count = split_cmdline(alias_string, &new_argv);
		if (count < 0)