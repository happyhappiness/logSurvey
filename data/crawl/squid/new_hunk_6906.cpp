    storeAppendPrintf(sentry, "%d cbdata entries\n", cbdataCount);
    for (hptr = hash_first(htable); hptr; hptr = hash_next(htable)) {
	c = (cbdata *) hptr;
#if CBDATA_DEBUG
	storeAppendPrintf(sentry, "%20p %10s %d locks %s:%d\n",
	    c->key,
	    c->valid ? "VALID" : "NOT VALID",
	    c->locks,
	    c->file, c->line);
#else
	storeAppendPrintf(sentry, "%20p %10s %d locks\n",
	    c->key,
	    c->valid ? "VALID" : "NOT VALID",
	    c->locks);
#endif
    }
}
