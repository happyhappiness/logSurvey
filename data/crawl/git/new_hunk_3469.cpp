		pathspec->magic |= item[i].magic;
	}

	if (nr_exclude == n)
		die(_("There is nothing to exclude from by :(exclude) patterns.\n"
		      "Perhaps you forgot to add either ':/' or '.' ?"));


	if (pathspec->magic & PATHSPEC_MAXDEPTH) {
		if (flags & PATHSPEC_KEEP_ORDER)
