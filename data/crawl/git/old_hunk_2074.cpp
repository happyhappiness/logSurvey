		struct stat st;

		if (lstat(ce->name, &st)) {
			error("lstat(%s): %s", ce->name, strerror(errno));
			continue;
		}