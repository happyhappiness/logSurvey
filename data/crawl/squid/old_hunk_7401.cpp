	NRedirectors);
    storeAppendPrintf(sentry, "{use histogram:}\n");
    for (k = 0; k < NRedirectors; k++) {
	storeAppendPrintf(sentry, "{    redirector #%d: %d}\n",
	    k + 1,
	    RedirectStats.use_hist[k]);
    }
    storeAppendPrintf(sentry, close_bracket);
}