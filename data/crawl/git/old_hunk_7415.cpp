	for (cp = format; *cp && (sp = find_next(cp)); ) {
		const char *ep = strchr(sp, ')');
		if (!ep)
			return error("malformatted format string %s", sp);
		/* sp points at "%(" and ep points at the closing ")" */
		parse_atom(sp + 2, ep);
		cp = ep + 1;