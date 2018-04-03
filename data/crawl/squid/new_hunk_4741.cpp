    if (user && !*user)
        safe_free(user);

    if (!Config.onoff.log_mime_hdrs) {
        logfilePrintf(logfile, "%9ld.%03d %6d %s %s/%03d %ld %s %s %s %s%s/%s %s",
                      (long int) current_time.tv_sec,
                      (int) current_time.tv_usec / 1000,
                      al->cache.msec,
                      client,
                      log_tags[al->cache.code],
                      al->http.code,
                      (long int) al->cache.size,
                      al->_private.method_str,
                      al->url,
                      user ? user : dash_str,
                      al->hier.ping.timedout ? "TIMEOUT_" : "",
                      hier_strings[al->hier.code],
                      al->hier.host,
                      al->http.content_type);
    } else {
        char *ereq = log_quote(al->headers.request);
        char *erep = log_quote(al->headers.reply);
        logfilePrintf(logfile, "%9ld.%03d %6d %s %s/%03d %ld %s %s %s %s%s/%s %s [%s] [%s]",
                      (long int) current_time.tv_sec,
                      (int) current_time.tv_usec / 1000,
                      al->cache.msec,
                      client,
                      log_tags[al->cache.code],
                      al->http.code,
                      (long int) al->cache.size,
                      al->_private.method_str,
                      al->url,
                      user ? user : dash_str,
                      al->hier.ping.timedout ? "TIMEOUT_" : "",
                      hier_strings[al->hier.code],
                      al->hier.host,
                      al->http.content_type,
                      ereq,
                      erep);
        safe_free(ereq);
        safe_free(erep);
    }

    safe_free(user);
}

static void