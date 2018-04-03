 
     cputime = rusage_cputime(&rusage);
 
-    storeAppendPrintf(sentry, "Resource usage for %s:\n", appname);
+    storeAppendPrintf(sentry, "Resource usage for %s:\n", APP_SHORTNAME);
 
     storeAppendPrintf(sentry, "\tUP Time:\t%.3f seconds\n", runtime);
 
