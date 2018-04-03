     if (r) {
         Adaptation::Icap::History::Pointer h = r->icapHistory();
         if (h != NULL) {
-            if (start)
+            if (doStart)
                 h->start("ICAPModXactLauncher");
             else
                 h->stop("ICAPModXactLauncher");
