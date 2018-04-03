    safe_free(user1);

    safe_free(user2);
}

void
accessLogLog(AccessLogEntry * al)
{
    if (LogfileStatus != LOG_ENABLE)
        return;

