    storeAppendPrintf(sentry, "%d cbdata entries\n", cbdataCount);
    for (hptr = hash_first(htable); hptr; hptr = hash_next(htable)) {
	c = (cbdata *) hptr;
	storeAppendPrintf(sentry, "%20p %10s %d locks\n",
	    c->key,
	    c->valid ? "VALID" : "NOT VALID",
	    c->locks);
    }
}
