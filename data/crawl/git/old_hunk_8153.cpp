	memcpy(ce->name, path, namelen);
	ce->ce_mode = create_ce_mode(mode);
	ce->ce_flags = htons(namelen);
	if (!cached) {
		if (lstat(path, &st) < 0)
			die("unable to stat newly created file %s", path);
		fill_stat_cache_info(ce, &st);
	}
	if (write_sha1_file(buf, size, blob_type, ce->sha1) < 0)
		die("unable to create backing store for newly created file %s", path);
	if (add_cache_entry(ce, ADD_CACHE_OK_TO_ADD) < 0)
		die("unable to add cache entry for %s", path);
}
