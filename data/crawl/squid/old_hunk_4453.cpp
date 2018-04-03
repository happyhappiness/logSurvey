    CacheManagerAction *a;

    for (a = ActionTable; a != NULL; a = a->next) {
        storeAppendPrintf(sentry, " %-22s\t%s\t%s\n",
                          a->action, a->desc, cachemgrActionProtection(a));
    }
}
