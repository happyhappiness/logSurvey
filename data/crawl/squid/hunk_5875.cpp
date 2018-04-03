     /* we can avoid memcpy-ing, and just reuse argv[] */
     for (j = optind; j < argc; j++) {
 	char *d, *c;
-	d = argv[j];
+	/* d will not be freed in case of non-error. Since we don't reconfigure,
+	 * it's going to live as long as the process anyways */
+	d = malloc(strlen(argv[j]) + 1);
+	strcpy(d, argv[j]);
+	debug("Adding domain-controller %s\n", d);
 	if (NULL == (c = strchr(d, '\\')) && NULL == (c = strchr(d, '/'))) {
 	    fprintf(stderr, "Couldn't grok domain-controller %s\n", d);
+	    free(d);
+	    continue;
+	}
+	/* more than one delimiter is not allowed */
+	if (NULL != strchr(c + 1, '\\') || NULL != strchr(c + 1, '/')) {
+	    fprintf(stderr, "Broken domain-controller %s\n", d);
+	    free(d);
 	    continue;
 	}
 	*c++ = '\0';
 	new_dc = (dc *) malloc(sizeof(dc));
 	if (!new_dc) {
 	    fprintf(stderr, "Malloc error while parsing DC options\n");
+	    free(d);
 	    continue;
 	}
 	/* capitalize */
