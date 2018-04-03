statFiledescriptors(StoreEntry * sentry)
{
    int i;
    int lft;
    int to;
    FD_ENTRY *f;

    storeAppendPrintf(sentry, open_bracket);
