     for (p = Config.externalAclHelperList; p; p = p->next) {
 	storeAppendPrintf(sentry, "External ACL Statistics: %s\n", p->name);
 	storeAppendPrintf(sentry, "Cache size: %d\n", p->cache->count);
-	helperStats(sentry, p->helper);
+	helperStats(sentry, p->theHelper);
 	storeAppendPrintf(sentry, "\n");
     }
 }
