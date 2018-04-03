	storeAppendPrintf(sentry, "Flags:");
	if (SD->flags.selected)
	    storeAppendPrintf(sentry, " SELECTED");
	storeAppendPrintf(sentry, "\n");
    }
}
