                          tvSubDsec(q->sent_t, current_time));
    }

    if (Config.dns.packet_max > 0)
        storeAppendPrintf(sentry, "DNS jumbo-grams: %d Bytes\n", Config.dns.packet_max);
    else
        storeAppendPrintf(sentry, "DNS jumbo-grams: not working\n");

    storeAppendPrintf(sentry, "\nNameservers:\n");
    storeAppendPrintf(sentry, "IP ADDRESS                                     # QUERIES # REPLIES\n");
    storeAppendPrintf(sentry, "---------------------------------------------- --------- ---------\n");
