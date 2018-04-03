		opts.fn = twoway_merge;
	}

	if (!fill_tree_descriptor(desc + nr, oid)) {
		error(_("Failed to find tree of %s."), oid_to_hex(oid));
		goto out;
	}
	nr++;

	if (unpack_trees(nr, desc, &opts))
		goto out;

	if (reset_type == MIXED || reset_type == HARD) {
		tree = parse_tree_indirect(oid);
		prime_cache_tree(&the_index, tree);
	}

	ret = 0;

out:
	for (i = 0; i < nr; i++)
		free((void *)desc[i].buffer);
	return ret;
}

static void print_new_head_line(struct commit *commit)