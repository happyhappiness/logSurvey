 
     const SBuf method(al->getLogMethod());
 
-    logfilePrintf(logfile, "%s %s %s [%s] \"" SQUIDSBUFPH " %s %s/%d.%d\" %d %" PRId64 " %s:%s%s",
+    logfilePrintf(logfile, "%s %s %s [%s] \"" SQUIDSBUFPH " " SQUIDSBUFPH " %s/%d.%d\" %d %" PRId64 " %s:%s%s",
                   clientip,
                   user_ident ? user_ident : dash_str,
                   user_auth ? user_auth : dash_str,
                   Time::FormatHttpd(squid_curtime),
                   SQUIDSBUFPRINT(method),
-                  al->url,
+                  SQUIDSBUFPRINT(al->url),
                   AnyP::ProtocolType_str[al->http.version.protocol],
                   al->http.version.major, al->http.version.minor,
                   al->http.code,
