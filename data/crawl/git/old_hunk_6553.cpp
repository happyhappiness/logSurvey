		h |= match_expr_eval(o, x->u.binary.right, bol, eol, ctx, 1);
		break;
	default:
		die("Unexpected node type (internal error) %d\n", x->node);
	}
	if (collect_hits)
		x->hit |= h;
