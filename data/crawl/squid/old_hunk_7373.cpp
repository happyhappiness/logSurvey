    storeAppendPrintf(sentry, close_bracket);
}

#if XMALLOC_STATISTICS
static void
info_get_mallstat(int size, number, StoreEntry * sentry)
{
    if (number > 0)
	storeAppendPrintf(sentry, "{\t%d = %d}\n", size, number);
