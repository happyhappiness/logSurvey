
#ifdef XMALLOC_STATISTICS
static void
info_get_mallstat(int size, int number, void *data)
{
    StoreEntry * sentry = data;
    if (number > 0)
	storeAppendPrintf(sentry, "\t%d = %d\n", size, number);
}
