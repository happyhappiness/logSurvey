 }
 
 static void
-dump_PortCfg(StoreEntry * e, const char *n, const AnyP::PortCfg * s)
+dump_PortCfg(StoreEntry * e, const char *n, const AnyP::PortCfgPointer &s)
 {
-    while (s) {
-        dump_generic_port(e, n, s);
+    for (AnyP::PortCfgPointer p = s; p != NULL; p = p->next) {
+        dump_generic_port(e, n, p);
         storeAppendPrintf(e, "\n");
-        s = s->next;
-    }
-}
-
-static void
-free_PortCfg(AnyP::PortCfg ** head)
-{
-    AnyP::PortCfg *s;
-
-    while ((s = *head) != NULL) {
-        *head = s->next;
-        cbdataReferenceDone(s);
     }
 }
 
