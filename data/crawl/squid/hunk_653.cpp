     else
         method = al->http.method.image();
 
-    logfilePrintf(logfile, "%s %s %s [%s] \"" SQUIDSBUFPH " %s %s/%d.%d\" %d %" PRId64 " \"%s\" \"%s\" %s%s:%s%s",
+    logfilePrintf(logfile, "%s %s %s [%s] \"" SQUIDSBUFPH " %s %s/%d.%d\" %d %" PRId64 " \"%s\" \"%s\" %s:%s%s",
                   clientip,
                   user_ident ? user_ident : dash_str,
                   user_auth ? user_auth : dash_str,
