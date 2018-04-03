	);
}

static void
cacheReport(Cache * cache)
{
    fprintf(stdout, "%s: entries: %d reqs: %d bad-add: %d bad-del: %d\n", 
	cache->name, cache->count, cache->req_count,
	cache->bad_add_count, cache->bad_del_count);

    if (cache->digest) {
	int bit_count, on_count;
	cacheDigestUtil(cache->digest, &bit_count, &on_count);
	fprintf(stdout, "%s: digest entries: cnt: %d cap: %d util: %d%% size: %d b\n", 
	    cache->name, 
	    cache->digest->count, cache->digest->capacity,
	    xpercentInt(cache->digest->count, cache->digest->capacity),
	    bit_count*8
	);
	fprintf(stdout, "%s: digest bits: on: %d cap: %d util: %d%%\n", 
	    cache->name,
	    on_count, bit_count,
	    xpercentInt(on_count, bit_count)
	);
    }
}

static void
cacheFetch(Cache *cache, const RawAccessLogEntry *e)
{
    assert(e);
    cache->req_count++;
    if (e->use_icp)
	cacheQueryPeer(cache, e->key);
}
