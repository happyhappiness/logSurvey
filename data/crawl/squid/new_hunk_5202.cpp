void
CossSwapDir::dump(StoreEntry &entry)const
{
    storeAppendPrintf(&entry, " %d", max_size >> 20);
    dumpOptions(&entry);
}

#if OLD_UNUSED_CODE
