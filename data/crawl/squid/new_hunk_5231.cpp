                  al->http.content_type);

    safe_free(user);

    if (Config.onoff.log_mime_hdrs) {
        char *ereq = log_quote(al->headers.request);
        char *erep = log_quote(al->headers.reply);
        logfilePrintf(logfile, " [%s] [%s]\n", ereq, erep);
        safe_free(ereq);
        safe_free(erep);
    } else {
        logfilePrintf(logfile, "\n");
    }

}

static void
accessLogCommon(AccessLogEntry * al, Logfile * logfile)
{
    const char *client = NULL;
    char *user1 = NULL, *user2 = NULL;
