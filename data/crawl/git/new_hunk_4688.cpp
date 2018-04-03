	    ce_stage(active_cache[pos+1]) != 2 ||
	    strcmp(active_cache[pos+2]->name, path) ||
	    ce_stage(active_cache[pos+2]) != 3)
		return error(_("path '%s' does not have all 3 versions"), path);

	read_mmblob(&ancestor, active_cache[pos]->sha1);
	read_mmblob(&ours, active_cache[pos+1]->sha1);
