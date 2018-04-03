storeDigestReport(StoreEntry * e)
{
#if USE_CACHE_DIGESTS
    if (!Config.onoff.digest_generation) {
	return;
    }
    if (store_digest) {
	cacheDigestReport(store_digest, "store", e);
	storeAppendPrintf(e, "\t added: %d rejected: %d ( %.2f %%) del-ed: %d\n",
