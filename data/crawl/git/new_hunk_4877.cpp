		char path[PATH_MAX + 1];
		memcpy(path, ce->name, len);
		path[len] = 0;
		if (lstat(path, &st))
			return error("cannot stat '%s': %s", path,
					strerror(errno));

		return check_ok_to_remove(path, len, DT_UNKNOWN, NULL, &st,
				error_type, o);