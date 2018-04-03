    safe_free(user_auth);

    if (Config.onoff.log_mime_hdrs) {
        char *ereq = QuoteMimeBlob(al->headers.request);
        char *erep = QuoteMimeBlob(al->headers.reply);
        logfilePrintf(logfile, " [%s] [%s]\n", ereq, erep);
        safe_free(ereq);
        safe_free(erep);
