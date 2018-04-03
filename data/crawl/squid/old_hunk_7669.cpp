	RESERVED_FD);

    storeAppendPrintf(sentry, "{Stop List:}\n");
    if ((p = getHttpStoplist())) {
	storeAppendPrintf(sentry, "{\tHTTP:}\n");
	while (p) {
	    storeAppendPrintf(sentry, "{\t\t%s}\n", p->key);
	    p = p->next;
	}
    }
    if ((p = getGopherStoplist())) {
	storeAppendPrintf(sentry, "{\tGOPHER:}\n");
	while (p) {
	    storeAppendPrintf(sentry, "{\t\t%s}\n", p->key);
	    p = p->next;
	}
    }
    if ((p = getFtpStoplist())) {
	storeAppendPrintf(sentry, "{\tFTP:}\n");
	while (p) {
	    storeAppendPrintf(sentry, "{\t\t%s}\n", p->key);
