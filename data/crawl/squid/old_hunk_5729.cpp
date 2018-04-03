    tt->rn_b = -1 - off;
    *ttt = *tt;
    ttt->rn_key = rn_ones;
    rnh->rnh_addaddr = rn_addroute;
    rnh->rnh_deladdr = rn_delete;
    rnh->rnh_matchaddr = rn_match;
    rnh->rnh_lookup = rn_lookup;
    rnh->rnh_walktree = rn_walktree;
    rnh->rnh_treetop = t;
    return (1);
}

void
rn_init(void)
{
    char *cp, *cplim;
#ifdef KERNEL
    struct domain *dom;

    for (dom = domains; dom; dom = dom->dom_next)
	if (dom->dom_maxrtkey > max_keylen)
	    max_keylen = dom->dom_maxrtkey;
#endif
    if (max_keylen == 0) {
	fprintf(stderr,
	    "rn_init: radix functions require max_keylen be set\n");
	return;
    }
    R_Malloc(rn_zeros, char *, 3 * max_keylen);
    if (rn_zeros == NULL) {
	fprintf(stderr, "rn_init failed.\n");
	exit(-1);
    }
    memset(rn_zeros, '\0', 3 * max_keylen);
    rn_ones = cp = rn_zeros + max_keylen;
    addmask_key = cplim = rn_ones + max_keylen;
    while (cp < cplim)
	*cp++ = -1;
    if (rn_inithead((void **) &mask_rnhead, 0) == 0) {
	fprintf(stderr, "rn_init2 failed.\n");
	exit(-1);
    }
