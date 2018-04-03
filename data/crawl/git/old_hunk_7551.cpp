	tree = parse_tree_indirect(ent->sha1);
	if (!tree)
		return error("bad tree object %s", tree_name);
	if (read_tree(tree, 1, revs->prune_data))
		return error("unable to read tree object %s", tree_name);
	ret = diff_cache(revs, active_cache, active_nr, revs->prune_data,
			 cached, match_missing);
	diffcore_std(&revs->diffopt);
	diff_flush(&revs->diffopt);
	return ret;
}

int do_diff_cache(const unsigned char *tree_sha1, struct diff_options *opt)
