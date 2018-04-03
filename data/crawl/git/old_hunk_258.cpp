		opts.fn = twoway_merge;
	}

	if (!fill_tree_descriptor(desc + nr, oid))
		return error(_("Failed to find tree of %s."), oid_to_hex(oid));
	nr++;

	if (unpack_trees(nr, desc, &opts))
		return -1;

	if (reset_type == MIXED || reset_type == HARD) {
		tree = parse_tree_indirect(oid);
		prime_cache_tree(&the_index, tree);
	}

	return 0;
}

static void print_new_head_line(struct commit *commit)