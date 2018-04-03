
		if (lstat(ce->name, &st) < 0) {
			if (errno != ENOENT && errno != ENOTDIR)
				warning_errno(_("failed to stat '%s'"), ce->name);
			/* It already vanished from the working tree */
			continue;
		}