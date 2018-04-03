  * Configuration option parsing code
  */
 
+/**
+ * Parse wccp2_return_method and wccp2_forwarding_method options
+ * they can be '1' aka 'gre' or  '2' aka 'l2'
+ * repesenting the integer numeric of the same.
+ */
+void
+parse_wccp2_method(int *method)
+{
+    char *t;
+
+    /* Snarf the method */
+    if ((t = strtok(NULL, w_space)) == NULL) {
+        debugs(80, 0, "wccp2_*_method: missing setting. Expected: gre or l2");
+        self_destruct();
+    }
+
+    /* update configuration if its valid */
+    if (strcmp(t, "gre") == 0 || strcmp(t, "1") == 0) {
+        *method = 1;
+    } else if (strcmp(t, "l2") == 0 || strcmp(t, "2") == 0) {
+        *method = 2;
+    } else {
+        debugs(80, 0, "wccp2_*_method: unknown setting. Expected: gre or l2, (got " << t << ")");
+        self_destruct();
+    }
+}
+
+void
+dump_wccp2_method(StoreEntry * e, const char *label, int v)
+{
+    switch(v)
+    {
+    case 1:
+        storeAppendPrintf(e, "%s gre\n", label);
+        break;
+    case 2:
+        storeAppendPrintf(e, "%s l2\n", label);
+        break;
+    default:
+        debugs(80, DBG_CRITICAL, "FATAL: WCCPv2 confifigured method (" << v << ") is not valid.");
+        self_destruct();
+    }
+}
+
+void
+free_wccp2_method(int *v)
+{ }
+
 /*
  * Format:
  *