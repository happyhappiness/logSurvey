		int len;

		fragment = xcalloc(1, sizeof(*fragment));
		fragment->linenr = linenr;
		len = parse_fragment(line, size, patch, fragment);
		if (len <= 0)
			die(_("corrupt patch at line %d"), linenr);
		fragment->patch = line;
		fragment->size = len;
		oldlines += fragment->oldlines;
