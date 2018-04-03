    }
}

#if CBDATA_DEBUG
void
_cbdata::dump(StoreEntry *sentry) const
{
    storeAppendPrintf(sentry, "%c%p\t%d\t%d\t%20s:%-5d\n", valid ? ' ' :
		      '!', &data, type, locks, file, line);
}

struct CBDataDumper : public unary_function<_cbdata, void>
{
    CBDataDumper(StoreEntry *anEntry):where(anEntry){}
    void operator()(_cbdata const &x) {
	x.dump(where);
    }
    StoreEntry *where;
};
#endif

static void
cbdataDump(StoreEntry * sentry)
{
    storeAppendPrintf(sentry, "%d cbdata entries\n", cbdataCount);
#if CBDATA_DEBUG
    storeAppendPrintf(sentry, "Pointer\tType\tLocks\tAllocated by\n");
    CBDataDumper dumper(sentry);
    for_each (cbdataEntries, dumper);
    storeAppendPrintf(sentry, "\n");
    storeAppendPrintf(sentry, "types\tsize\tallocated\ttotal\n");
    for (int i = 1; i < cbdata_types; i++) {
	MemPool *pool = cbdata_index[i].pool;
	if (pool) {
	    int obj_size = pool->obj_size - OFFSET_OF(cbdata, data);
