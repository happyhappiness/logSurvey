    assert(cache);
    fprintf(stderr, "%s: init-ing digest with %d entries\n", cache->name, cache->count);

    hash = cache->hash;

    delete cache->digest;
    cache->digest = new CacheDigest(cache->count + 1, 6);

    if (!cache->count)
        return;
