	cache->name, cache->count, cache->req_count,
	cache->bad_add_count, cache->bad_del_count);

    if (cache->digest) {
	int bit_count, on_count;
	cacheDigestUtil(cache->digest, &bit_count, &on_count);
	fprintf(stdout, "%s: digest entries: cnt: %d (-=%d) cap: %d util: %d%% size: %d b\n", 
	    cache->name, 
	    cache->digest->count, cache->digest->del_count,
	    cache->digest->capacity,
	    xpercentInt(cache->digest->count, cache->digest->capacity),
	    bit_count/8
	);
	fprintf(stdout, "%s: digest bits: on: %d cap: %d util: %d%%\n", 
	    cache->name,
	    on_count, bit_count,
	    xpercentInt(on_count, bit_count)
	);
    }
}

static void