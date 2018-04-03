 
     if (p->max_conn > 0)
         storeAppendPrintf(sentry, " max-conn=%d", p->max_conn);
+    if (p->standby.limit > 0)
+        storeAppendPrintf(sentry, " standby=%d", p->standby.limit);
 
     if (p->options.originserver)
         storeAppendPrintf(sentry, " originserver");
