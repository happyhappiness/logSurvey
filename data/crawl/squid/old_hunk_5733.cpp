dump_cachedir_option_maxsize(StoreEntry * e, const char *option, SwapDir * sd)
{
    if (sd->max_objsize != -1)
	storeAppendPrintf(e, " %s=%d", option, sd->max_objsize);
}

void
