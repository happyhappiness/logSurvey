 #endif
 #endif
 
-    while ((c = getopt(argc, argv, "vhdD")) != -1) {
+    while ((c = getopt(argc, argv, "Ddhs:v")) != -1) {
 	switch (c) {
-	case 'v':
-	    printf("dnsserver version %s\n", SQUID_VERSION);
-	    exit(0);
-	    break;
-	case 'd':
-	    snprintf(buf, 256, "dnsserver.%d.log", (int) getpid());
-	    logfile = fopen(buf, "a");
-	    do_debug++;
-	    if (!logfile)
-		fprintf(stderr, "Could not open dnsserver's log file\n");
-	    break;
 	case 'D':
 #ifdef RES_DEFNAMES
 	    _res.options |= RES_DEFNAMES;
