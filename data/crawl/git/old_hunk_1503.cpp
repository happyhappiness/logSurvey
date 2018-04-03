	ce = active_cache[pos];
	if (lstat(name, &st)) {
		if (errno != ENOENT)
			return error(_("%s: %s"), name, strerror(errno));
		if (checkout_target(&the_index, ce, &st))
			return -1;
	}
