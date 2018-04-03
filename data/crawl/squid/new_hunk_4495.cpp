SwapDir::optionMaxSizeDump(StoreEntry * e) const
{
    if (max_objsize != -1)
        storeAppendPrintf(e, " max-size=%"PRId64, max_objsize);
}

/* Swapdirs do not have an index of their own - thus they ask their parent..
