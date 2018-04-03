#endif
    if (c->valid || c->locks)
	return;
    cbdataCount--;
    debug(45, 3) ("cbdataUnlock: Freeing %p\n", p);
    if (c->unlock_func)
	c->unlock_func((void *) p);
    memPoolFree(cbdata_memory_pool[c->type], c);
}

int
cbdataValid(const void *p)
{
    cbdata *c;
    if (p == NULL)
	return 1;		/* A NULL pointer cannot become invalid */
    debug(45, 3) ("cbdataValid: %p\n", p);
    c = (cbdata *) (((char *) p) - OFFSET_OF(cbdata, data));
    assert(c->y == c);
    assert(c->locks > 0);
    return c->valid;
}

static void
cbdataDump(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "%d cbdata entries\n", cbdataCount);
    storeAppendPrintf(sentry, "see also memory pools section\n");
}
