	f->cd.msgs_recv);
    storeAppendPrintf(sentry, "cd.memory = %d\n",
	(int)f->cd.memory.kb);
    storeAppendPrintf(sentry, "cd.store_memory = %d\n",
        (int) (store_digest ? store_digest->mask_size/1024 : 0));
    storeAppendPrintf(sentry, "cd.kbytes_sent = %d\n",
	(int) f->cd.kbytes_sent.kb);