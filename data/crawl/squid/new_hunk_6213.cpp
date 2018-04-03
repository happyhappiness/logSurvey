    cblock.del_count = ntohl(cblock.del_count);
    cblock.mask_size = ntohl(cblock.mask_size);
    debug(72, 2) ("got digest cblock from %s; ver: %d (req: %d)\n",
	host, (int) cblock.ver.current, (int) cblock.ver.required);
    debug(72, 2) ("\t size: %d bytes, e-cnt: %d, e-util: %d%%\n",
	cblock.mask_size, cblock.count,
	xpercentInt(cblock.count, cblock.capacity));
    /* check version requirements (both ways) */
    if (cblock.ver.required > CacheDigestVer.current) {
	debug(72, 1) ("%s digest requires version %d; have: %d\n",
	    host, cblock.ver.required, CacheDigestVer.current);
	return 0;
    }
    if (cblock.ver.current < CacheDigestVer.required) {
	debug(72, 1) ("%s digest is version %d; we require: %d\n",
	    host, cblock.ver.current, CacheDigestVer.required);
	return 0;
    }
    /* check consistency */
    if (cblock.ver.required > cblock.ver.current ||
	cblock.mask_size <= 0 || cblock.capacity <= 0 ||
	cblock.bits_per_entry <= 0 || cblock.hash_func_count <= 0) {
	debug(72, 0) ("%s digest cblock is corrupted.\n", host);
	return 0;
    }
    /* check consistency further */
    if (cblock.mask_size != cacheDigestCalcMaskSize(cblock.capacity, cblock.bits_per_entry)) {
	debug(72, 0) ("%s digest cblock is corrupted (mask size mismatch: %d ? %d).\n",
	    host, cblock.mask_size, cacheDigestCalcMaskSize(cblock.capacity, cblock.bits_per_entry));
	return 0;
    }
    /* there are some things we cannot do yet */
    if (cblock.hash_func_count != CacheDigestHashFuncCount) {
	debug(72, 0) ("%s digest: unsupported #hash functions: %d ? %d.\n",
	    host, cblock.hash_func_count, CacheDigestHashFuncCount);
	return 0;
    }
    /*
     * no cblock bugs below this point
     */
    /* check size changes */
    if (pd->cd && cblock.mask_size != pd->cd->mask_size) {
	debug(72, 2) ("%s digest changed size: %d -> %d\n",
	   host, cblock.mask_size, pd->cd->mask_size);
	freed_size = pd->cd->mask_size;
	cacheDigestDestroy(pd->cd);
	pd->cd = NULL;
    }
    if (!pd->cd) {
	debug(72, 2) ("creating %s digest; size: %d (%+d) bytes\n",
	    host, cblock.mask_size, (int) (cblock.mask_size - freed_size));
	pd->cd = cacheDigestCreate(cblock.capacity, cblock.bits_per_entry);
	if (cblock.mask_size >= freed_size)
	    kb_incr(&Counter.cd.memory, cblock.mask_size - freed_size);
    }
    assert(pd->cd);
    /* these assignments leave us in an inconsistent state until we finish reading the digest */
    pd->cd->count = cblock.count;
    pd->cd->del_count = cblock.del_count;
    return 1;
}

static int
peerDigestUseful(const PeerDigest *pd)
{
    /* TODO: we should calculate the prob of a false hit instead of bit util */
    const int bit_util = cacheDigestBitUtil(pd->cd);
    if (bit_util > 65) {
	debug(72, 0) ("Warning: %s peer digest has too many bits on (%d%%).\n",
	    strBuf(pd->host), bit_util);
	return 0;
    }
    return 1;
}

static int
saneDiff(time_t diff)
{
    return abs(diff) > squid_curtime/2 ? 0 : diff;
}

void
peerDigestStatsReport(const PeerDigest *pd, StoreEntry * e)
{
#define f2s(flag) (pd->flags.flag ? "yes" : "no")
#define appendTime(tm) storeAppendPrintf(e, "%s\t %10d\t %+d\t %+d\n", \
    ""#tm, pd->times.tm, \
    saneDiff(pd->times.tm - squid_curtime), \
    saneDiff(pd->times.tm - pd->times.initialized))

    const char *host = pd ? strBuf(pd->host) : NULL;
    assert(pd);

    storeAppendPrintf(e, "\npeer digest from %s\n", host);

    cacheDigestGuessStatsReport(&pd->stats.guess, e, host);

    storeAppendPrintf(e, "\nevent\t timestamp\t secs from now\t secs from init\n");
    appendTime(initialized);
    appendTime(needed);
    appendTime(requested);
    appendTime(received);
    appendTime(next_check);

    storeAppendPrintf(e, "peer digest state:\n");
    storeAppendPrintf(e, "\tneeded: %3s, usable: %3s, requested: %3s\n",
	f2s(needed), f2s(usable), f2s(requested));
    storeAppendPrintf(e, "\n\tlast retry delay: %d secs\n",
	pd->times.retry_delay);
    storeAppendPrintf(e, "\tlast request response time: %d secs\n",
	pd->times.req_delay);
    storeAppendPrintf(e, "\tlast request result: %s\n",
	pd->req_result ? pd->req_result : "(none)");

    storeAppendPrintf(e, "\npeer digest traffic:\n");
    storeAppendPrintf(e, "\trequests sent: %d, volume: %d KB\n",
	pd->stats.sent.msgs, (int) pd->stats.sent.kbytes.kb);
    storeAppendPrintf(e, "\treplies recv:  %d, volume: %d KB\n",
	pd->stats.recv.msgs, (int) pd->stats.recv.kbytes.kb);

    storeAppendPrintf(e, "\npeer digest structure:\n");
    if (pd->cd)
	cacheDigestReport(pd->cd, host, e);
    else
	storeAppendPrintf(e, "\tno in-memory copy\n");
}

#endif
