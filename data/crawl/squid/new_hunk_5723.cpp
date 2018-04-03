    if (mlen <= skip) {
	if (m0 >= last_zeroed)
	    last_zeroed = mlen;
	return (squid_mask_rnhead->rnh_nodes);
    }
    if (m0 < last_zeroed)
	memset(addmask_key + m0, '\0', last_zeroed - m0);
    *addmask_key = last_zeroed = mlen;
    x = squid_rn_search(addmask_key, rn_masktop);
    if (memcmp(addmask_key, x->rn_key, mlen) != 0)
	x = 0;
    if (x || search)
	return (x);
    squid_R_Malloc(x, struct squid_radix_node *, squid_max_keylen + 2 * sizeof(*x));
    if ((saved_x = x) == 0)
	return (0);
    memset(x, '\0', squid_max_keylen + 2 * sizeof(*x));
    netmask = cp = (caddr_t) (x + 2);
    memcpy(cp, addmask_key, mlen);
    x = squid_rn_insert(cp, squid_mask_rnhead, &maskduplicated, x);
    if (maskduplicated) {
	fprintf(stderr, "squid_rn_addmask: mask impossibly already in tree");
	squid_Free(saved_x);
	return (x);
    }
    /*
