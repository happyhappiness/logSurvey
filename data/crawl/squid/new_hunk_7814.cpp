	    (int) entry->refcount,
	    mem_describe(entry),
	    stat_describe(entry));
    }
    storeAppendPrintf(sentry, "}\n");
}


