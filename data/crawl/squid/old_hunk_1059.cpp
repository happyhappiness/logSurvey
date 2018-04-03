
// some SwapDirs may maintain their indexes and be able to lookup an entry key
StoreEntry *
SwapDir::get(const cache_key *key)
{
    return NULL;
}

void
SwapDir::get(String const key, STOREGETCLIENT aCallback, void *aCallbackData)
{
    fatal("not implemented");
}
