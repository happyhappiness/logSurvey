        assert(fetch->mask_offset == pd->cd->mask_size);
        assert(peerDigestFetchedEnough(fetch, NULL, 0, "peerDigestSwapInMask"));
        return -1;      /* XXX! */
    } else {
        /* We always read everything, so return so */
        return size;
    }

    fatal("peerDigestSwapInMask(): shouldn't get here!\n");
    return 0; /* keep gcc happy */
}

static int
