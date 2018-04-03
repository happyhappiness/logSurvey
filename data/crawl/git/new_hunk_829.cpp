	clean = merge_trees(&o,
			    head_tree,
			    next_tree, base_tree, &result);
	if (is_rebase_i(opts) && clean <= 0)
		fputs(o.obuf.buf, stdout);
	strbuf_release(&o.obuf);
	if (clean < 0)
		return clean;