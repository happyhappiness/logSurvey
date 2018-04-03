	clean = merge_trees(&o,
			    head_tree,
			    next_tree, base_tree, &result);
	strbuf_release(&o.obuf);
	if (clean < 0)
		return clean;