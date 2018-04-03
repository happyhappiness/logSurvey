		struct stat st;

		if (lstat(ce->name, &st)) {
			error_errno("lstat(%s)", ce->name);
			continue;
		}
