
		return check_ok_to_remove(path, len, DT_UNKNOWN, NULL, &st,
				error_type, o);
	} else if (!lstat(ce->name, &st))
		return check_ok_to_remove(ce->name, ce_namelen(ce),
				ce_to_dtype(ce), ce, &st,
				error_type, o);

	return 0;
}

static int verify_absent(struct cache_entry *ce,