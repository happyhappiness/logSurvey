    int i;
    storeAppendPrintf(sentry, "Internal DNS Statistics:\n");
    storeAppendPrintf(sentry, "\nThe Queue:\n");
    storeAppendPrintf(sentry, "  ID   SIZE SENDS   DELAY\n");
    storeAppendPrintf(sentry, "------ ---- ----- --------\n");
    for (n = lru_list.head; n; n = n->next) {
	q = n->data;
	storeAppendPrintf(sentry, "%#06x %4d %5d %8.3f\n",
	    (int) q->id, q->sz, q->nsends,
	    tvSubDsec(q->start_t, current_time));
    }
    storeAppendPrintf(sentry, "\nNameservers:\n");
    storeAppendPrintf(sentry, "IP ADDRESS      # QUERIES # REPLIES\n");
