}

/* returns mask utilization parameters */
double
cacheDigestUtil(const CacheDigest * cd, int *bit_cnt_p, int *on_cnt_p)
{
    const int bit_count = cd->capacity * BitsPerEntry;
    int pos = bit_count;
    int on_count = 0;
    while (pos-- > 0) {
	if (CBIT_TEST(cd->mask, pos))
	    on_count++;
    }
    if (bit_cnt_p)
	*bit_cnt_p = bit_count;
    if (on_cnt_p)
	*on_cnt_p = on_count;
    return xpercent(on_count, bit_count);
}

void
cacheDigestReport(CacheDigest *cd, const char *label, StoreEntry * e)
{
    int bit_count, on_count;
    assert(cd && e);
    cacheDigestUtil(cd, &bit_count, &on_count);
    storeAppendPrintf(e, "%s digest: size: %d bytes.\n",
	label ? label : "",
	bit_count/8
    );
    storeAppendPrintf(e, "\t entries: count: %d capacity: %d util: %d%%\n",
	cd->count,
