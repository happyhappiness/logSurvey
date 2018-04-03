    if (sd_state.rewrite_offset >= store_digest->mask_size)
	storeDigestRewriteFinish(e);
    else
	eventAdd("storeDigestSwapOutStep", (EVH *) storeDigestSwapOutStep, e, 0);
}

static void
storeDigestCBlockSwapOut(StoreEntry * e)
{
    /*
     * when we actually start using control block, do not forget to convert to
     * network byte order if needed
     */
    memset(&sd_state.cblock, 0, sizeof(sd_state.cblock));
    storeAppend(e, (char *) &sd_state.cblock, sizeof(sd_state.cblock));
}

void
storeDigestReport(StoreEntry * e)
{
    if (store_digest) {
	cacheDigestReport(store_digest, "store", e);
    } else {
	storeAppendPrintf(e, "store digest: disabled.\n");
    }
}
