    else
        method = al->http.method.image();

    logfilePrintf(logfile, "%9ld.%03d %6ld %s %s%s/%03d %" PRId64 " " SQUIDSBUFPH " %s %s %s%s/%s %s%s",
                  (long int) current_time.tv_sec,
                  (int) current_time.tv_usec / 1000,
                  tvToMsec(al->cache.trTime),
                  clientip,
                  LogTags_str[al->cache.code],
                  al->http.statusSfx(),
