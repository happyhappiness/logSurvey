 
     if (s->tcp_keepalive.enabled) {
         if (s->tcp_keepalive.idle || s->tcp_keepalive.interval || s->tcp_keepalive.timeout) {
-            storeAppendPrintf(e, " tcp_keepalive=%d,%d,%d", s->tcp_keepalive.idle, s->tcp_keepalive.interval, s->tcp_keepalive.timeout);
+            storeAppendPrintf(e, " tcpkeepalive=%d,%d,%d", s->tcp_keepalive.idle, s->tcp_keepalive.interval, s->tcp_keepalive.timeout);
         } else {
-            storeAppendPrintf(e, " tcp_keepalive");
+            storeAppendPrintf(e, " tcpkeepalive");
         }
     }
 
