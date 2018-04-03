			git_dir = submodule_git_dir.buf;
		if (is_directory(git_dir)) {
			if (!quiet)
				fprintf(stderr, "Fetching submodule %s%s\n", prefix, ce->name);
			cp.dir = submodule_path.buf;
			argv_array_push(&argv, default_argv);
			argv_array_push(&argv, "--submodule-prefix");
