	return hit;
}

static int match_expr_eval(struct grep_opt *o,
			   struct grep_expr *x,
			   char *bol, char *eol,
			   enum grep_context ctx,
			   int collect_hits)
{
	int h = 0;

	switch (x->node) {
	case GREP_NODE_ATOM:
		h = match_one_pattern(o, x->u.atom, bol, eol, ctx);
		break;
	case GREP_NODE_NOT:
		h = !match_expr_eval(o, x->u.unary, bol, eol, ctx, 0);
		break;
	case GREP_NODE_AND:
		if (!collect_hits)
			return (match_expr_eval(o, x->u.binary.left,
						bol, eol, ctx, 0) &&
				match_expr_eval(o, x->u.binary.right,
						bol, eol, ctx, 0));
		h = match_expr_eval(o, x->u.binary.left, bol, eol, ctx, 0);
		h &= match_expr_eval(o, x->u.binary.right, bol, eol, ctx, 0);
		break;
	case GREP_NODE_OR:
		if (!collect_hits)
			return (match_expr_eval(o, x->u.binary.left,
						bol, eol, ctx, 0) ||
				match_expr_eval(o, x->u.binary.right,
						bol, eol, ctx, 0));
		h = match_expr_eval(o, x->u.binary.left, bol, eol, ctx, 0);
		x->u.binary.left->hit |= h;
		h |= match_expr_eval(o, x->u.binary.right, bol, eol, ctx, 1);
		break;
	default:
		die("Unexpected node type (internal error) %d", x->node);
