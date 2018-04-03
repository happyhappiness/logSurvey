     if (p->options.allow_miss)
         storeAppendPrintf(sentry, " allow-miss");
 
+    if (p->options.no_tproxy)
+        storeAppendPrintf(sentry, " no-tproxy");
+
     if (p->max_conn > 0)
         storeAppendPrintf(sentry, " max-conn=%d", p->max_conn);
 
