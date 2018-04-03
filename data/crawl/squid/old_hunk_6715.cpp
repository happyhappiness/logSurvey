    return httpHeaderExtFieldCreate(f->name, f->value);
}

#if 0 /* save for parts */

/*
 * returns the space requred to put a field (and terminating <CRLF>!) into a
 * buffer
 */
static size_t
httpHeaderFieldBufSize(const HttpHeaderExtField *fld)
{
    return strlen(fld->name)+2+strlen(fld->value)+2;
}

/*
 * returns true if fld.name is a "known" splitable field; 
 * always call this function to check because the detection algortihm may change
 */
static int
httpHeaderFieldIsList(const HttpHeaderExtField *fld) {
    int i;
    assert(fld);
    /* "onten" should not match "Content"! */
    for (i = 0; i < KnownSplitableFieldCount; ++i)
	if (strcasecmp(KnownSplitableFields[i], fld->name))
	    return 1;
    return 0;
}

#endif

static void
httpHeaderStoreAReport(StoreEntry *e, void (*reportPacker)(Packer *p))
{
    Packer p;
    assert(e);
    packerToStoreInit(&p, e);
    (*reportPacker)(&p);
    packerClean(&p);
}

void
httpHeaderStoreReport(StoreEntry *e)
{
    httpHeaderStoreAReport(e, &httpHeaderPackReport); 
}

void
httpHeaderStoreReqReport(StoreEntry *e)
{
    httpHeaderStoreAReport(e, &httpHeaderPackReqReport); 
}

void
httpHeaderStoreRepReport(StoreEntry *e)
{
    httpHeaderStoreAReport(e, &httpHeaderPackRepReport); 
}


static void
httpHeaderPackReport(Packer *p)
{
    assert(p);

    httpHeaderPackRepReport(p);
    httpHeaderPackReqReport(p);

    /* low level totals; reformat this? @?@ */
    packerPrintf(p,
	"hdrs totals: %uld+%uld %s lstr: +%uld-%uld<(%uld=%uld)\n",
	shortHeadersCount,
	longHeadersCount,
	memPoolReport(shortStrings),
	longStrAllocCount,
	longStrFreeCount,
	longStrHighWaterCount,
	longStrHighWaterSize);
}

static void
httpHeaderPackRepReport(Packer *p)
{
    assert(p);
#if 0 /* implement this */
    httpHeaderPackAReport(p, &ReplyHeaderStats);
    for (i = SCC_PUBLIC; i < SCC_ENUM_END; i++)
	storeAppendPrintf(entry, "Cache-Control %s: %d\n",
	    HttpServerCCStr[i],
	    ReplyHeaderStats.cc[i]);
#endif
}

static void
httpHeaderPackReqReport(Packer *p)
{
    assert(p);
#if 0 /* implement this */
    httpHeaderPackAReport(p, &RequestHeaderStats);
#endif
}

#if 0 /* implement this */
static void
httpHeaderPackAReport(Packer *p, HttpHeaderStats *stats)
{
    assert(p);
    assert(stats);
    assert(0);
    http_server_cc_t i;
    http_hdr_misc_t j;
    storeAppendPrintf(entry, "HTTP Reply Headers:\n");
    storeAppendPrintf(entry, "       Headers parsed: %d\n",
	ReplyHeaderStats.parsed);
    for (j = HDR_AGE; j < HDR_MISC_END; j++)
	storeAppendPrintf(entry, "%21.21s: %d\n",
	    HttpHdrMiscStr[j],
	    ReplyHeaderStats.misc[j]);
}
#endif

/* "short string" routines below are trying to recycle memory for short strings */
static char *
dupShortStr(const char *str)
{
