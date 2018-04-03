     int size, number;
     StoreEntry *sentry;
{
    static char line[MAX_LINELEN];
    if (number > 0)
	storeAppendPrintf(sentry, "{\t%d = %d}\n", size, number);
}
#endif


void info_get(obj, sentry)
     cacheinfo *obj;
     StoreEntry *sentry;
{
    char *tod = NULL;
    static char line[MAX_LINELEN];
    wordlist *p = NULL;
#ifdef HAVE_MALLINFO
    int t;
#endif
