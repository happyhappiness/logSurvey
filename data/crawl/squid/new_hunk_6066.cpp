	hier_strings[al->hier.code]);
}

void
accessLogLog(AccessLogEntry * al)
{
    LOCAL_ARRAY(char, ident_buf, USER_IDENT_SZ);

    if (LogfileStatus != LOG_ENABLE)
