	storeAppendPrintf(sentry, "    Read Buffer Size: %d bytes\n",
	    dns->size);
	storeAppendPrintf(sentry, "    Read Offset: %d bytes\n",
	    dns->offset);
    }
    storeAppendPrintf(sentry, "\nFlags key:\n\n");
    storeAppendPrintf(sentry, "   A = ALIVE\n");
