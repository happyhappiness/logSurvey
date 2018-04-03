 
     assert(pd);
 
-    const char *host = pd->host.c_str();
+    const char *host = pd->host.buf();
     storeAppendPrintf(e, "\npeer digest from %s\n", host);
 
     cacheDigestGuessStatsReport(&pd->stats.guess, e, host);
