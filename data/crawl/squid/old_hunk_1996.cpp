}

static int
check_null_access_log(customlog *customlog_definitions)
{
    return customlog_definitions == NULL;
}

static void
dump_access_log(StoreEntry * entry, const char *name, customlog * logs)
{
    customlog *log;

    for (log = logs; log; log = log->next) {
        storeAppendPrintf(entry, "%s ", name);
