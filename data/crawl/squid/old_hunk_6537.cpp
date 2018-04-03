    return METHOD_NONE;
}

/* CacheEntry */

static CacheEntry *
cacheEntryCreate(const storeSwapLogData * s)
{
    CacheEntry *e = xcalloc(1, sizeof(CacheEntry));
    assert(s);
    /* e->s = *s; */
    xmemcpy(e->key_arr, s->key, MD5_DIGEST_CHARS);
    e->key = &e->key_arr[0];
    return e;
}

static void
cacheEntryDestroy(CacheEntry * e)
{
    assert(e);
    xfree(e);
}


/* FileIterator */

static FileIterator *
fileIteratorCreate(const char *fname, FI_READER reader)
{
    FileIterator *fi = xcalloc(1, sizeof(FileIterator));
    assert(fname && reader);
    fi->fname = fname;
    fi->reader = reader;
    fileIteratorAdvance(fi);
    return fi;   
}

static void
fileIteratorDestroy(FileIterator *fi)
{
    assert(fi);
    xfree(fi->entry);
    xfree(fi);
}

static void
fileIteratorAdvance(FileIterator *fi)
{
    assert(fi);
    do {
	const int res = fi->reader(fi);
	fi->line_count++;
        if (res < 0)
	    fi->bad_line_count++;
	else
	if (res == 0)
	    fi->inner_time = -1; /* eof */
    } while (res < 0);
}




static CacheIndex *
cacheIndexCreate(const char *name)
{
    CacheIndex *idx;
    if (!name || !strlen(name))
	return NULL;

    idx = xcalloc(1, sizeof(CacheIndex));
    idx->name = name;
    idx->hash = hash_create(storeKeyHashCmp, 2e6, storeKeyHashHash);

    return idx;
}

static void
cacheIndexDestroy(CacheIndex * idx)
{
    hash_link *hashr = NULL;
    if (idx) {
	/* destroy hash list contents */
	for (hashr = hash_first(idx->hash); hashr; hashr = hash_next(idx->hash)) {
	    hash_remove_link(idx->hash, hashr);
	    cacheEntryDestroy((CacheEntry *) hashr);
	}
	/* destroy the hash table itself */
	hashFreeMemory(idx->hash);
	if (idx->digest)
	    cacheDigestDestroy(idx->digest);
	xfree(idx);
    }
}

/* makes digest based on currently hashed entries */
static void
cacheIndexInitDigest(CacheIndex * idx)
{
    hash_link *hashr = NULL;
    struct timeval t_start, t_end;
    assert(idx && !idx->digest);
    fprintf(stderr, "%s: init-ing digest with %d entries\n", idx->name, idx->count);
    idx->digest = cacheDigestCreate(2 * idx->count);	/* 50% utilization */
    gettimeofday(&t_start, NULL);
    for (hashr = hash_first(idx->hash); hashr; hashr = hash_next(idx->hash)) {
	cacheDigestAdd(idx->digest, hashr->key);
    }
    gettimeofday(&t_end, NULL);
    assert(idx->digest->count == idx->count);
    fprintf(stderr, "%s: init-ed  digest with %d entries\n",
	idx->name, idx->digest->count);
    fprintf(stderr, "%s: init took: %f sec, %f sec/M\n",
	idx->name,
	tvSubDsec(t_start, t_end),
	(double) 1e6 * tvSubDsec(t_start, t_end) / idx->count);
    /* check how long it takes to traverse the hash */
    gettimeofday(&t_start, NULL);
    for (hashr = hash_first(idx->hash); hashr; hashr = hash_next(idx->hash)) {
    }
    gettimeofday(&t_end, NULL);
    fprintf(stderr, "%s: hash scan took: %f sec, %f sec/M\n",
	idx->name,
	tvSubDsec(t_start, t_end),
	(double) 1e6 * tvSubDsec(t_start, t_end) / idx->count);
}

static int
cacheIndexAddLog(CacheIndex * idx, const char *fname)
{
    FILE *file;
    int scanned_count = 0;
