	    free(r);
	    noutstanding--;
	}
	if (pconn_fd >= 0 && noutstanding < max_outstanding && !done_reading_urls) {
	    char *t;
	    if (fgets(buf, 8191, stdin) == NULL) {
		fprintf(stderr, "Done Reading URLS\n");
