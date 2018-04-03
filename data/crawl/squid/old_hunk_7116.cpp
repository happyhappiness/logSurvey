    }
    storeAppendPrintf(e, "\r\n");
    storeTimestampsSet(e);
    assert(e->flag & KEY_PRIVATE);
    storeSetPublicKey(e);
}

