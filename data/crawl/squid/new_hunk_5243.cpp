void
helperStats(StoreEntry * sentry, helper * hlp)
{
    dlink_node *link;
    storeAppendPrintf(sentry, "program: %s\n",
                      hlp->cmdline->key);
    storeAppendPrintf(sentry, "number running: %d of %d\n",
