	const char *start = refname;

	if (nr < 1 || *end != '\0')
		die(_(":strip= requires a positive integer argument"));

	while (remaining) {
		switch (*start++) {
		case '\0':
			die(_("ref '%s' does not have %ld components to :strip"),
			    refname, nr);
		case '/':
			remaining--;
