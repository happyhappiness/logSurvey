	if ((opts.dir && !opts.update))
		die("--exclude-per-directory is meaningless unless -u");

	if (opts.prefix) {
		int pfxlen = strlen(opts.prefix);
		int pos;
		if (opts.prefix[pfxlen-1] != '/')
			die("prefix must end with /");
		if (stage != 2)
			die("binding merge takes only one tree");
		pos = cache_name_pos(opts.prefix, pfxlen);
		if (0 <= pos)
			die("corrupt index file");
		pos = -pos-1;
		if (pos < active_nr &&
		    !strncmp(active_cache[pos]->name, opts.prefix, pfxlen))
			die("subdirectory '%s' already exists.", opts.prefix);
		pos = cache_name_pos(opts.prefix, pfxlen-1);
		if (0 <= pos)
			die("file '%.*s' already exists.",
					pfxlen-1, opts.prefix);
		opts.pos = -1 - pos;
	}

	if (opts.merge) {
		if (stage < 2)
			die("just how do you expect me to merge %d trees?", stage-1);
