storeDiskdDirStats(SwapDir * SD, StoreEntry * sentry)
{
    diskdinfo_t *diskdinfo = SD->fsdata;
    commonUfsDirStats (SD, sentry);
    storeAppendPrintf(sentry, "Pending operations: %d\n", diskdinfo->away);
}

