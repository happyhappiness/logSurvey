eventDump(StoreEntry * sentry)
{
    struct ev_entry *e = tasks;
    storeAppendPrintf(sentry, "%s\t%s\t%s\t%s\n",
	"Operation",
	"Next Execution",
	"Weight",
	"Callback Valid?");
    while (e != NULL) {
	storeAppendPrintf(sentry, "%s\t%f seconds\t%d\t%s\n",
	    e->name, e->when - current_dtime, e->weight,
	    e->arg ? cbdataValid(e->arg) ? "yes" : "no" : "N/A");
	e = e->next;
    }
}