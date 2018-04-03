			continue;
		}

		/* using -u and -i at the same time makes no sense */
		if (1 < opts.index_only + opts.update)
			usage(read_tree_usage);

		if (get_sha1(arg, sha1))
			die("Not a valid object name %s", arg);
