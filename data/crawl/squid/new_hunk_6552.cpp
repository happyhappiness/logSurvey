	    we_true_hit_count++;
	else
	    we_false_miss_count++;
    else if (we_think_we_have_it)
	we_false_hit_count++;
    else
	we_true_miss_count++;
}

static void
cacheIndexIcpReport(CacheIndex * idx)
{
    fprintf(stdout, "we: icp: %d\n", we_icp_query_count);
    fprintf(stdout, "we: t-hit: %d (%d%%) t-miss: %d (%d%%) t-*: %d (%d%%)\n",
	we_true_hit_count, xpercentInt(we_true_hit_count, we_icp_query_count),
	we_true_miss_count, xpercentInt(we_true_miss_count, we_icp_query_count),
	we_true_hit_count + we_true_miss_count,
	xpercentInt(we_true_hit_count + we_true_miss_count, we_icp_query_count)
	);
    fprintf(stdout, "we: f-hit: %d (%d%%) f-miss: %d (%d%%) f-*: %d (%d%%)\n",
	we_false_hit_count, xpercentInt(we_false_hit_count, we_icp_query_count),
	we_false_miss_count, xpercentInt(we_false_miss_count, we_icp_query_count),
	we_false_hit_count + we_false_miss_count,
	xpercentInt(we_false_hit_count + we_false_miss_count, we_icp_query_count)
	);
}

static int
cacheIndexAddAccessLog(CacheIndex * idx, const char *fname)
{
    FILE *file;
    int scanned_count = 0;
