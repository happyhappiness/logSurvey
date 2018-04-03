 }
 
 static void
-dump_http_port_list(StoreEntry * e, const char *n, const http_port_list * s)
+dump_PortCfg(StoreEntry * e, const char *n, const AnyP::PortCfg * s)
 {
     while (s) {
-        dump_generic_http_port(e, n, s);
+        dump_generic_port(e, n, s);
         storeAppendPrintf(e, "\n");
         s = s->next;
     }
 }
 
 static void
-free_http_port_list(http_port_list ** head)
+free_PortCfg(AnyP::PortCfg ** head)
 {
-    http_port_list *s;
+    AnyP::PortCfg *s;
 
     while ((s = *head) != NULL) {
         *head = s->next;
