{
    hash_link *hptr;
    cbdata *c;
    for (hptr = hash_first(htable); hptr; hptr = hash_next(htable)) {
	c = (cbdata *) hptr;
	storeAppendPrintf(sentry, "%20p %10s %d locks\n",