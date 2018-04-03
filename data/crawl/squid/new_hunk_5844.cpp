    if (SD->flags.read_only)
	storeAppendPrintf(sentry, " READ-ONLY");
    storeAppendPrintf(sentry, "\n");
    storeAppendPrintf(sentry, "Pending operations: %d\n", diskdinfo->away);
}

