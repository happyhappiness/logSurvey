	if (reset_type == KEEP) {
		unsigned char head_sha1[20];
		if (get_sha1("HEAD", head_sha1))
			return error("You do not have a valid HEAD.");
		if (!fill_tree_descriptor(desc, head_sha1))
			return error("Failed to find tree of HEAD.");
		nr++;
		opts.fn = twoway_merge;
	}

	if (!fill_tree_descriptor(desc + nr - 1, sha1))
		return error("Failed to find tree of %s.", sha1_to_hex(sha1));
	if (unpack_trees(nr, desc, &opts))
		return -1;
	if (write_cache(newfd, active_cache, active_nr) ||
	    commit_locked_index(lock))
		return error("Could not write new index file.");

	return 0;
}
