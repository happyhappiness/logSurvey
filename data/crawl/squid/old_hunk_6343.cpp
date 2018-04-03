    ct = f->cputime - l->cputime;

    storeAppendPrintf(sentry, "sample_start_time = %d.%d (%s)\n",
	(int) f->timestamp.tv_sec,
	(int) f->timestamp.tv_usec,
	mkrfc1123(f->timestamp.tv_sec));
    storeAppendPrintf(sentry, "sample_end_time = %d.%d (%s)\n",
	(int) l->timestamp.tv_sec,
	(int) l->timestamp.tv_usec,
	mkrfc1123(l->timestamp.tv_sec));

    storeAppendPrintf(sentry, "client_http.requests = %f/sec\n",