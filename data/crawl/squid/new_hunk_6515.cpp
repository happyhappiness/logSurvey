}

/* returns mask utilization parameters */
static void
cacheDigestStats(const CacheDigest * cd, CacheDigestStats *stats)
{
    const int bit_count = cd->capacity * BitsPerEntry;
    int on_count = 0;
    int pos = bit_count;
    int seq_len_sum = 0;
    int seq_count = 0;
    int cur_seq_len = 0;
    int cur_seq_type = 1;
    assert(stats);
    memset(stats, 0, sizeof(*stats));
    while (pos-- > 0) {
	const int is_on = CBIT_TEST(cd->mask, pos);
	if (is_on)
	    on_count++;
	if (is_on != cur_seq_type || !pos) {
	    seq_len_sum += cur_seq_len;
	    seq_count++;
	    cur_seq_type = !cur_seq_type;
	    cur_seq_len = 0;
	}
	cur_seq_len++;
    }
    stats->bit_count = bit_count;
    stats->bit_on_count = on_count;
    stats->bseq_len_sum = seq_len_sum;
    stats->bseq_count = seq_count;
}

void
cacheDigestReport(CacheDigest *cd, const char *label, StoreEntry * e)
{
    CacheDigestStats stats;
    assert(cd && e);
    cacheDigestStats(cd, &stats);
    storeAppendPrintf(e, "%s digest: size: %d bytes\n",
	label ? label : "", stats.bit_count/8
    );
    storeAppendPrintf(e, "\t entries: count: %d capacity: %d util: %d%%\n",
	cd->count,
