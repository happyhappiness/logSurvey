 static void
 dump_generic_http_port(StoreEntry * e, const char *n, const http_port_list * s)
 {
-    storeAppendPrintf(e, "%s %s:%d",
+    char buf[MAX_IPSTRLEN];
+
+    storeAppendPrintf(e, "%s %s",
                       n,
-                      inet_ntoa(s->s.sin_addr),
-                      ntohs(s->s.sin_port));
+                      s->s.ToURL(buf,MAX_IPSTRLEN));
 
     if (s->defaultsite)
         storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);
