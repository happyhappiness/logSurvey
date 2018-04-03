
/* local prototypes */
static void storeDigestRebuildStart(void *datanotused);
static void storeDigestRebuildResume();
static void storeDigestRebuildFinish();
static void storeDigestRebuildStep(void *datanotused);
static void storeDigestRewriteStart();
static void storeDigestRewriteResume();
static void storeDigestRewriteFinish(StoreEntry * e);
static EVH storeDigestSwapOutStep;
static void storeDigestCBlockSwapOut(StoreEntry * e);
static int storeDigestCalcCap();
static int storeDigestResize();


void
storeDigestInit()
{
#if USE_CACHE_DIGESTS
    const int cap = storeDigestCalcCap();
    store_digest = cacheDigestCreate(cap, StoreDigestBitsPerEntry);
    debug(71, 1) ("Local cache digest enabled; rebuild/rewrite every %d/%d sec\n",
	StoreDigestRebuildPeriod, StoreDigestRewritePeriod);
#else
    store_digest = NULL;
    debug(71, 1) ("Local cache digest is 'off'\n");
#endif
    memset(&sd_state, 0, sizeof(sd_state));
    cachemgrRegister("store_digest", "Store Digest",
	storeDigestReport, 0);
}

/* called when store_rebuild completes */
void
storeDigestNoteStoreReady()
{
    storeDigestRebuildStart(NULL);
    storeDigestRewriteStart(NULL);
}

void
storeDigestAdd(const StoreEntry * entry)
{
    int good_entry = 0;
