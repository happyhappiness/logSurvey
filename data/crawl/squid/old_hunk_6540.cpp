    return scanned_count;
}

static int
cacheIndexScanAccessLog(CacheIndex * idx, const char *fname, FILE * file)
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
		fname, scanned_count / 1000, scanned_count - count - 1);
	if (!url || !hier) {
	    /*fprintf(stderr, "%s:%d: strange access log entry '%s'\n", 
	     * fname, scanned_count, buf); */
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
	    /*fprintf(stderr, "%s:%d: invalid method %s in '%s'\n", 
	     * fname, scanned_count, method, buf); */
	    continue;
	}
	while (*url)
	    url--;
	url++;
	*hier = '\0';
	hier += 3;
	*strchr(hier, '/') = '\0';
	/*fprintf(stdout, "%s:%d: %s %s %s\n",
	 * fname, count, method, url, hier); */
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
	 * fname, count, method, storeKeyText(key), url, hier); */
	cacheIndexQueryPeer(idx, key);
	icp_count++;
    }
    fprintf(stderr, "%s: scanned %d access log entries; bad: %d\n",
	fname, scanned_count, scanned_count - count);
    fprintf(stderr, "%s: icp: %d (%d%%)\n",
	fname, icp_count, xpercentInt(icp_count, count));
    return count;
}

static int
