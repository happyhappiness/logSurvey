	if (pathspec) {
		const char **p;
		for (p = pathspec; *p; p++) {
			if (has_symlink_leading_path(strlen(*p), *p)) {
				int len = prefix ? strlen(prefix) : 0;
				die("'%s' is beyond a symbolic link", *p + len);
			}
