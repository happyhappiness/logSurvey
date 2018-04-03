    return scanned_count;
}

#endif

static void
cacheFetch(Cache *cache, const RawAccessLogEntry *e)
{
    assert(e);
    if (e->use_icp)
	cacheQueryPeer(cache, e->key);
}

static fr_result
swapStateReader(FileIterator * fi)
{
    storeSwapLogData *entry;
    if (!fi->entry)
	fi->entry = xcalloc(1, sizeof(storeSwapLogData));
    entry = fi->entry;
    if (fread(entry, sizeof(*entry), 1, fi->file) != 1)
	return frEof;
    fi->inner_time = entry->lastref;
    if (entry->op != SWAP_LOG_ADD && entry->op != SWAP_LOG_DEL) {
	fprintf(stderr, "%s:%d: unknown swap log action\n", fi->fname, fi->line_count);
	exit(-3);
    }
    return frOk;
}

static fr_result
accessLogReader(FileIterator * fi)
{
    static char buf[4096];
    RawAccessLogEntry *entry;
    char *url;
    char *method;
    int method_id = METHOD_NONE;
    char *hier = NULL;

    assert(fi);
    if (!fi->entry)
	fi->entry = xcalloc(1, sizeof(RawAccessLogEntry));
    else
	memset(fi->entry, 0, sizeof(RawAccessLogEntry));
    entry = fi->entry;
    if (!fgets(buf, sizeof(buf), fi->file))
	return frEof; /* eof */
    entry->timestamp = fi->inner_time = (time_t)atoi(buf);
    url = strstr(buf, "://");
    hier = url ? strstr(url, " - ") : NULL;

    if (!url || !hier) {
	/*fprintf(stderr, "%s:%d: strange access log entry '%s'\n", 
	 * fname, scanned_count, buf); */
	return frError;
    }
    method = url;
    while (!isdigit(*method)) {
	if (*method == ' ')
	    *method = '\0';
	--method;
    }
    method += 2;
    method_id = methodStrToId(method);
    if (method_id == METHOD_NONE) {
	/*fprintf(stderr, "%s:%d: invalid method %s in '%s'\n", 
	 * fname, scanned_count, method, buf); */
	return frError;
    }
    while (*url) url--;
    url++;
    *hier = '\0';
    hier += 3;
    *strchr(hier, '/') = '\0';
    /*fprintf(stdout, "%s:%d: %s %s %s\n",
     * fname, count, method, url, hier); */
    entry->use_icp =  /* no ICP lookup for these status codes */
	strcmp(hier, "NONE") &&
	strcmp(hier, "DIRECT") &&
	strcmp(hier, "FIREWALL_IP_DIRECT") &&
	strcmp(hier, "LOCAL_IP_DIRECT") &&
	strcmp(hier, "NO_DIRECT_FAIL") &&
	strcmp(hier, "NO_PARENT_DIRECT") &&
	strcmp(hier, "SINGLE_PARENT") &&
	strcmp(hier, "PASSTHROUGH_PARENT") &&
	strcmp(hier, "SSL_PARENT_MISS") &&
	strcmp(hier, "DEFAULT_PARENT");
    if (!entry->use_icp)
	return frMore;
    memcpy(entry->key, storeKeyPublic(url, method_id), sizeof(entry->key));
    /*fprintf(stdout, "%s:%d: %s %s %s %s\n",
	fname, count, method, storeKeyText(entry->key), url, hier); */
    return frOk;
}


static void
cachePurge(Cache *cache, storeSwapLogData *s)
{
    CacheEntry *olde = (CacheEntry *) hash_lookup(cache->hash, s->key);
    if (!olde) {
	cache->bad_del_count++;
    } else {
	assert(cache->count);
	hash_remove_link(cache->hash, (hash_link *) olde);
	cacheEntryDestroy(olde);
	cache->count--;
    }
}

static void
cacheStore(Cache *cache, storeSwapLogData *s, int update_digest)
{
    CacheEntry *olde = (CacheEntry *) hash_lookup(cache->hash, s->key);
    if (olde) {
	cache->bad_add_count++;
    } else {
	CacheEntry *e = cacheEntryCreate(s);
	hash_join(cache->hash, (hash_link *) e);
	cache->count++;
	if (update_digest)
	    cacheDigestAdd(cache->digest, e->key);
    }
}

static void
cacheUpdateStore(Cache *cache, storeSwapLogData *s, int update_digest)
{
    switch (s->op) {
	case SWAP_LOG_ADD:
	    cacheStore(cache, s, update_digest);
	    break;
	case SWAP_LOG_DEL:
	    cachePurge(cache, s);
	    break;
	default:
	    assert(0);
    }
}

static int
