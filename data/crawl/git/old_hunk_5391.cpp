	pos = cache_name_pos(fullname, fullnamelen);
	if (pos < 0)
		pos = -pos - 1;
	ce = active_cache[pos];
	if (ce_namelen(ce) == fullnamelen &&
	    !memcmp(ce->name, fullname, fullnamelen))
		die("Path '%s' is in the index, but not '%s'.\n"
		    "Did you mean ':%d:%s'?",
		    fullname, filename,
		    ce_stage(ce), fullname);

	if (!lstat(filename, &st))
		die("Path '%s' exists on disk, but not in the index.", filename);