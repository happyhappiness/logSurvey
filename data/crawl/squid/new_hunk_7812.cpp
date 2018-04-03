     StoreEntry *sentry;
     int vm_or_not;
{
    static char space[40];
    static char space2[40];
    int npend = 0;
    StoreEntry *entry = NULL;
    int N = 0;
    int obj_size;

    storeAppendPrintf(sentry, "{\n");

    for (entry = storeGetFirst();
	entry != NULL;
