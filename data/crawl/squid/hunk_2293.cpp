     char clientip[MAX_IPSTRLEN];
     al->getLogClientIp(clientip, MAX_IPSTRLEN);
 
-    logfilePrintf(logfile, "%s %s %s [%s] \"%s %s %s/%d.%d\" %d %"PRId64" %s%s:%s%s",
+    logfilePrintf(logfile, "%s %s %s [%s] \"%s %s %s/%d.%d\" %d %" PRId64 " %s%s:%s%s",
                   clientip,
                   user_ident ? user_ident : dash_str,
                   user_auth ? user_auth : dash_str,
