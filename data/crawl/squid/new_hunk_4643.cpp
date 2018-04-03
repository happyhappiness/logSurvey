}

void
helperStats(StoreEntry * sentry, helper * hlp, const char *label)
{
    if (!helperStartStats(sentry, hlp, label))
        return;

    dlink_node *link;
    storeAppendPrintf(sentry, "program: %s\n",
                      hlp->cmdline->key);
