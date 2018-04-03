    }
    cbdataCount--;
    debug(45, 3) ("cbdataFree: Freeing %p\n", p);
#if CBDATA_DEBUG
    dlinkDelete(&c->link, &cbdataEntries);
#endif
    free_func = cbdata_index[c->type].free_func;
    if (free_func)
	free_func((void *) p);
    memPoolFree(cbdata_index[c->type].pool, c);
    return NULL;
}

void
#if CBDATA_DEBUG
cbdataInternalLockDbg(const void *p, const char *file, int line)
#else
cbdataInternalLock(const void *p)
#endif
{
    cbdata *c;
    if (p == NULL)
	return;
    c = (cbdata *) (((char *) p) - OFFSET_OF(cbdata, data));
#if CBDATA_DEBUG
    debug(45, 3) ("cbdataLock: %p=%d %s:%d\n", p, c ? c->locks + 1 : -1, file, line);
#else
    debug(45, 3) ("cbdataLock: %p=%d\n", p, c ? c->locks + 1 : -1);
#endif
    CBDATA_CHECK(c);
    c->locks++;
}

void
#if CBDATA_DEBUG
cbdataInternalUnlockDbg(const void *p, const char *file, int line)
#else
cbdataInternalUnlock(const void *p)
#endif
{
    cbdata *c;
    FREE *free_func;
    if (p == NULL)
	return;
    c = (cbdata *) (((char *) p) - OFFSET_OF(cbdata, data));
#if CBDATA_DEBUG
    debug(45, 3) ("cbdataUnlock: %p=%d %s:%d\n", p, c ? c->locks - 1 : -1, file, line);
#else
    debug(45, 3) ("cbdataUnlock: %p=%d\n", p, c ? c->locks - 1 : -1);
#endif
    CBDATA_CHECK(c);
    assert(c != NULL);
    assert(c->locks > 0);
    c->locks--;
    if (c->valid || c->locks)
	return;
    cbdataCount--;
    debug(45, 3) ("cbdataUnlock: Freeing %p\n", p);
#if CBDATA_DEBUG
    dlinkDelete(&c->link, &cbdataEntries);
#endif
    free_func = cbdata_index[c->type].free_func;
    if (free_func)
	free_func((void *) p);
    memPoolFree(cbdata_index[c->type].pool, c);
}

int
cbdataReferenceValid(const void *p)
{
    cbdata *c;
    if (p == NULL)
	return 1;		/* A NULL pointer cannot become invalid */
    debug(45, 3) ("cbdataReferenceValid: %p\n", p);
    c = (cbdata *) (((char *) p) - OFFSET_OF(cbdata, data));
    CBDATA_CHECK(c);
    assert(c->locks > 0);
    return c->valid;
}

int
#if CBDATA_DEBUG
cbdataInternalReferenceDoneValidDbg(void **pp, void **tp, const char *file, int line)
#else
cbdataInternalReferenceDoneValid(void **pp, void **tp)
#endif
{
    void *p = (void *) *pp;
    int valid = cbdataReferenceValid(p);
    *pp = NULL;
#if CBDATA_DEBUG
    cbdataInternalUnlockDbg(p, file, line);
#else
    cbdataInternalUnlock(p);
#endif
    if (valid) {
	*tp = p;
	return 1;
    } else {
	*tp = NULL;
	return 0;
    }
}


static void
cbdataDump(StoreEntry * sentry)
{
#if CBDATA_DEBUG
    dlink_node *n;
    cbdata *p;
    int i;
#endif
    storeAppendPrintf(sentry, "%d cbdata entries\n", cbdataCount);
#if CBDATA_DEBUG
    storeAppendPrintf(sentry, "Pointer\tType\tLocks\tAllocated by\n");
    for (n = cbdataEntries.head; n; n = n->next) {
	p = n->data;
	storeAppendPrintf(sentry, "%c%p\t%d\t%d\t%20s:%-5d\n", p->valid ? ' ' : '!', &p->data, p->type, p->locks, p->file, p->line);
    }
    storeAppendPrintf(sentry, "\n");
    storeAppendPrintf(sentry, "types\tsize\tallocated\ttotal\n");
    for (i = 1; i < cbdata_types; i++) {
	MemPool *pool = cbdata_index[i].pool;
	if (pool) {
	    int obj_size = pool->obj_size - OFFSET_OF(cbdata, data);
	    storeAppendPrintf(sentry, "%s\t%d\t%d\t%d\n", pool->label + 7, obj_size, pool->meter.inuse.level, obj_size * pool->meter.inuse.level);
	}
    }
#else
    storeAppendPrintf(sentry, "detailed allocation information only available when compiled with CBDATA_DEBUG\n");
#endif
    storeAppendPrintf(sentry, "\nsee also \"Memory utilization\" for detailed per type statistics\n");
}
