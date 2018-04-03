{
	const char *p = message;
	if (!p)
		die (_("Could not read commit message of %s"),
				sha1_to_hex(commit->object.sha1));
	while (*p && *p != '\n') {
		const char *eol;
