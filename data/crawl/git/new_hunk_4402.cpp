	const char *p = message, *eol;

	if (!p)
		die (_("Could not read commit message of %s"),
				sha1_to_hex(commit->object.sha1));
	while (*p && *p != '\n') {
		for (eol = p + 1; *eol && *eol != '\n'; eol++)
