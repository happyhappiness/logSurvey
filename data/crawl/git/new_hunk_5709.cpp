		parse_commit(new->commit);
	}

	ret = merge_working_tree(opts, &old, new);
	if (ret)
		return ret;
