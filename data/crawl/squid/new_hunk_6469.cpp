	f->icp.pkts_sent);
    storeAppendPrintf(sentry, "icp.pkts_recv = %d\n",
	f->icp.pkts_recv);
    storeAppendPrintf(sentry, "icp.queries_sent = %d\n",
	f->icp.queries_sent);
    storeAppendPrintf(sentry, "icp.replies_sent = %d\n",
	f->icp.replies_sent);
    storeAppendPrintf(sentry, "icp.queries_recv = %d\n",
	f->icp.queries_recv);
    storeAppendPrintf(sentry, "icp.replies_recv = %d\n",
	f->icp.replies_recv);
    storeAppendPrintf(sentry, "icp.query_timeouts = %d\n",
	f->icp.query_timeouts);
    storeAppendPrintf(sentry, "icp.replies_queued = %d\n",
	f->icp.replies_queued);
    storeAppendPrintf(sentry, "icp.kbytes_sent = %d\n",
	(int) f->icp.kbytes_sent.kb);
    storeAppendPrintf(sentry, "icp.kbytes_recv = %d\n",
	(int) f->icp.kbytes_recv.kb);
    storeAppendPrintf(sentry, "icp.q_kbytes_sent = %d\n",
	(int) f->icp.q_kbytes_sent.kb);
    storeAppendPrintf(sentry, "icp.r_kbytes_sent = %d\n",
	(int) f->icp.r_kbytes_sent.kb);
    storeAppendPrintf(sentry, "icp.q_kbytes_recv = %d\n",
	(int) f->icp.q_kbytes_recv.kb);
    storeAppendPrintf(sentry, "icp.r_kbytes_recv = %d\n",
	(int) f->icp.r_kbytes_recv.kb);

#if SQUID_PEER_DIGEST
    storeAppendPrintf(sentry, "icp.times_used = %d\n",
        f->icp.times_used);
    storeAppendPrintf(sentry, "cd.times_used = %d\n",
        f->cd.times_used);
    storeAppendPrintf(sentry, "cd.msgs_sent = %d\n",
	f->cd.msgs_sent);
    storeAppendPrintf(sentry, "cd.msgs_recv = %d\n",
	f->cd.msgs_recv);
    storeAppendPrintf(sentry, "cd.memory = %d\n",
	(int)f->cd.memory.kb);
    storeAppendPrintf(sentry, "cd.store_memory = %d\n",
        (int) (store_digest ? store_digest->mask_size/1024 : 0));
    storeAppendPrintf(sentry, "cd.kbytes_sent = %d\n",
	(int) f->cd.kbytes_sent.kb);
    storeAppendPrintf(sentry, "cd.kbytes_recv = %d\n",
	(int) f->cd.kbytes_recv.kb);
#endif

    storeAppendPrintf(sentry, "unlink.requests = %d\n",
