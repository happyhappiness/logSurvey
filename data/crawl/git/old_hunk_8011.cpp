			die("fetch-pack: pipe setup failure: %s", strerror(errno));
		*av++ = "index-pack";
		*av++ = "--stdin";
		if (!quiet && !no_progress)
			*av++ = "-v";
		if (use_thin_pack)
			*av++ = "--fix-thin";
		if (keep_pack > 1 || unpack_limit) {
			int s = sprintf(keep_arg,
					"--keep=fetch-pack %d on ", getpid());
			if (gethostname(keep_arg + s, sizeof(keep_arg) - s))
