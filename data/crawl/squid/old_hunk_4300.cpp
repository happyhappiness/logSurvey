        safe_free(user);

    if (!Config.onoff.log_mime_hdrs) {
        logfilePrintf(logfile, "%9ld.%03d %6d %s %s/%03d %"PRId64" %s %s %s %s%s/%s %s",
                      (long int) current_time.tv_sec,
                      (int) current_time.tv_usec / 1000,
                      al->cache.msec,
