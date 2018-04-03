    if (mlen <= skip) {
	if (m0 >= last_zeroed)
	    last_zeroed = mlen;
	return (mask_rnhead->rnh_nodes);
    }
    if (m0 < last_zeroed)
	memset(addmask_key + m0, '\0', last_zeroed - m0);
    *addmask_key = last_zeroed = mlen;
    x = rn_search(addmask_key, rn_masktop);
    if (memcmp(addmask_key, x->rn_key, mlen) != 0)
	x = 0;
    if (x || search)
	return (x);
    R_Malloc(x, struct radix_node *, max_keylen + 2 * sizeof(*x));
    if ((saved_x = x) == 0)
	return (0);
    memset(x, '\0', max_keylen + 2 * sizeof(*x));
    netmask = cp = (caddr_t) (x + 2);
    memcpy(cp, addmask_key, mlen);
    x = rn_insert(cp, mask_rnhead, &maskduplicated, x);
    if (maskduplicated) {
	fprintf(stderr, "rn_addmask: mask impossibly already in tree");
	Free(saved_x);
	return (x);
    }
    /*
