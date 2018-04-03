
		h = compile_pattern_atom(&pp);
		if (!h || pp != p->next)
			die("BUG: malformed header expr");
		if (!header_group[p->field]) {
			header_group[p->field] = h;
			continue;
