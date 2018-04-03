void
CossSwapDir::dump(StoreEntry &entry)const
{
    storeAppendPrintf(&entry, " %lu", (max_size >> 10));
    dumpOptions(&entry);
}

