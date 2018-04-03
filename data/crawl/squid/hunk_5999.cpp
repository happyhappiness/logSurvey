 {
     static int started_clean_event = 0;
     static const char *errmsg =
-    "\tFailed to verify one of the swap directories, Check cache.log\n"
-    "\tfor details.  Run 'squid -z' to create swap directories\n"
-    "\tif needed, or if running Squid for the first time.";
+	"\tFailed to verify one of the swap directories, Check cache.log\n"
+	"\tfor details.  Run 'squid -z' to create swap directories\n"
+	"\tif needed, or if running Squid for the first time.";
     storeAufsDirInitBitmap(sd);
     if (storeAufsDirVerifyCacheDirs(sd) < 0)
 	fatal(errmsg);
