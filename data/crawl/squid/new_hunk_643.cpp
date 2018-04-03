            peerDigestFetchAbort(fetch, buf, "invalid digest cblock");
            return -1;
        }
    }

    /* need more data, do we have space? */
    if (size >= SM_PAGE_SIZE) {
        peerDigestFetchAbort(fetch, buf, "digest cblock too big");
        return -1;
    }

    return 0;       /* We need more data */
}

int
