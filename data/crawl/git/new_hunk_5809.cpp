	} else {
		const char *cwd = get_pwd_cwd();
		if (!cwd)
			die_errno("Cannot determine the current working directory");
		if (snprintf(buf, PATH_MAX, "%s/%s", cwd, path) >= PATH_MAX)
			die("Too long path: %.*s", 60, path);
	}
