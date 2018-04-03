{
	int h = 0;

	switch (x->node) {
	case GREP_NODE_ATOM:
		h = match_one_pattern(o, x->u.atom, bol, eol, ctx);
