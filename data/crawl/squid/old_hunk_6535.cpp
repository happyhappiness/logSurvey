	);
}

#if 0

static int
cacheAddLog(Cache * idx, const char *fname)
{
    FILE *file;
    int scanned_count = 0;
    assert(idx);
    assert(fname && strlen(fname));

    file = fopen(fname, "r");
    if (!file) {
	fprintf(stderr, "cannot open %s: %s\n", fname, strerror(errno));
	return 0;
    }
    scanned_count = cacheIndexScanCleanPrefix(idx, fname, file);
    fclose(file);
    return scanned_count;
}

static void
cacheInitReport(Cache * cache)
{
    assert(idx);
    fprintf(stderr, "%s: bad swap_add:  %d\n",
	idx->name, idx->bad_add_count);
    fprintf(stderr, "%s: bad swap_del:  %d\n",
	idx->name, idx->bad_del_count);
    fprintf(stderr, "%s: scanned lines: %d\n",
	idx->name, idx->scanned_count);
}

#if 0
static int
cacheGetLogEntry(Cache * idx, storeSwapLogData * s)
{
    if (!idx->has_log_entry)
	cacheIndexStepLogEntry();
    if (idx->has_log_entry) {
	*s = idx->log_entry_buf;
	return 1;
    }
    return 0;
}

static int
cacheStepLogEntry(Cache * cache)
{
    if (fread(&idx->log_entry_buf, sizeof(idx->log_entry_buf), 1, idx->log) == 1) {
	int op = (int) idx->log_entry_buf.op;
	idx->scanned_count++;
	idx->has_log_entry = 1;
	if (op != SWAP_LOG_ADD && op != SWAP_LOG_DEL) {
	    fprintf(stderr, "%s:%d: unknown swap log action %d\n", idx->log_fname, idx->scanned_count, op);
	    exit(-3);
	}
    } else
	idx->has_log_entry = 0;
}

static int
cacheScan(Cache * idx, const char *fname, FILE * file)
{
    int count = 0;
    int del_count = 0;
    storeSwapLogData s;
    fprintf(stderr, "%s scanning\n", fname);
    while (fread(&s, sizeof(s), 1, file) == 1) {
	count++;
	idx->scanned_count++;
	if (s.op == SWAP_LOG_ADD) {
	    CacheEntry *olde = (CacheEntry *) hash_lookup(idx->hash, s.key);
	    if (olde) {
		idx->bad_add_count++;
	    } else {
		CacheEntry *e = cacheEntryCreate(&s);
		hash_join(idx->hash, (hash_link *) e);
		idx->count++;
	    }
	} else if (s.op == SWAP_LOG_DEL) {
	    CacheEntry *olde = (CacheEntry *) hash_lookup(idx->hash, s.key);
	    if (!olde)
		idx->bad_del_count++;
	    else {
		assert(idx->count);
		hash_remove_link(idx->hash, (hash_link *) olde);
		cacheEntryDestroy(olde);
		idx->count--;
	    }
	    del_count++;
	} else {
	    fprintf(stderr, "%s:%d: unknown swap log action\n", fname, count);
	    exit(-3);
	}
    }
    fprintf(stderr, "%s scanned %d entries, alloc: %d bytes\n",
	fname, count,
	(int) (count * sizeof(CacheEntry)));
    return count;
}
#endif

/* Us */

static int
cacheAddAccessLog(Cache * idx, const char *fname)
{
    FILE *file;
    int scanned_count = 0;
    assert(!idx);
    assert(fname && strlen(fname));

    file = fopen(fname, "r");
    if (!file) {
	fprintf(stderr, "cannot open %s: %s\n", fname, strerror(errno));
	return 0;
    }
    scanned_count = cacheIndexScanAccessLog(idx, fname, file);
    fclose(file);
    return scanned_count;
}

#endif

static void
cacheFetch(Cache *cache, const RawAccessLogEntry *e)
{
