		die ("Too long path: %.*s", 60, path);

	while (depth--) {
		if (!is_directory(buf)) {
			char *last_slash = strrchr(buf, '/');
			if (last_slash) {
				*last_slash = '\0';
