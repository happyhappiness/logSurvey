eventDump(StoreEntry * sentry)
{
    struct ev_entry *e = tasks;
    storeAppendPrintf(sentry, "%s\t%s\n",
	"Operation",
	"Next Execution");
    while (e != NULL) {
	storeAppendPrintf(sentry, "%s\t%f seconds\n",
	    e->name, e->when - current_dtime);
	e = e->next;
    }
}