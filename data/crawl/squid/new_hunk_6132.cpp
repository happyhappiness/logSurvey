eventDump(StoreEntry * sentry)
{
    struct ev_entry *e = tasks;
    storeAppendPrintf(sentry, "%s\t%s\t%s\n",
	"Operation",
	"Next Execution",
	"Weight");
    while (e != NULL) {
	storeAppendPrintf(sentry, "%s\t%f seconds\t%d\n",
	    e->name, e->when - current_dtime, e->weight);
	e = e->next;
    }
}