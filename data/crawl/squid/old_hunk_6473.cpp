	(int) f->cd.memory.kb);
    storeAppendPrintf(sentry, "cd.store_memory = %d\n",
	(int) (store_digest ? store_digest->mask_size/1024 : 0));
#endif
    statPeerSelect(sentry);
    storeDigestReport(sentry);
}

