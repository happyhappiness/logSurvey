    for (k = 0; k < N; k++)
	ipcacheStatPrint(*(list + k), sentry);
    storeAppendPrintf(sentry, close_bracket);
    xfree(list);
}

static void
