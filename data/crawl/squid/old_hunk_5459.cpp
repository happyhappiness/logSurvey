}

static void
dump_cachedir_option_readonly(StoreEntry * e, const char *option, SwapDir * sd)
{
    if (sd->flags.read_only)
	storeAppendPrintf(e, " %s", option);
