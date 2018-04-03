	RESERVED_FD);

    storeAppendPrintf(sentry, "{Stop List:}\n");
    if ((p = Config.http_stoplist)) {
	storeAppendPrintf(sentry, "{\tHTTP:}\n");
	while (p) {
	    storeAppendPrintf(sentry, "{\t\t%s}\n", p->key);
	    p = p->next;
	}
    }
    if ((p = Config.gopher_stoplist)) {
	storeAppendPrintf(sentry, "{\tGOPHER:}\n");
	while (p) {
	    storeAppendPrintf(sentry, "{\t\t%s}\n", p->key);
	    p = p->next;
	}
    }
    if ((p = Config.ftp_stoplist)) {
	storeAppendPrintf(sentry, "{\tFTP:}\n");
	while (p) {
	    storeAppendPrintf(sentry, "{\t\t%s}\n", p->key);
