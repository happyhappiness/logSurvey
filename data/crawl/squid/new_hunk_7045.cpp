	    describeTimestamps(entry),
	    (int) entry->refcount,
	    storePendingNClients(entry),
	    mem ? mem->inmem_hi : entry->object_len,
	    entry->url);
    }
    storeAppendPrintf(sentry, close_bracket);
