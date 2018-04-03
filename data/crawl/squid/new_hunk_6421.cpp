	"Operation",
	"Next Execution");
    while (e != NULL) {
	storeAppendPrintf(sentry, "%s\t%f seconds\n",
	    e->name, e->when - current_dtime);
	e = e->next;
    }
}
