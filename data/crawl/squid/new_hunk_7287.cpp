statFiledescriptors(StoreEntry * sentry)
{
    int i;
    int to = 0;
    FD_ENTRY *f;

    storeAppendPrintf(sentry, open_bracket);