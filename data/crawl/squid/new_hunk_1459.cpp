    hash_first(hid);

    int i = 0;
    for (hash_link *walker = hash_next(hid); walker; walker = hash_next(hid)) {
        storeAppendPrintf(e, "\t item %d:\t%s\n", i, (char *)(walker->key));
        ++i;
    }
}

/* ========== PconnPool PUBLIC FUNCTIONS ============================================ */

PconnPool::PconnPool(const char *aDescr, const CbcPointer<PeerPoolMgr> &aMgr):
        table(NULL), descr(aDescr),
        mgr(aMgr),
        theCount(0)
{
    int i;
