	    debug(72, 1) ("peerDigestSwapInHeaders: %s status %d got cached!\n",
		strBuf(fetch->pd->host), fetch->entry->mem_obj->reply->sline.status);
	    peerDigestFetchAbort(fetch, buf, "internal status error");
	    return -1;
	}
	fetch->state = DIGEST_READ_CBLOCK;
	return hdr_size; /* Say how much data we read */
    } else {
	/* need more data, do we have space? */
	if (size >= SM_PAGE_SIZE) {
	    peerDigestFetchAbort(fetch, buf, "stored header too big");
	    return -1;
	} else {
	    return 0; /* We need to read more to parse .. */
        }
    }
    fatal("peerDigestSwapInHeaders() - shouldn't get here!\n");
}

static int
peerDigestSwapInCBlock(void *data, char *buf, ssize_t size)
{
    DigestFetchState *fetch = data;

    assert(fetch->state == DIGEST_READ_CBLOCK);
    if (peerDigestFetchedEnough(fetch, buf, size, "peerDigestSwapInCBlock"))
	return -1;

    if (size >= StoreDigestCBlockSize) {
	PeerDigest *pd = fetch->pd;
	HttpReply *rep = fetch->entry->mem_obj->reply;

	assert(pd && rep);
	if (peerDigestSetCBlock(pd, buf)) {
	    /* XXX: soon we will have variable header size */
	    /* switch to CD buffer and fetch digest guts */
	    buf = NULL;
	    assert(pd->cd->mask);
            fetch->state = DIGEST_READ_MASK;
            return StoreDigestCBlockSize;
	} else {
	    peerDigestFetchAbort(fetch, buf, "invalid digest cblock");
            return -1;
	}
    } else {
	/* need more data, do we have space? */
	if (size >= SM_PAGE_SIZE) {
	    peerDigestFetchAbort(fetch, buf, "digest cblock too big");
            return -1;
        } else {
            return 0; /* We need more data */
        }
    }
    fatal("peerDigestSwapInCBlock(): shouldn't get here!\n");
}

static int
peerDigestSwapInMask(void *data, char *buf, ssize_t size)
{
    DigestFetchState *fetch = data;
    PeerDigest *pd;

    pd = fetch->pd;
    assert(pd->cd && pd->cd->mask);

    /*
     * NOTENOTENOTENOTENOTE: buf doesn't point to pd->cd->mask anymore!
     * we need to do the copy ourselves!
     */
    xmemcpy(pd->cd->mask + fetch->mask_offset, buf, size);

    /* NOTE! buf points to the middle of pd->cd->mask! */
    if (peerDigestFetchedEnough(fetch, NULL, size, "peerDigestSwapInMask"))
	return -1;

    fetch->mask_offset += size;
    if (fetch->mask_offset >= pd->cd->mask_size) {
	debug(72, 2) ("peerDigestSwapInMask: Done! Got %d, expected %d\n",
	    fetch->mask_offset, pd->cd->mask_size);
	assert(fetch->mask_offset == pd->cd->mask_size);
	assert(peerDigestFetchedEnough(fetch, NULL, 0, "peerDigestSwapInMask"));
        return -1; /* XXX! */
    } else {
        /* We always read everything, so return so */
        return size;
    }
    fatal("peerDigestSwapInMask(): shouldn't get here!\n");
}

static int
