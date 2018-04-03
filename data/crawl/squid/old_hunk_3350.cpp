
    user2 = accessLogFormatName(al->cache.rfc931);

    logfilePrintf(logfile, "%s %s %s [%s] \"%s %s HTTP/%d.%d\" %d %"PRId64" %s%s:%s",
                  client,
                  user2 ? user2 : dash_str,
                  user1 ? user1 : dash_str,
