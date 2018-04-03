		commit_list_insert(current_head, &parents);
	}

	if (write_cache_as_tree(tree.hash, 0, NULL)) {
		res = error(_("git write-tree failed to write a tree"));
		goto out;
