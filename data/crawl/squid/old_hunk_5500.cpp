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
	p = (cbdata *)n->data;
	storeAppendPrintf(sentry, "%c%p\t%d\t%d\t%20s:%-5d\n", p->valid ? ' ' : '!', &p->data, p->type, p->locks, p->file, p->line);
    }
    storeAppendPrintf(sentry, "\n");
    storeAppendPrintf(sentry, "types\tsize\tallocated\ttotal\n");
    for (i = 1; i < cbdata_types; i++) {
	MemPool *pool = cbdata_index[i].pool;
	if (pool) {
	    int obj_size = pool->obj_size - OFFSET_OF(cbdata, data);
