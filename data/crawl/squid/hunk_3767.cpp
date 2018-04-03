     if (p->connect_timeout > 0)
         storeAppendPrintf(sentry, " connect-timeout=%d", (int) p->connect_timeout);
 
+    if (p->connect_fail_limit != PEER_TCP_MAGIC_COUNT)
+        storeAppendPrintf(sentry, " connect-fail-limit=%d", p->connect_fail_limit);
+
 #if USE_CACHE_DIGESTS
 
     if (p->digest_url)
