}

void
SqStringRegistry::registerWithCacheManager(CacheManager & manager)
{
    manager.registerAction("strings",
                           "Strings in use in squid", Stat, 0, 1);
}

void
SqStringRegistry::add(SqString const *entry)
{
    entries.insert(entry, ptrcmp);
}

void
SqStringRegistry::remove(SqString const *entry)
{
    entries.remove(entry, ptrcmp);
}

SqStringRegistry SqStringRegistry::Instance_;

extern size_t memStringCount();

void
SqStringRegistry::Stat(StoreEntry *entry)
{
    storeAppendPrintf(entry, "%lu entries, %lu reported from MemPool\n", (unsigned long) Instance().entries.elements, (unsigned long) memStringCount());
    Instance().entries.head->walk(Stater, entry);
}

void
SqStringRegistry::Stater(SqString const * const & nodedata, void *state)
{
    StoreEntry *entry = (StoreEntry *) state;
    nodedata->stat(entry);
}

#endif

/*
 * Similar to strtok, but has some rudimentary knowledge
 * of quoting
