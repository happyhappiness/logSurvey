		for (p = pathspec; *p; p++) {
			if (has_symlink_leading_path(*p, strlen(*p))) {
				int len = prefix ? strlen(prefix) : 0;
				die(_("'%s' is beyond a symbolic link"), *p + len);
			}
		}
	}
