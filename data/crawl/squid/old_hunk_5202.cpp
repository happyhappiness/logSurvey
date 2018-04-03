void
CossSwapDir::dump(StoreEntry &entry)const
{
    storeAppendPrintf(&entry, " %d",
                      max_size >> 20);
    dump_cachedir_options(&entry, NULL, this);
}

#if OLD_UNUSED_CODE
