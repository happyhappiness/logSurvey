    }
    cbdataCount--;
    debug(45, 3) ("cbdataFree: Freeing %p\n", p);
    free_func = cbdata_index[c->type].free_func;
    if (free_func)
	free_func((void *) p);
    memPoolFree(cbdata_index[c->type].pool, c);
    return NULL;
}

int
cbdataLocked(const void *p)
{
    cbdata *c;
    assert(p);
    c = (cbdata *) (((char *) p) - OFFSET_OF(cbdata, data));
    assert(c->y == c);
    debug(45, 3) ("cbdataLocked: %p = %d\n", p, c->locks);
    assert(c != NULL);
    return c->locks;
}

void
#if CBDATA_DEBUG
cbdataLockDbg(const void *p, const char *file, int line)
#else
cbdataLock(const void *p)
#endif
{
    cbdata *c;
    if (p == NULL)
	return;
    c = (cbdata *) (((char *) p) - OFFSET_OF(cbdata, data));
    assert(c->y == c);
    debug(45, 3) ("cbdataLock: %p\n", p);
    assert(c != NULL);
    c->locks++;
#if CBDATA_DEBUG
    c->file = file;
    c->line = line;
#endif
}

void
#if CBDATA_DEBUG
cbdataUnlockDbg(const void *p, const char *file, int line)
#else
cbdataUnlock(const void *p)
#endif
{
    cbdata *c;
    FREE *free_func;
    if (p == NULL)
	return;
    c = (cbdata *) (((char *) p) - OFFSET_OF(cbdata, data));
    assert(c->y == c);
    debug(45, 3) ("cbdataUnlock: %p\n", p);
    assert(c != NULL);
    assert(c->locks > 0);
    c->locks--;
#if CBDATA_DEBUG
    c->file = file;
    c->line = line;
#endif
    if (c->valid || c->locks)
	return;
    cbdataCount--;
    debug(45, 3) ("cbdataUnlock: Freeing %p\n", p);
    free_func = cbdata_index[c->type].free_func;
    if (free_func)
	free_func((void *) p);
    memPoolFree(cbdata_index[c->type].pool, c);
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
