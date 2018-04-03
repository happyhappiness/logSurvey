	len = end - start;
	strip_suffix_mem(start, &len, is_bundle ? ".bundle" : ".git");

	if (is_bare)
		dir = xstrfmt("%.*s.git", (int)len, start);
	else