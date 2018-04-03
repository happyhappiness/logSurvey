 void
 helperStats(StoreEntry * sentry, helper * hlp)
 {
-    helper_server *srv;
     dlink_node *link;
-    double tt;
     storeAppendPrintf(sentry, "program: %s\n",
                       hlp->cmdline->key);
     storeAppendPrintf(sentry, "number running: %d of %d\n",
