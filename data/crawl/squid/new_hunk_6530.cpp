static void
cacheQueryReport(Cache * cache, CacheQueryStats *stats)
{
    fprintf(stdout, "%s: peer queries: %d (%d%%)\n", 
	cache->name, 
	stats->query_count, xpercentInt(stats->query_count, cache->req_count)
	);
    fprintf(stdout, "%s: t-hit: %d (%d%%) t-miss: %d (%d%%) t-*: %d (%d%%)\n",
	cache->name, 
	stats->true_hit_count, xpercentInt(stats->true_hit_count, stats->query_count),
