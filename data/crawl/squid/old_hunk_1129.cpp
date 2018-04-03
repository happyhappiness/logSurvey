    if (tt->rn_flags & RNF_NORMAL) {
        if (m->rm_leaf != tt || m->rm_refs > 0) {
            fprintf(stderr, "squid_rn_delete: inconsistent annotation\n");
            return 0;		/* dangling ref could cause disaster */
        }
    } else {
        if (m->rm_mask != tt->rn_mask) {
