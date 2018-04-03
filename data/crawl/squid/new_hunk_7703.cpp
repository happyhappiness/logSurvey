    storeAppendPrintf(sentry, "{\tReserved number of file descriptors:  %4d}\n",
	RESERVED_FD);

    storeAppendPrintf(sentry, "{Stop List:}\n");
    if ((p = getHttpStoplist())) {
	storeAppendPrintf(sentry, "{\tHTTP:}\n");
