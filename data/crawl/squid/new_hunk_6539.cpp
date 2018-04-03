}
#endif

/* Us */

static int
cacheAddAccessLog(Cache * idx, const char *fname)
{
    FILE *file;
    int scanned_count = 0;
