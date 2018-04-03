    for (mp = &x->rn_mklist; (m = *mp); mp = &m->rm_mklist)
	if (m == saved_m) {
	    *mp = m->rm_mklist;
	    MKFree(m);
	    break;
	}
    if (m == 0) {
	fprintf(stderr, "rn_delete: couldn't find our annotation\n");
	if (tt->rn_flags & RNF_NORMAL)
	    return (0);		/* Dangling ref to us */
    }
