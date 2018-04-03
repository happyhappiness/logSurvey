 
         if (e->stats.last_connect_failure) {
             storeAppendPrintf(sentry, "Last failed connect() at: %s\n",
-                              mkhttpdlogtime(&(e->stats.last_connect_failure)));
+                              Time::FormatHttpd(e->stats.last_connect_failure));
         }
 
         if (e->peer_domain != NULL) {
