			posns[i] = create_tree_entry_list(t+i);

		if (unpack_trees_rec(posns, len, o->prefix ? o->prefix : "",
				     o, &df_conflict_list))
			return -1;
	}

	if (o->trivial_merges_only && o->nontrivial_merge)
		return error("Merge requires file-level merging");

	check_updates(active_cache, active_nr, o);
	return 0;
