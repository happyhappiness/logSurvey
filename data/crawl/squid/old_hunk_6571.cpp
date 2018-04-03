	"Next Execution");
    while (e != NULL) {
	storeAppendPrintf(sentry, "%s\t%d seconds\n",
	    e->name, e->when - squid_curtime);
	e = e->next;
    }
}
