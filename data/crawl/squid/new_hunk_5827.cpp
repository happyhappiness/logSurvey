	debug(3, 1) ("cache_dir '%s' new Q1 value '%d'\n", diskdinfo->magic1);
}

static void
storeDiskdDirDumpQ1(StoreEntry * e, const char *option, SwapDir *sd)
{
    diskdinfo_t *diskdinfo = sd->fsdata;
    storeAppendPrintf(e, " Q1=%d", diskdinfo->magic1);
}

static void
storeDiskdDirParseQ2(SwapDir * sd, const char *name, const char *value, int reconfiguring)
{
