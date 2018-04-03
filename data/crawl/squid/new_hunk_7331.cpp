    char *s = NULL;
    int lft;
    int to;
    FD_ENTRY *f;

    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry, "{Active file descriptors:}\n");
