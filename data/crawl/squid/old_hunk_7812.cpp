     StoreEntry *sentry;
     int vm_or_not;
{
    static char tempbuf[MAX_LINELEN];
    static char space[40];
    static char space2[40];
    int npend = 0;
    StoreEntry *entry = NULL;
    int N = 0;
    int obj_size;

    storeAppend(sentry, open_bracket, (int) strlen(open_bracket));

    for (entry = storeGetFirst();
	entry != NULL;
