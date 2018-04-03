	return (time_t) 10;
    return tasks->when - squid_curtime;
}

void
eventInit(void)
{
    cachemgrRegister("events",
	"Event Queue",
	eventDump, 0);
}

static void
eventDump(StoreEntry * sentry)
{
    struct ev_entry *e = tasks;
    storeAppendPrintf(sentry, "%s\t%s\n",
	"Operation",
	"Next Execution");
    while (e != NULL) {
	storeAppendPrintf(sentry, "%s\t%d seconds\n",
	    e->name, e->when - squid_curtime);
	e = e->next;
    }
}
