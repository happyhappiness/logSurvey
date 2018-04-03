 
     assert(pd);
 
-    const char *host = pd->host.buf();
+    const char *host = pd->host.unsafeBuf();
     storeAppendPrintf(e, "\npeer digest from %s\n", host);
 
     cacheDigestGuessStatsReport(&pd->stats.guess, e, host);
