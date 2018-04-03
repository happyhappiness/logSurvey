 
 #if USE_SSL
     if (s->sslBump)
-        storeAppendPrintf(e, " sslBump");
+        storeAppendPrintf(e, " ssl-bump");
 
     if (s->cert)
         storeAppendPrintf(e, " cert=%s", s->cert);