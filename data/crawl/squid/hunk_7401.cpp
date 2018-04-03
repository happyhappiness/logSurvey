 	NRedirectors);
     storeAppendPrintf(sentry, "{use histogram:}\n");
     for (k = 0; k < NRedirectors; k++) {
-	storeAppendPrintf(sentry, "{    redirector #%d: %d}\n",
+	storeAppendPrintf(sentry, "{    redirector #%d: %d (%d rewrites)}\n",
 	    k + 1,
-	    RedirectStats.use_hist[k]);
+	    RedirectStats.use_hist[k],
+	    RedirectStats.rewrites[k]);
     }
     storeAppendPrintf(sentry, close_bracket);
 }