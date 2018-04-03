		return;
	}

	if (!max_candidates)
		die("no tag exactly matches '%s'", sha1_to_hex(cmit->object.sha1));
	if (debug)
		fprintf(stderr, "searching to describe %s\n", arg);

