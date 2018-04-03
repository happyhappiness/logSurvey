	    p->refcount,
	    p->transferbyte);
    }

    storeAppendPrintf(sentry, close_bracket);
}

void stat_io_get(sentry)
     StoreEntry *sentry;
{
    int i;
