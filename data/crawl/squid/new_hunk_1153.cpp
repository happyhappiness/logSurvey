    if (user && !*user)
        safe_free(user);

    logfilePrintf(logfile, "%9ld.%03d %6ld %s %s/%03d %" PRId64 " %s %s %s -/%s -\n",
                  (long int) current_time.tv_sec,
                  (int) current_time.tv_usec / 1000,
                  tvToMsec(al->icap.trTime),
                  client,
                  al->icap.outcome,
                  al->icap.resStatus,