	if (!cmit)
		die(_("%s is not a valid '%s' object"), arg, commit_type);

	n = find_commit_name(get_object_hash(cmit->object));
	if (n && (tags || all || n->prio == 2)) {
		/*
		 * Exact match to an existing ref.
		 */
		display_name(n);
		if (longformat)
			show_suffix(0, n->tag ? get_object_hash(*n->tag->tagged) : sha1);
		if (dirty)
			printf("%s", dirty);
		printf("\n");
