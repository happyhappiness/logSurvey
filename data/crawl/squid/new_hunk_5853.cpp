    storeAppendPrintf(sentry, "Pending operations: %d\n", diskdinfo->away);
}

static void
storeDiskdDirParseQ1(SwapDir * sd, const char *name, const char *value, int reconfiguring)
{
    diskdinfo_t *diskdinfo = sd->fsdata;
