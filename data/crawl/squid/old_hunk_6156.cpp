{
    dlink_node *n;
    idns_query *q;
    storeAppendPrintf(sentry, "Internal DNS Statistics:\n");
    storeAppendPrintf(sentry, "\nThe Queue:\n");
	storeAppendPrintf(sentry, " ID  SIZE SENDS   DELAY\n");
	storeAppendPrintf(sentry, "---- ---- ----- --------\n");
    for (n = lru_list.head; n; n = n->next) {
	q = n->data;
	storeAppendPrintf(sentry, "%#04hx %4d %5d %8.3f\n",
		q->id, q->sz, q->nsends,
		tvSubDsec(q->start, current_time));
    }
}

