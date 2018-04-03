    storeAppendPrintf(sentry, "  ID   SIZE SENDS FIRST SEND LAST SEND\n");
    storeAppendPrintf(sentry, "------ ---- ----- ---------- ---------\n");
    for (n = lru_list.head; n; n = n->next) {
	q = (idns_query *)n->data;
	storeAppendPrintf(sentry, "%#06x %4d %5d %10.3f %9.3f\n",
	    (int) q->id, (int) q->sz, q->nsends,
	    tvSubDsec(q->start_t, current_time),
