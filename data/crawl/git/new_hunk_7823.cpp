		else if (reset_type != NONE)
			die("Cannot do %s reset with paths.",
					reset_type_names[reset_type]);
		return read_from_tree(prefix, argv + i, sha1);
	}
	if (reset_type == NONE)
		reset_type = MIXED; /* by default */
