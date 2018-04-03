				die("Invalid pathspec magic '%.*s' in '%s'",
				    (int) len, copyfrom, elt);
		}
		if (*copyfrom != ')')
			die("Missing ')' at the end of pathspec magic in '%s'", elt);
		copyfrom++;
	} else {
		/* shorthand */
		for (copyfrom = elt + 1;