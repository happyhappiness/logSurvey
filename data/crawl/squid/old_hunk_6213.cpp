    cblock.del_count = ntohl(cblock.del_count);
    cblock.mask_size = ntohl(cblock.mask_size);
    debug(72, 2) ("got digest cblock from %s; ver: %d (req: %d)\n",
	peer->host, (int) cblock.ver.current, (int) cblock.ver.required);
    debug(72, 2) ("\t size: %d bytes, e-cnt: %d, e-util: %d%%\n",
	cblock.mask_size, cblock.count,
	xpercentInt(cblock.count, cblock.capacity));
    /* check version requirements (both ways) */
    if (cblock.ver.required > CacheDigestVer.current) {
	debug(72, 1) ("%s digest requires version %d; have: %d\n",
	    peer->host, cblock.ver.required, CacheDigestVer.current);
	return 0;
    }
    if (cblock.ver.current < CacheDigestVer.required) {
	debug(72, 1) ("%s digest is version %d; we require: %d\n",
	    peer->host, cblock.ver.current, CacheDigestVer.required);
	return 0;
    }
    /* check consistency */
    if (cblock.ver.required > cblock.ver.current ||
	cblock.mask_size <= 0 || cblock.capacity <= 0 ||
	cblock.bits_per_entry <= 0 || cblock.hash_func_count <= 0) {
	debug(72, 0) ("%s digest cblock is corrupted.\n", peer->host);
	return 0;
    }
    /* check consistency further */
    if (cblock.mask_size != cacheDigestCalcMaskSize(cblock.capacity, cblock.bits_per_entry)) {
	debug(72, 0) ("%s digest cblock is corrupted (mask size mismatch: %d ? %d).\n",
	    peer->host, cblock.mask_size, cacheDigestCalcMaskSize(cblock.capacity, cblock.bits_per_entry));
	return 0;
    }
    /* there are some things we cannot do yet */
    if (cblock.hash_func_count != CacheDigestHashFuncCount) {
	debug(72, 0) ("%s digest: unsupported #hash functions: %d ? %d.\n",
	    peer->host, cblock.hash_func_count, CacheDigestHashFuncCount);
	return 0;
    }
    /*
     * no cblock bugs below this point
     */
    /* check size changes */
    if (peer->digest.cd && cblock.mask_size != peer->digest.cd->mask_size) {
	debug(72, 2) ("%s digest changed size: %d -> %d\n",
	    peer->host, cblock.mask_size, peer->digest.cd->mask_size);
	freed_size = peer->digest.cd->mask_size;
	cacheDigestDestroy(peer->digest.cd);
	peer->digest.cd = NULL;
    }
    if (!peer->digest.cd) {
	debug(72, 2) ("creating %s digest; size: %d (%+d) bytes\n",
	    peer->host, cblock.mask_size, (int) (cblock.mask_size - freed_size));
	peer->digest.cd = cacheDigestCreate(cblock.capacity, cblock.bits_per_entry);
	if (cblock.mask_size >= freed_size)
	    kb_incr(&Counter.cd.memory, cblock.mask_size - freed_size);
    }
    assert(peer->digest.cd);
    /* these assignments leave us in an inconsistent state until we finish reading the digest */
    peer->digest.cd->count = cblock.count;
    peer->digest.cd->del_count = cblock.del_count;
    return 1;
}

static int
peerDigestUseful(const peer * peer)
{
    /* TODO: we should calculate the prob of a false hit instead of bit util */
    const int bit_util = cacheDigestBitUtil(peer->digest.cd);
    if (bit_util > 75) {
	debug(72, 0) ("Warning: %s peer digest has too many bits on (%d%%).\n",
	    peer->host, bit_util);
	return 0;
    }
    return 1;
}

#endif
