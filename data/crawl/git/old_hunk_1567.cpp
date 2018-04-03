		fragment = xcalloc(1, sizeof(*fragment));
		fragment->linenr = state->linenr;
		len = parse_fragment(state, line, size, patch, fragment);
		if (len <= 0)
			die(_("corrupt patch at line %d"), state->linenr);
		fragment->patch = line;
		fragment->size = len;
		oldlines += fragment->oldlines;
