    }

    storeAppendPrintf(sentry, "\nNameservers:\n");
    storeAppendPrintf(sentry, "IP ADDRESS      # QUERIES # REPLIES\n");
    storeAppendPrintf(sentry, "--------------- --------- ---------\n");

    for (i = 0; i < nns; i++) {
        storeAppendPrintf(sentry, "%-15s %9d %9d\n",
                          inet_ntoa(nameservers[i].S.sin_addr),
                          nameservers[i].nqueries,
                          nameservers[i].nreplies);
    }
