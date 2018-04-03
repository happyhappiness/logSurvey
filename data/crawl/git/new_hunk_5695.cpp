		int len;

		fragment = xcalloc(1, sizeof(*fragment));
		fragment->linenr = linenr;
		len = parse_fragment(line, size, patch, fragment);
		if (len <= 0)
			die("corrupt patch at line %d", linenr);
