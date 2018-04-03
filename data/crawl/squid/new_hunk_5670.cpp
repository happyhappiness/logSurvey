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
	    return 0;		/* We need more data */
	}
    }
    fatal("peerDigestSwapInCBlock(): shouldn't get here!\n");
}
