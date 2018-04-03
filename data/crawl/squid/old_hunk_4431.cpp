
        for (i = 0; i < e->n_addresses; i++) {
            storeAppendPrintf(sentry, "Address[%d] : %s\n", i,
                              inet_ntoa(e->addresses[i]));
        }

        storeAppendPrintf(sentry, "Status     : %s\n",
