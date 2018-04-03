    return count;
}

/* Us */

static int we_icp_query_count = 0;
static int we_true_hit_count = 0;
static int we_true_miss_count = 0;
static int we_false_hit_count = 0;
static int we_false_miss_count = 0;

static void
cacheIndexQueryPeer(CacheIndex *idx, const cache_key *key)
{
    const int peer_has_it = hash_lookup(Peer->hash, key) != NULL;
    const int we_think_we_have_it = cacheDigestTest(Peer->digest, key);

    we_icp_query_count++;
    if (peer_has_it)
	if (we_think_we_have_it)
	    we_true_hit_count++;
	else
	    we_false_miss_count++;
    else
	if (we_think_we_have_it)
	    we_false_hit_count++;
	else
	    we_true_miss_count++;
}

static void
cacheIndexIcpReport(CacheIndex *idx)
{
    fprintf(stdout, "we: icp: %d\n", we_icp_query_count);
    fprintf(stdout, "we: t-hit: %d (%d%%) t-miss: %d (%d%%) t-*: %d (%d%%)\n",
	we_true_hit_count, xpercentInt(we_true_hit_count, we_icp_query_count),
	we_true_miss_count, xpercentInt(we_true_miss_count, we_icp_query_count),
	we_true_hit_count+we_true_miss_count, 
	    xpercentInt(we_true_hit_count+we_true_miss_count, we_icp_query_count)
    );
    fprintf(stdout, "we: f-hit: %d (%d%%) f-miss: %d (%d%%) f-*: %d (%d%%)\n",
	we_false_hit_count, xpercentInt(we_false_hit_count, we_icp_query_count),
	we_false_miss_count, xpercentInt(we_false_miss_count, we_icp_query_count),
	we_false_hit_count+we_false_miss_count, 
	    xpercentInt(we_false_hit_count+we_false_miss_count, we_icp_query_count)
    );
}

static int
cacheIndexAddAccessLog(CacheIndex *idx, const char *fname)
{
    FILE *file;
    int scanned_count = 0;
    assert(!idx);
    assert(fname && strlen(fname));

    file = fopen(fname, "r");
    if (!file) {
	fprintf(stderr, "cannot open %s: %s\n", fname, strerror(errno));
	return 0;
    }
    scanned_count = cacheIndexScanAccessLog(idx, fname, file);
    fclose(file);
    return scanned_count;
}

static int
cacheIndexScanAccessLog(CacheIndex *idx, const char *fname, FILE *file)
{
    static char buf[4096];
    int count = 0;
    int scanned_count = 0;
    int icp_count = 0;
    assert(!idx);
    fprintf(stderr, "%s scanning\n", fname);
    while (fgets(buf, sizeof(buf), file)) {
	char *url = strstr(buf, "://");
	char *method;
	int method_id = METHOD_NONE;
	char *hier = url ? strstr(url, " - ") : NULL;
	const cache_key *key = NULL;

	scanned_count++;
	if (!(scanned_count % 50000))
	    fprintf(stderr, "%s scanned %d K entries (%d bad)\n", 
		fname, scanned_count/1000, scanned_count-count-1);
	if (!url || !hier) {
	    fprintf(stderr, "%s:%d: strange access log entry '%s'\n", 
		fname, scanned_count, buf);
	    continue;
	}
	method = url;
	while (!isdigit(*method)) {
	    if (*method == ' ')
		*method = '\0';
	    --method;
	}
	method += 2;
	method_id = cacheIndexParseMethod(method);
	if (method_id == METHOD_NONE) {
	    fprintf(stderr, "%s:%d: invalid method %s in '%s'\n", 
		fname, scanned_count, method, buf);
	    continue;
	}
	while (*url) url--;
	url++;
	*hier = '\0';
	hier += 3;
	*strchr(hier, '/') = '\0';
	/*fprintf(stdout, "%s:%d: %s %s %s\n",
	    fname, count, method, url, hier);*/
	count++;
	/* no ICP lookup for these status codes */
	if (!strcmp(hier, "NONE") ||
	    !strcmp(hier, "DIRECT") ||
	    !strcmp(hier, "FIREWALL_IP_DIRECT") ||
	    !strcmp(hier, "LOCAL_IP_DIRECT") ||
	    !strcmp(hier, "NO_DIRECT_FAIL") ||
	    !strcmp(hier, "NO_PARENT_DIRECT") ||
	    !strcmp(hier, "SINGLE_PARENT") ||
	    !strcmp(hier, "PASSTHROUGH_PARENT") ||
	    !strcmp(hier, "SSL_PARENT_MISS") ||
	    !strcmp(hier, "DEFAULT_PARENT"))
	    continue;
	key = storeKeyPublic(url, method_id);
	/*fprintf(stdout, "%s:%d: %s %s %s %s\n",
	    fname, count, method, storeKeyText(key), url, hier);*/
	cacheIndexQueryPeer(idx, key);
	icp_count++;
    }
    fprintf(stderr, "%s: scanned %d access log entries; bad: %d\n",
	fname, scanned_count, scanned_count-count);
    fprintf(stderr, "%s: icp: %d (%d%%)\n",
	fname, icp_count, xpercentInt(icp_count, count));
    return count;
}

static int
usage(const char *prg_name)
{
