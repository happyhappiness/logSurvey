                          tvSubDsec(q->sent_t, current_time));
    }

    storeAppendPrintf(sentry, "\nNameservers:\n");
    storeAppendPrintf(sentry, "IP ADDRESS                                     # QUERIES # REPLIES\n");
    storeAppendPrintf(sentry, "---------------------------------------------- --------- ---------\n");
