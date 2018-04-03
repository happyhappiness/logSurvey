		int at;

		if (!ep)
			return error("malformed format string %s", sp);
		/* sp points at "%(" and ep points at the closing ")" */
		at = parse_ref_filter_atom(sp + 2, ep);
		cp = ep + 1;
