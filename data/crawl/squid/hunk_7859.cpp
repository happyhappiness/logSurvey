     while ((c = getopt(argc, argv, "vCDRVbsif:a:p:u:m:zh?")) != -1) {
 	switch (c) {
 	case 'v':
-	    printf("Harvest Cache: Version %s\n", SQUID_VERSION);
+	    printf("Harvest Cache: Version %s\n", version_string);
 	    exit(0);
 	    /* NOTREACHED */
 	case 'b':
