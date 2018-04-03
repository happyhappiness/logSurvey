		else if (reset_type != NONE)
			die("Cannot do %s reset with paths.",
					reset_type_names[reset_type]);
		if (read_from_tree(prefix, argv + i, sha1))
			return 1;
		return update_index_refresh() ? 1 : 0;
	}
	if (reset_type == NONE)
		reset_type = MIXED; /* by default */
