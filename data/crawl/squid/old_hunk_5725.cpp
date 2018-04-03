	goto on1;
    if (tt->rn_flags & RNF_NORMAL) {
	if (m->rm_leaf != tt || m->rm_refs > 0) {
	    fprintf(stderr, "rn_delete: inconsistent annotation\n");
	    return 0;		/* dangling ref could cause disaster */
	}
    } else {
	if (m->rm_mask != tt->rn_mask) {
	    fprintf(stderr, "rn_delete: inconsistent annotation\n");
	    goto on1;
	}
	if (--m->rm_refs >= 0)
