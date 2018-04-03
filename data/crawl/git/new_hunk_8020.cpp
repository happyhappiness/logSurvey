	}

	if (do_keep) {
		if (pack_lockfile && pipe(keep_pipe))
			die("fetch-pack: pipe setup failure: %s", strerror(errno));
		*av++ = "index-pack";
		*av++ = "--stdin";
		if (!quiet && !no_progress)
