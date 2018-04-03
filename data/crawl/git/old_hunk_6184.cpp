				die("more than one --exclude-per-directory are given.");

			dir = xcalloc(1, sizeof(*opts.dir));
			dir->show_ignored = 1;
			dir->exclude_per_dir = arg + 24;
			opts.dir = dir;
			/* We do not need to nor want to do read-directory
