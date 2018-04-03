				die("Invalid pathspec magic '%.*s' in '%s'",
				    (int) len, copyfrom, elt);
		}
		if (*copyfrom == ')')
			copyfrom++;
	} else {
		/* shorthand */
		for (copyfrom = elt + 1;