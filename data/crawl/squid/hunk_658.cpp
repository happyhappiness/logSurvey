     else if (p->connection_auth == 2)
         storeAppendPrintf(sentry, " connection-auth=auto");
 
+    p->secure.dumpCfg(sentry,"tls-");
     storeAppendPrintf(sentry, "\n");
 }
 
