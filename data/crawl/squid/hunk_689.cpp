     for (external_acl *p = Config.externalAclHelperList; p; p = p->next) {
         storeAppendPrintf(sentry, "External ACL Statistics: %s\n", p->name);
         storeAppendPrintf(sentry, "Cache size: %d\n", p->cache->count);
-        helperStats(sentry, p->theHelper);
+        assert(p->theHelper);
+        p->theHelper->packStatsInto(sentry);
         storeAppendPrintf(sentry, "\n");
     }
 }
