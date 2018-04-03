        storeAppendPrintf(e, " max-size=%"PRId64, max_objsize);
}

// some SwapDirs may maintain their indexes and be able to lookup an entry key
StoreEntry *
SwapDir::get(const cache_key *key)
{
    return NULL;
}

void
