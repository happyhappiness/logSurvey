void
CossSwapDir::dump(StoreEntry &entry)const
{
    storeAppendPrintf(&entry, " %Zu", (max_size >> 10));
    dumpOptions(&entry);
}

