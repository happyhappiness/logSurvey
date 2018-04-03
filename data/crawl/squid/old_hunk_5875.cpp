    /* we can avoid memcpy-ing, and just reuse argv[] */
    for (j = optind; j < argc; j++) {
	char *d, *c;
	d = argv[j];
	if (NULL == (c = strchr(d, '\\')) && NULL == (c = strchr(d, '/'))) {
	    fprintf(stderr, "Couldn't grok domain-controller %s\n", d);
	    continue;
	}
	*c++ = '\0';
	new_dc = (dc *) malloc(sizeof(dc));
	if (!new_dc) {
	    fprintf(stderr, "Malloc error while parsing DC options\n");
	    continue;
	}
	/* capitalize */
