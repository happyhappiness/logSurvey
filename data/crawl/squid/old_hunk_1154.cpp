    else
        method = al->http.method.image();

    logfilePrintf(logfile, "%9ld.%03d %6d %s %s%s/%03d %" PRId64 " " SQUIDSBUFPH " %s %s %s%s/%s %s%s",
                  (long int) current_time.tv_sec,
                  (int) current_time.tv_usec / 1000,
                  al->cache.msec,
                  clientip,
                  LogTags_str[al->cache.code],
                  al->http.statusSfx(),
