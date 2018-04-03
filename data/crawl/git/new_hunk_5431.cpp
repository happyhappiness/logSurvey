		/* This picks up the paths that are not tracked */
		baselen = fill_directory(&dir, pathspec);
		if (pathspec)
			seen = prune_directory(&dir, pathspec, baselen);
	}

	if (refresh_only) {
		refresh(verbose, pathspec);
		goto finish;
	}

	if (pathspec) {
		int i;
		if (!seen)
			seen = find_used_pathspec(pathspec);
		for (i = 0; pathspec[i]; i++) {
			if (!seen[i] && pathspec[i][0]
			    && !file_exists(pathspec[i]))
				die("pathspec '%s' did not match any files",
				    pathspec[i]);
		}
		free(seen);
	}

	exit_status |= add_files_to_cache(prefix, pathspec, flags);

	if (add_new_files)