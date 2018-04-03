		die("--long is incompatible with --abbrev=0");

	if (contains) {
		const char **args = xmalloc((7 + argc) * sizeof(char*));
		int i = 0;
		args[i++] = "name-rev";
		args[i++] = "--name-only";
		args[i++] = "--no-undefined";
		if (always)
			args[i++] = "--always";
		if (!all) {
			args[i++] = "--tags";
			if (pattern) {
