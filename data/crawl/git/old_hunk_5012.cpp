	if (!x)
		die("Not a valid grep expression");
	switch (x->node) {
	case GREP_NODE_ATOM:
		h = match_one_pattern(x->u.atom, bol, eol, ctx, &match, 0);
		break;
