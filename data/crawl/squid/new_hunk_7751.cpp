	    else
		storeAppendPrintf(sentry, "!%s ", d->domain);
	}
	storeAppendPrintf(sentry, close_bracket);	/* } */
    }
    storeAppendPrintf(sentry, close_bracket);
}

#if XMALLOC_STATISTICS
void info_get_mallstat(size, number, sentry)
     int size, number;
     StoreEntry *sentry;
{
    static char line[MAX_LINELEN];
    if (number > 0)
	storeAppendPrintf(sentry, "{\t%d = %d}\n", size, number);
}
#endif


void info_get(obj, sentry)
