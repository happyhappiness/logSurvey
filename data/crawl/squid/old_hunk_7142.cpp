statFiledescriptors(StoreEntry * sentry)
{
    int i;
    FD_ENTRY *f;

    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry, "{Active file descriptors:}\n");
