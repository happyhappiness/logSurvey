{
    if (store_digest) {
	cacheDigestReport(store_digest, "store", e);
    } else {
	storeAppendPrintf(e, "store digest: disabled.\n");
    }