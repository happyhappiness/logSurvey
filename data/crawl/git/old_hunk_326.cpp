		struct object_id head_oid;
		if (get_oid("HEAD", &head_oid))
			return error(_("You do not have a valid HEAD."));
		if (!fill_tree_descriptor(desc, head_oid.hash))
			return error(_("Failed to find tree of HEAD."));
		nr++;
		opts.fn = twoway_merge;
	}

	if (!fill_tree_descriptor(desc + nr - 1, oid->hash))
		return error(_("Failed to find tree of %s."), oid_to_hex(oid));
	if (unpack_trees(nr, desc, &opts))
		return -1;
