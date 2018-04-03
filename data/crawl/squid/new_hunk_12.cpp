                          n->hops);

        for (x = n->hosts; x; x = x->next)
            storeAppendPrintf(sentry, " %s", hashKeyStr(x));

        storeAppendPrintf(sentry, "\n");

