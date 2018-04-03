 
     assert(pd);
 
-    const char *host = pd->host.unsafeBuf();
+    const char *host = pd->host.termedBuf();
     storeAppendPrintf(e, "\npeer digest from %s\n", host);
 
     cacheDigestGuessStatsReport(&pd->stats.guess, e, host);
