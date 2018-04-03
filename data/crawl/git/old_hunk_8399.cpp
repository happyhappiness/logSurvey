	    (baselen < chomp_prefix || memcmp(ls_tree_prefix, base, chomp_prefix)))
		return 0;

	if (!(ls_options & LS_NAME_ONLY))
		printf("%06o %s %s\t", mode, type,
				abbrev ? find_unique_abbrev(sha1,abbrev)
					: sha1_to_hex(sha1));
	write_name_quoted(base + chomp_prefix, baselen - chomp_prefix,
			  pathname,
			  line_termination, stdout);
