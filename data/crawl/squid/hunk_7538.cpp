     storeAppendPrintf(sentry, close_bracket);
 }
 
-static int dummy_handler(u1, u2, u3)
-     int u1;
-     struct hostent *u2;
-     void *u3;
+static int
+dummy_handler(int u1, struct hostent *u2, void *u3)
 {
     return 0;
 }
 
-static int ipcacheHasPending(i)
-     ipcache_entry *i;
+static int
+ipcacheHasPending(ipcache_entry * i)
 {
     struct _ip_pending *p = NULL;
     if (i->status != IP_PENDING)
