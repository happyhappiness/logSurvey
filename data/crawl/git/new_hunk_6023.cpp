		av = default_arg - 1; /* ick; we would not address av[0] */
	}

	ac = parse_options(ac, av, builtin_show_branch_options,
			   show_branch_usage, PARSE_OPT_STOP_AT_NON_OPTION);
	if (all_heads)
		all_remotes = 1;

	if (extra || reflog) {
		/* "listing" mode is incompatible with
		 * independent nor merge-base modes.
		 */
		if (independent || merge_base)
			usage_with_options(show_branch_usage,
					   builtin_show_branch_options);
		if (reflog && ((0 < extra) || all_heads || all_remotes))
			/*
			 * Asking for --more in reflog mode does not
			 * make sense.  --list is Ok.
			 *
			 * Also --all and --remotes do not make sense either.
			 */
			die("--reflog is incompatible with --all, --remotes, "
			    "--independent or --merge-base");
	}

	/* If nothing is specified, show all branches by default */