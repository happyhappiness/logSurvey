
	newfd = hold_locked_index(&lock_file, 1);

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];

		/* "-u" means "update", meaning that a merge will update
		 * the working tree.
		 */
		if (!strcmp(arg, "-u")) {
			opts.update = 1;
			continue;
		}

		if (!strcmp(arg, "-v")) {
			opts.verbose_update = 1;
			continue;
		}

		/* "-i" means "index only", meaning that a merge will
		 * not even look at the working tree.
		 */
		if (!strcmp(arg, "-i")) {
			opts.index_only = 1;
			continue;
		}

		if (!prefixcmp(arg, "--index-output=")) {
			set_alternate_index_output(arg + 15);
			continue;
		}

		/* "--prefix=<subdirectory>/" means keep the current index
		 *  entries and put the entries from the tree under the
		 * given subdirectory.
		 */
		if (!prefixcmp(arg, "--prefix=")) {
			if (stage || opts.merge || opts.prefix)
				usage(read_tree_usage);
			opts.prefix = arg + 9;
			opts.merge = 1;
			stage = 1;
			if (read_cache_unmerged())
				die("you need to resolve your current index first");
			continue;
		}

		/* This differs from "-m" in that we'll silently ignore
		 * unmerged entries and overwrite working tree files that
		 * correspond to them.
		 */
		if (!strcmp(arg, "--reset")) {
			if (stage || opts.merge || opts.prefix)
				usage(read_tree_usage);
			opts.reset = 1;
			opts.merge = 1;
			stage = 1;
			read_cache_unmerged();
			continue;
		}

		if (!strcmp(arg, "--trivial")) {
			opts.trivial_merges_only = 1;
			continue;
		}

		if (!strcmp(arg, "--aggressive")) {
			opts.aggressive = 1;
			continue;
		}

		/* "-m" stands for "merge", meaning we start in stage 1 */
		if (!strcmp(arg, "-m")) {
			if (stage || opts.merge || opts.prefix)
				usage(read_tree_usage);
			if (read_cache_unmerged())
				die("you need to resolve your current index first");
			stage = 1;
			opts.merge = 1;
			continue;
		}

		if (!prefixcmp(arg, "--exclude-per-directory=")) {
			struct dir_struct *dir;

			if (opts.dir)
				die("more than one --exclude-per-directory are given.");

			dir = xcalloc(1, sizeof(*opts.dir));
			dir->flags |= DIR_SHOW_IGNORED;
			dir->exclude_per_dir = arg + 24;
			opts.dir = dir;
			/* We do not need to nor want to do read-directory
			 * here; we are merely interested in reusing the
			 * per directory ignore stack mechanism.
			 */
			continue;
		}

		if (1 < opts.index_only + opts.update)
			die("-u and -i at the same time makes no sense");

		if (get_sha1(arg, sha1))
			die("Not a valid object name %s", arg);
		if (list_tree(sha1) < 0)
			die("failed to unpack tree object %s", arg);
		stage++;
	}
	if ((opts.update||opts.index_only) && !opts.merge)
		die("%s is meaningless without -m, --reset, or --prefix",
		    opts.update ? "-u" : "-i");
