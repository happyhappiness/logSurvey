    return httpHeaderExtFieldCreate(f->name, f->value);
}

/*
 * Reports
 */

static void
httpHeaderFieldStatDumper(StoreEntry * sentry, int idx, double val, double size, int count)
{
    const int id = (int) val;
    const int valid_id = id >= 0 && id < HDR_ENUM_END;
    const char *name = valid_id ? Headers[id].name : "INVALID";
    if (count || valid_id)
	storeAppendPrintf(sentry, "%2d\t %-20s\t %5d\t %6.2f\n",
	    id, name, count, xdiv(count, HeaderParsedCount));
}

static void
httpHeaderCCStatDumper(StoreEntry * sentry, int idx, double val, double size, int count)
{
    const int id = (int) val;
    const int valid_id = id >= 0 && id < SCC_ENUM_END;
    const char *name = valid_id ? SccAttrs[id].name : "INVALID";
    if (count || valid_id)
	storeAppendPrintf(sentry, "%2d\t %-20s\t %5d\t %6.2f\n",
	    id, name, count, xdiv(count, CcPasredCount));
}


static void
httpHeaderFldsPerHdrDumper(StoreEntry * sentry, int idx, double val, double size, int count)
{
    if (count)
	storeAppendPrintf(sentry, "%2d\t %5d\t %5d\t %6.2f\n",
	    idx, ((int)(val+size)), count, xpercent(count, HeaderEntryParsedCount));
}


static void
httpHeaderStatDump(const HttpHeaderStat *hs, StoreEntry *e)
{
    assert(hs && e);

    storeAppendPrintf(e, "\n<h3>Header Stats: %s</h3>\n", hs->label);
    storeAppendPrintf(e, "\t<h3>Field type distribution</h3>\n");
    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\n",
	"id", "name", "count", "#/header");
    statHistDump(&hs->fieldTypeDistr, e, httpHeaderFieldStatDumper);
    storeAppendPrintf(e, "\t<h3>Cache-control directives distribution</h3>\n");
    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\n",
	"id", "name", "count", "#/cc_field");
    statHistDump(&hs->ccTypeDistr, e, httpHeaderCCStatDumper);
    storeAppendPrintf(e, "\t<h3>Number of fields per header distribution (init size: %d)</h3>\n",
	INIT_FIELDS_PER_HEADER);
    storeAppendPrintf(e, "%2s\t %-5s\t %5s\t %6s\n",
	"id", "#flds", "count", "%total");
    statHistDump(&hs->hdrUCountDistr, e, httpHeaderFldsPerHdrDumper);
}

static void
shortStringStatDump(StoreEntry *e)
{
    storeAppendPrintf(e, "<h3>Short String Stats</h3>\n<p>%s\n</p>\n",
	memPoolReport(shortStrings));
    storeAppendPrintf(e, "<br><h3>Long String Stats</h3>\n");
    storeAppendPrintf(e, "\talive: %3d (%5.1f KB) high-water:  %3d (%5.1f KB)\n",
	longStrAliveCount, longStrAliveSize/1024.,
	longStrHighWaterCount, longStrHighWaterSize/1024.);
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
    /* field stats */
    storeAppendPrintf(e, "<h3>Http Fields Stats (replies and requests)</h3>\n");
    storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\t %6s\n",
	"id", "name", "#alive", "%err", "%repeat");
    for (ht = 0; ht < HDR_ENUM_END; ht++) {
	field_attrs_t *f = Headers+ht;
	storeAppendPrintf(e, "%2d\t %-20s\t %5d\t %6.3f\t %6.3f\n",
	    f->id, f->name, f->stat.aliveCount,
	    xpercent(f->stat.errCount, f->stat.parsCount), 
	    xpercent(f->stat.repCount, f->stat.parsCount));
    }
    storeAppendPrintf(e, "%s\n", "<hr size=1 noshade>");
    /* short strings */
    shortStringStatDump(e);
}


/*
 * "short string" routines below are trying to recycle memory for short strings
 */

static char *
dupShortStr(const char *str)
{
