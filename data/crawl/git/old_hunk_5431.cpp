		/* This picks up the paths that are not tracked */
		baselen = fill_directory(&dir, pathspec);
		if (pathspec)
			prune_directory(&dir, pathspec, baselen);
	}

	if (refresh_only) {
		refresh(verbose, pathspec);
		goto finish;
	}

	exit_status |= add_files_to_cache(prefix, pathspec, flags);

	if (add_new_files)