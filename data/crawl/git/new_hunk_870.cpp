		copyfrom++;
	} else {
		/* shorthand */
		copyfrom = parse_short_magic(&element_magic, elt);
	}

	magic |= element_magic;