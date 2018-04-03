	    if (p)
		p->rn_dupedkey = tt->rn_dupedkey;
	    else
		fprintf(stderr, "rn_delete: couldn't find us\n");
	}
	t = tt + 1;
	if (t->rn_flags & RNF_ACTIVE) {
