	    debug(72, 1) ("peerDigestSwapInHeaders: %s status %d got cached!\n",
		strBuf(fetch->pd->host), fetch->entry->mem_obj->reply->sline.status);
	    peerDigestFetchAbort(fetch, buf, "internal status error");
	    return;
	}
	fetch->offset += hdr_size;
	storeClientCopy(fetch->sc, fetch->entry, size, fetch->offset,
	    SM_PAGE_SIZE, buf,
	    peerDigestSwapInCBlock, fetch);
    } else {
	/* need more data, do we have space? */
	if (size >= SM_PAGE_SIZE)
	    peerDigestFetchAbort(fetch, buf, "stored header too big");
	else
	    storeClientCopy(fetch->sc, fetch->entry, size, 0, SM_PAGE_SIZE, buf,
		peerDigestSwapInHeaders, fetch);
    }
}

static void
peerDigestSwapInCBlock(void *data, char *buf, ssize_t size)
{
    DigestFetchState *fetch = data;

    if (peerDigestFetchedEnough(fetch, buf, size, "peerDigestSwapInCBlock"))
	return;

    if (size >= StoreDigestCBlockSize) {
	PeerDigest *pd = fetch->pd;
	HttpReply *rep = fetch->entry->mem_obj->reply;
	const int seen = fetch->offset + size;

	assert(pd && rep);
	if (peerDigestSetCBlock(pd, buf)) {
	    /* XXX: soon we will have variable header size */
	    fetch->offset += StoreDigestCBlockSize;
	    /* switch to CD buffer and fetch digest guts */
	    memFree(buf, MEM_4K_BUF);
	    buf = NULL;
	    assert(pd->cd->mask);
	    storeClientCopy(fetch->sc, fetch->entry,
		seen,
		fetch->offset,
		pd->cd->mask_size,
		pd->cd->mask,
		peerDigestSwapInMask, fetch);
	} else {
	    peerDigestFetchAbort(fetch, buf, "invalid digest cblock");
	}
    } else {
	/* need more data, do we have space? */
	if (size >= SM_PAGE_SIZE)
	    peerDigestFetchAbort(fetch, buf, "digest cblock too big");
	else
	    storeClientCopy(fetch->sc, fetch->entry, size, 0, SM_PAGE_SIZE, buf,
		peerDigestSwapInCBlock, fetch);
    }
}

static void
peerDigestSwapInMask(void *data, char *buf, ssize_t size)
{
    DigestFetchState *fetch = data;
    PeerDigest *pd;

    /* NOTE! buf points to the middle of pd->cd->mask! */
    if (peerDigestFetchedEnough(fetch, NULL, size, "peerDigestSwapInMask"))
	return;

    pd = fetch->pd;
    assert(pd->cd && pd->cd->mask);

    fetch->offset += size;
    fetch->mask_offset += size;
    if (fetch->mask_offset >= pd->cd->mask_size) {
	debug(72, 2) ("peerDigestSwapInMask: Done! Got %d, expected %d\n",
	    fetch->mask_offset, pd->cd->mask_size);
	assert(fetch->mask_offset == pd->cd->mask_size);
	assert(peerDigestFetchedEnough(fetch, NULL, 0, "peerDigestSwapInMask"));
    } else {
	const size_t buf_sz = pd->cd->mask_size - fetch->mask_offset;
	assert(buf_sz > 0);
	storeClientCopy(fetch->sc, fetch->entry,
	    fetch->offset,
	    fetch->offset,
	    buf_sz,
	    pd->cd->mask + fetch->mask_offset,
	    peerDigestSwapInMask, fetch);
    }
}

static int
