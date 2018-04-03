	method_id = cacheIndexParseMethod(method);
	if (method_id == METHOD_NONE) {
	    /*fprintf(stderr, "%s:%d: invalid method %s in '%s'\n", 
		fname, scanned_count, method, buf);*/
	    continue;
	}
	while (*url) url--;
	url++;
	*hier = '\0';
	hier += 3;
	*strchr(hier, '/') = '\0';
	/*fprintf(stdout, "%s:%d: %s %s %s\n",
	    fname, count, method, url, hier);*/
	count++;
	/* no ICP lookup for these status codes */
	if (!strcmp(hier, "NONE") ||
