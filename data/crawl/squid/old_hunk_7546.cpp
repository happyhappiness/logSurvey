}

#if XMALLOC_STATISTICS
static void info_get_mallstat(size, number, sentry)
     int size, number;
     StoreEntry *sentry;
{
    if (number > 0)
	storeAppendPrintf(sentry, "{\t%d = %d}\n", size, number);
}
#endif

static char *host_port_fmt(host, port)
     char *host;
     u_short port;
{
    LOCAL_ARRAY(char, buf, 32);
    sprintf(buf, "%s.%d", host, (int) port);
    return buf;
}

static void statFiledescriptors(sentry)
     StoreEntry *sentry;
{
    int i;
    int j;
