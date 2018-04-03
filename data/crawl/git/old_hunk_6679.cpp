		die("invalid cache");
	}

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];

		if (!strcmp(arg, "--")) {
			i++;
			break;
		}
		if (!strcmp(arg, "-a") || !strcmp(arg, "--all")) {
			all = 1;
			continue;
		}
		if (!strcmp(arg, "-f") || !strcmp(arg, "--force")) {
			state.force = 1;
			continue;
		}
		if (!strcmp(arg, "-q") || !strcmp(arg, "--quiet")) {
			state.quiet = 1;
			continue;
		}
		if (!strcmp(arg, "-n") || !strcmp(arg, "--no-create")) {
			state.not_new = 1;
			continue;
		}
		if (!strcmp(arg, "-u") || !strcmp(arg, "--index")) {
			state.refresh_cache = 1;
			if (newfd < 0)
				newfd = hold_locked_index(&lock_file, 1);
			continue;
		}
		if (!strcmp(arg, "-z")) {
			line_termination = 0;
			continue;
		}
		if (!strcmp(arg, "--stdin")) {
			if (i != argc - 1)
				die("--stdin must be at the end");
			read_from_stdin = 1;
			i++; /* do not consider arg as a file name */
			break;
		}
		if (!strcmp(arg, "--temp")) {
			to_tempfile = 1;
			continue;
		}
		if (!prefixcmp(arg, "--prefix=")) {
			state.base_dir = arg+9;
			state.base_dir_len = strlen(state.base_dir);
			continue;
		}
		if (!prefixcmp(arg, "--stage=")) {
			if (!strcmp(arg + 8, "all")) {
				to_tempfile = 1;
				checkout_stage = CHECKOUT_ALL;
			} else {
				int ch = arg[8];
				if ('1' <= ch && ch <= '3')
					checkout_stage = arg[8] - '0';
				else
					die("stage should be between 1 and 3 or all");
			}
			continue;
		}
		if (arg[0] == '-')
			usage(checkout_cache_usage);
		break;
	}

	if (state.base_dir_len || to_tempfile) {
		/* when --prefix is specified we do not
