}

static void
dump_cachedir_option_maxsize(StoreEntry * e, const char *option, SwapDir const * sd)
{
    if (sd->max_objsize != -1)
	storeAppendPrintf(e, " %s=%ld", option, (long int) sd->max_objsize);
