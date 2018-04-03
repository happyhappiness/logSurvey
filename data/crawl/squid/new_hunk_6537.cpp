    return METHOD_NONE;
}

/* FileIterator */

static void fileIteratorAdvance(FileIterator *fi);

static FileIterator *
fileIteratorCreate(const char *fname, FI_READER reader)
{
    FileIterator *fi = xcalloc(1, sizeof(FileIterator));
    assert(fname && reader);
    fi->fname = fname;
    fi->reader = reader;
    fi->file = fopen(fname, "r");
    if (!fi->file) {
	fprintf(stderr, "cannot open %s: %s\n", fname, strerror(errno));
	return NULL;
    } else
	fprintf(stderr, "opened %s\n", fname);
    fileIteratorAdvance(fi);
    return fi;
}

static void
fileIteratorDestroy(FileIterator *fi)
{
    assert(fi);
    if (fi->file) {
	fclose(fi->file);
	fprintf(stderr, "closed %s\n", fi->fname);
    }
    xfree(fi->entry);
    xfree(fi);
}

static void
fileIteratorAdvance(FileIterator *fi)
{
    int res;
    assert(fi);
    do {
	time_t last_time = fi->inner_time;
	res = fi->reader(fi);
	fi->line_count++;
        if (res == frError)
	    fi->bad_line_count++;
	else
	if (res == frEof)
	    fi->inner_time = -1;
	else
	if (fi->inner_time < last_time) {
	    assert(last_time >= 0);
	    fi->time_warp_count++;
	    fi->inner_time = last_time;
	}
	/* report progress */
	if (!(fi->line_count % 50000))
	    fprintf(stderr, "%s scanned %d K entries (%d bad)\n",
		fi->fname, fi->line_count / 1000, fi->bad_line_count);
    } while (res < 0);
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


/* Cache */

static Cache *
cacheCreate(const char *name)
{
    Cache *c;
    assert(name && strlen(name));
    c = xcalloc(1, sizeof(Cache));
    c->name = name;
    c->hash = hash_create(storeKeyHashCmp, 2e6, storeKeyHashHash);
    return c;
}

static void
cacheDestroy(Cache * cache)
{
    CacheEntry *e = NULL;
    hash_table *hash;
    assert(cache);
    hash = cache->hash;
    /* destroy hash table contents */
    for (e = hash_first(hash); e; e = hash_next(hash)) {
	hash_remove_link(hash, (hash_link*)e);
	cacheEntryDestroy(e);
    }
    /* destroy the hash table itself */
	hashFreeMemory(hash);
    if (cache->digest)
	cacheDigestDestroy(cache->digest);
    xfree(cache);
}

/* re-digests currently hashed entries */
static void
cacheResetDigest(Cache * cache)
{
    CacheEntry *e = NULL;
    hash_table *hash;
    struct timeval t_start, t_end;

    assert(cache);
    fprintf(stderr, "%s: init-ing digest with %d entries\n", cache->name, cache->count);
    if (cache->digest)
	cacheDigestDestroy(cache->digest);
    hash = cache->hash;
    cache->digest = cacheDigestCreate(2 * cache->count + 1); /* 50% utilization */
    if (!cache->count)
	return;
    gettimeofday(&t_start, NULL);
    for (e = hash_first(hash); e; e = hash_next(hash)) {
	cacheDigestAdd(cache->digest, e->key);
    }
    gettimeofday(&t_end, NULL);
    assert(cache->digest->count == cache->count);
    fprintf(stderr, "%s: init-ed  digest with %d entries\n",
	cache->name, cache->digest->count);
    fprintf(stderr, "%s: init took: %f sec, %f sec/M\n",
	cache->name,
	tvSubDsec(t_start, t_end),
	(double) 1e6 * tvSubDsec(t_start, t_end) / cache->count);
    /* check how long it takes to traverse the hash */
    gettimeofday(&t_start, NULL);
    for (e = hash_first(hash); e; e = hash_next(hash)) {
    }
    gettimeofday(&t_end, NULL);
    fprintf(stderr, "%s: hash scan took: %f sec, %f sec/M\n",
	cache->name,
	tvSubDsec(t_start, t_end),
	(double) 1e6 * tvSubDsec(t_start, t_end) / cache->count);
}

static void
cacheQueryPeer(Cache * cache, const cache_key * key)
{
    const int peer_has_it = hash_lookup(cache->peer->hash, key) != NULL;
    const int we_think_we_have_it = cacheDigestTest(cache->digest, key);

    cache->qstats.query_count++;
    if (peer_has_it) {
	if (we_think_we_have_it)
	    cache->qstats.true_hit_count++;
	else
	    cache->qstats.false_miss_count++;
    } else {
	if (we_think_we_have_it)
	    cache->qstats.false_hit_count++;
	else
	    cache->qstats.true_miss_count++;
    }
}

static void
cacheQueryReport(Cache * cache, CacheQueryStats *stats)
{
    fprintf(stdout, "%s: icp: %d\n", cache->name, stats->query_count);
    fprintf(stdout, "%s: t-hit: %d (%d%%) t-miss: %d (%d%%) t-*: %d (%d%%)\n",
	cache->name, 
	stats->true_hit_count, xpercentInt(stats->true_hit_count, stats->query_count),
	stats->true_miss_count, xpercentInt(stats->true_miss_count, stats->query_count),
	stats->true_hit_count + stats->true_miss_count,
	xpercentInt(stats->true_hit_count + stats->true_miss_count, stats->query_count)
	);
    fprintf(stdout, "%s: f-hit: %d (%d%%) f-miss: %d (%d%%) f-*: %d (%d%%)\n",
	cache->name, 
	stats->false_hit_count, xpercentInt(stats->false_hit_count, stats->query_count),
	stats->false_miss_count, xpercentInt(stats->false_miss_count, stats->query_count),
	stats->false_hit_count + stats->false_miss_count,
	xpercentInt(stats->false_hit_count + stats->false_miss_count, stats->query_count)
	);
}

#if 0

static int
cacheAddLog(Cache * idx, const char *fname)
{
    FILE *file;
    int scanned_count = 0;
