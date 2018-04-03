}

void
cacheDigestReport(CacheDigest * cd, const char *label, StoreEntry * e)
{
    CacheDigestStats stats;
    assert(cd && e);
    cacheDigestStats(cd, &stats);
    storeAppendPrintf(e, "%s digest: size: %d bytes\n",
	label ? label : "", stats.bit_count / 8
	);
    storeAppendPrintf(e, "\t entries: count: %d capacity: %d util: %d%%\n",
	cd->count,
	cd->capacity,
	xpercentInt(cd->count, cd->capacity)
	);
    storeAppendPrintf(e, "\t deletion attempts: %d\n",
	cd->del_count
	);
    storeAppendPrintf(e, "\t bits: on: %d capacity: %d util: %d%%\n",
	stats.bit_on_count, stats.bit_count,
	xpercentInt(stats.bit_on_count, stats.bit_count)
	);
    storeAppendPrintf(e, "\t bit-seq: count: %d avg.len: %.2f\n",
	stats.bseq_count,
	xdiv(stats.bseq_len_sum, stats.bseq_count)
	);
}

static void
cacheDigestHashKey(int bit_count, const cache_key * key)
{
    /* get four hashed values */
    memcpy(hashed_keys, key, sizeof(hashed_keys));
