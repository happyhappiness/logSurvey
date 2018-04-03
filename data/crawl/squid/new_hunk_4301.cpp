    } else {
        char *ereq = log_quote(al->headers.request);
        char *erep = log_quote(al->headers.reply);
        logfilePrintf(logfile, "%9ld.%03d %6d %s %s/%03d %"PRId64" %s %s %s %s%s/%s %s [%s] [%s]\n",
                      (long int) current_time.tv_sec,
                      (int) current_time.tv_usec / 1000,
                      al->cache.msec,
