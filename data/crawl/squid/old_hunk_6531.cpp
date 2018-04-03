	);
}

static void
cacheFetch(Cache *cache, const RawAccessLogEntry *e)
{
    assert(e);
    if (e->use_icp)
	cacheQueryPeer(cache, e->key);
}
