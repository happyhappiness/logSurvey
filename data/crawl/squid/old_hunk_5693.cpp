    fwdStart(-1, e, req);
    cbdataLock(fetch);
    cbdataLock(fetch->pd);
    storeClientCopy(fetch->sc, e, 0, 0, 4096, memAllocate(MEM_4K_BUF),
	peerDigestFetchReply, fetch);
}

/* wait for full http headers to be received then parse them */
static void
peerDigestFetchReply(void *data, char *buf, ssize_t size)
{
    DigestFetchState *fetch = data;
