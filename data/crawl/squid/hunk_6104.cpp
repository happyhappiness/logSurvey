 {
     storeAppendPrintf(sentry, "Redirector Statistics:\n");
     helperStats(sentry, redirectors);
+    if (Config.onoff.redirector_bypass)
+	storeAppendPrintf(sentry, "\nNumber of requests bypassed "
+	    "because all redirectors were busy: %d\n", n_bypassed);
 }
 
 /**** PUBLIC FUNCTIONS ****/
