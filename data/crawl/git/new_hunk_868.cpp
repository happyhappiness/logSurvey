		; /* nothing to do */
	} else if (elt[1] == '(') {
		/* longhand */
		copyfrom = parse_long_magic(&element_magic,
					    &pathspec_prefix,
					    elt);
	} else {
		/* shorthand */
		copyfrom = parse_short_magic(&element_magic, elt);