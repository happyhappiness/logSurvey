
	save_commit_buffer = 0;

	if (longformat && abbrev == 0)
		die("--long is incompatible with --abbrev=0");

	if (contains) {
		const char **args = xmalloc((6 + argc) * sizeof(char*));
		int i = 0;
