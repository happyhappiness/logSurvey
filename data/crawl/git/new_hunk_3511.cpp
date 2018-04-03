		const char *s = buf;

		if (get_sha1_hex(s + strlen("Subproject commit "), ce->sha1))
			die(_("corrupt patch for submodule %s"), path);
	} else {
		if (!cached) {
			if (lstat(path, &st) < 0)
