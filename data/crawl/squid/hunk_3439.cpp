     LOCAL_ARRAY(char, xname, 128);
 
     while (p != NULL) {
-        storeAppendPrintf(entry, "%s %s %s %d %d",
+        storeAppendPrintf(entry, "%s %s %s %d %d name=%s",
                           name,
                           p->host,
                           neighborTypeStr(p),
                           p->http_port,
-                          p->icp.port);
+                          p->icp.port,
+                          p->name);
         dump_peer_options(entry, p);
 
         for (d = p->peer_domain; d; d = d->next) {