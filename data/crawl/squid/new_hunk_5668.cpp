
    /* Call the right function based on the state */
    /* (Those functions will update the state if needed) */

    /* Lock our data to protect us from ourselves */
    cbdataInternalLock(fetch);

    /* Repeat this loop until we're out of data OR the state changes */
    /* (So keep going if the state has changed and we still have data */
    do {
	prevstate = fetch->state;
	switch (fetch->state) {
	case DIGEST_READ_REPLY:
	    retsize = peerDigestFetchReply(data, fetch->buf, fetch->bufofs);
	    break;
	case DIGEST_READ_HEADERS:
	    retsize = peerDigestSwapInHeaders(data, fetch->buf, fetch->bufofs);
	    break;
	case DIGEST_READ_CBLOCK:
	    retsize = peerDigestSwapInCBlock(data, fetch->buf, fetch->bufofs);
	    break;
	case DIGEST_READ_MASK:
	    retsize = peerDigestSwapInMask(data, fetch->buf, fetch->bufofs);
	    break;
	case DIGEST_READ_NONE:
	    break;
	case DIGEST_READ_DONE:
	    goto finish;
	    break;
	default:
	    fatal("Bad digest transfer mode!\n");
	}

	if (retsize < 0)
	    goto finish;
	/*
	 * The returned size indicates how much of the buffer was read -
	 * so move the remainder of the buffer to the beginning
	 * and update the bufofs / bufsize
	 */
	newsize = fetch->bufofs - retsize;
	xmemmove(fetch->buf, fetch->buf + retsize, fetch->bufofs - newsize);
	fetch->bufofs = newsize;

    } while (prevstate != fetch->state && fetch->bufofs > 0);

    /* Update the copy offset */
    fetch->offset += copysize;

    /* Schedule another copy */
    if (cbdataReferenceValid(fetch)) {
	storeClientCopy(fetch->sc, fetch->entry, fetch->offset, SM_PAGE_SIZE - fetch->bufofs,
	    fetch->buf + fetch->bufofs, peerDigestHandleReply, fetch);
    }
  finish:
    /* Unlock our data - we've finished with it for now */
    cbdataInternalUnlock(fetch);
}


