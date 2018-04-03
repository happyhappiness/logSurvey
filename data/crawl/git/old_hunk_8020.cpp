	}

	if (do_keep) {
		*av++ = "index-pack";
		*av++ = "--stdin";
		if (!quiet && !no_progress)
