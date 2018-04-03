
    /* -------------------------------------------------- */

    storeAppendPrintf(sentry, "{Connection information for %s:}\n", appname);

    storeAppendPrintf(sentry, "{\tNumber of connections:\t%lu}\n", nconn);

    {
	float f;
