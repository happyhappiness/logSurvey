}

static void
shortStringStatDump(StoreEntry *e)
{
    storeAppendPrintf(e, "<h3>Short String Stats</h3>\n<p>%s\n</p>\n",
	memPoolReport(shortStrings));
    storeAppendPrintf(e, "<br><h3>Long String Stats</h3>\n");
    storeAppendPrintf(e, "\talive: %3d (%5.1lf KB) high-water:  %3d (%5.1lf KB)\n",
	longStrAliveCount, (double)longStrAliveSize/1024.,
	longStrHighWaterCount, (double)longStrHighWaterSize/1024.);
}

void
httpHeaderStoreReport(StoreEntry *e)
{
    int i;
    http_hdr_type ht;
    assert(e);

    /* fix this (including summing for totals) for req hdrs @?@ */
    for (i = 0; i < 1 /*HttpHeaderStatCount*/; i++) {
	httpHeaderStatDump(HttpHeaderStats+i, e);
	storeAppendPrintf(e, "%s\n", "<br>");
    }
    storeAppendPrintf(e, "%s\n", "<hr size=1 noshade>");
