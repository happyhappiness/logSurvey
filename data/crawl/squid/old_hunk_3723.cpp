
}

void
accessLogLog(AccessLogEntry * al, ACLChecklist * checklist)
{
    customlog *log;

    if (LogfileStatus != LOG_ENABLE)
        return;

    if (al->url == NULL)
        al->url = dash_str;
