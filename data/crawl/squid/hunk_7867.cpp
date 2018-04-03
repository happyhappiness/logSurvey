     exit(1);
 }
 
-int main(argc, argv)
+static void mainParseOptions(argc, argv)
      int argc;
-     char **argv;
+     char *argv[];
 {
-    int c;
-    int malloc_debug_level = 0;
     extern char *optarg;
-    int errcount = 0;
-    static int neighbors = 0;
-    char *s = NULL;
-    int n;			/* # of GC'd objects */
-    time_t last_maintain = 0;
-
-    errorInitialize();
-
-    cached_starttime = getCurrentTime();
-    failure_notify = fatal_dump;
-
-    setMaxFD();
-
-    for (n = getMaxFD(); n > 2; n--)
-	close(n);
-
-#if HAVE_MALLOPT
-    /* set malloc option */
-    /* use small block algorithm for faster allocation */
-    /* grain of small block */
-    mallopt(M_GRAIN, 16);
-    /* biggest size that is considered a small block */
-    mallopt(M_MXFAST, 4096);
-    /* number of holding small block */
-    mallopt(M_NLBLKS, 100);
-#endif
-
-    /*init comm module */
-    comm_init();
-
-    /* we have to init fdstat here. */
-    fdstat_init(PREOPEN_FD);
-    fdstat_open(0, LOG);
-    fdstat_open(1, LOG);
-    fdstat_open(2, LOG);
-    fd_note(0, "STDIN");
-    fd_note(1, "STDOUT");
-    fd_note(2, "STDERR");
-
-    if ((s = getenv("HARVEST_HOME")) != NULL) {
-	config_file = (char *) xcalloc(1, strlen(s) + 64);
-	sprintf(config_file, "%s/lib/cached.conf", s);
-    } else {
-	config_file = xstrdup("/usr/local/harvest/lib/cached.conf");
-    }
-
-    /* enable syslog by default */
-    syslog_enable = 0;
-    /* preinit for debug module */
-    debug_log = stderr;
-    hash_init(0);
+    int c;
 
-    while ((c = getopt(argc, argv, "vCDRVbsif:a:p:u:m:zh?")) != -1)
+    while ((c = getopt(argc, argv, "vCDRVbsif:a:p:u:m:zh?")) != -1) {
 	switch (c) {
 	case 'v':
 	    printf("Harvest Cache: Version %s\n", SQUID_VERSION);
