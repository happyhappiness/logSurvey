
		if (lstat(ce->name, &st) < 0) {
			if (errno != ENOENT)
				warning("'%s': %s", ce->name, strerror(errno));
			/* It already vanished from the working tree */
			continue;
		}
