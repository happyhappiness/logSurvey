	} while (b > (unsigned) x->rn_b);	/* x->rn_b < b && x->rn_b >= 0 */
#ifdef RN_DEBUG
	if (rn_debug)
	    fprintf(stderr, "rn_insert: Going In:\n");
	traverse(p);
#endif
	t = rn_newpair(v_arg, b, nodes);
	tt = t->rn_l;
	if ((cp[p->rn_off] & p->rn_bmask) == 0)
	    p->rn_l = t;
