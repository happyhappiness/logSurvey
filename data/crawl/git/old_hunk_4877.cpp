		char path[PATH_MAX + 1];
		memcpy(path, ce->name, len);
		path[len] = 0;
		lstat(path, &st);

		return check_ok_to_remove(path, len, DT_UNKNOWN, NULL, &st,
				error_type, o);