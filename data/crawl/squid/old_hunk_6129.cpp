eventDump(StoreEntry * sentry)
{
    struct ev_entry *e = tasks;
    storeAppendPrintf(sentry, "%s\t%s\t%s\t%s\n",
	"Operation",
	"Next Execution",