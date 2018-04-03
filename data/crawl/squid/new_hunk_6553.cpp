
	scanned_count++;
	if (!(scanned_count % 50000))
	    fprintf(stderr, "%s scanned %d K entries (%d bad)\n",
		fname, scanned_count / 1000, scanned_count - count - 1);
	if (!url || !hier) {
	    /*fprintf(stderr, "%s:%d: strange access log entry '%s'\n", 
	     * fname, scanned_count, buf); */
	    continue;
	}
	method = url;
