
		return check_ok_to_remove(path, len, DT_UNKNOWN, NULL, &st,
				error_type, o);
	} else if (lstat(ce->name, &st)) {
		if (errno != ENOENT)
			return error("cannot stat '%s': %s", ce->name,
				     strerror(errno));
		return 0;
	} else {
		return check_ok_to_remove(ce->name, ce_namelen(ce),
					  ce_to_dtype(ce), ce, &st,
					  error_type, o);
	}
}

static int verify_absent(struct cache_entry *ce,