statFiledescriptors(StoreEntry * sentry)
{
    int i;
    fde *f;

    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry, "{Active file descriptors:}\n");
