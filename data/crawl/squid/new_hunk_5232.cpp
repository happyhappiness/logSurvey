    safe_free(user1);

    safe_free(user2);

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

void
accessLogLog(AccessLogEntry * al, ACLChecklist * checklist)
{
    customlog *log;

    if (LogfileStatus != LOG_ENABLE)
        return;

