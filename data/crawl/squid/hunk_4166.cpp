     if (s->vport)
         storeAppendPrintf(e, " vport");
 
+    if (s->connection_auth_disabled)
+        storeAppendPrintf(e, " connection-auth=off");
+    else
+        storeAppendPrintf(e, " connection-auth=on");
+
     if (s->disable_pmtu_discovery != DISABLE_PMTU_OFF) {
         const char *pmtu;
 
