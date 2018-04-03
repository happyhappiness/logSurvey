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
+        debugs(80, DBG_CRITICAL, "wccp2_*_method: missing setting.");
+        self_destruct();
+    }
+
+    /* update configuration if its valid */
+    if (strcmp(t, "gre") == 0 || strcmp(t, "1") == 0) {
+        *method = WCCP2_METHOD_GRE;
+    } else if (strcmp(t, "l2") == 0 || strcmp(t, "2") == 0) {
+        *method = WCCP2_METHOD_L2;
+    } else {
+        debugs(80, DBG_CRITICAL, "wccp2_*_method: unknown setting, got " << t );
+        self_destruct();
+    }
+}
+
+void
+dump_wccp2_method(StoreEntry * e, const char *label, int v)
+{
+    switch(v)
+    {
+    case WCCP2_METHOD_GRE:
+        storeAppendPrintf(e, "%s gre\n", label);
+        break;
+    case WCCP2_METHOD_L2:
+        storeAppendPrintf(e, "%s l2\n", label);
+        break;
+    default:
+        debugs(80, DBG_CRITICAL, "FATAL: WCCPv2 configured method (" << v << ") is not valid.");
+        self_destruct();
+    }
+}
+
+void
+free_wccp2_method(int *v)
+{ }
+
+/**
+ * Parse wccp2_assignment_method option
+ * they can be '1' aka 'hash' or  '2' aka 'mask'
+ * repesenting the integer numeric of the same.
+ */
+void
+parse_wccp2_amethod(int *method)
+{
+    char *t;
+
+    /* Snarf the method */
+    if ((t = strtok(NULL, w_space)) == NULL) {
+        debugs(80, DBG_CRITICAL, "wccp2_assignment_method: missing setting.");
+        self_destruct();
+    }
+
+    /* update configuration if its valid */
+    if (strcmp(t, "hash") == 0 || strcmp(t, "1") == 0) {
+        *method = WCCP2_ASSIGNMENT_METHOD_HASH;
+    } else if (strcmp(t, "mask") == 0 || strcmp(t, "2") == 0) {
+        *method = WCCP2_ASSIGNMENT_METHOD_MASK;
+    } else {
+        debugs(80, DBG_CRITICAL, "wccp2_assignment_method: unknown setting, got " << t );
+        self_destruct();
+    }
+}
+
+void
+dump_wccp2_amethod(StoreEntry * e, const char *label, int v)
+{
+    switch(v)
+    {
+    case WCCP2_ASSIGNMENT_METHOD_HASH:
+        storeAppendPrintf(e, "%s hash\n", label);
+        break;
+    case WCCP2_ASSIGNMENT_METHOD_MASK:
+        storeAppendPrintf(e, "%s mask\n", label);
+        break;
+    default:
+        debugs(80, DBG_CRITICAL, "FATAL: WCCPv2 configured " << label << " (" << v << ") is not valid.");
+        self_destruct();
+    }
+}
+
+void
+free_wccp2_amethod(int *v)
+{ }
+
 /*
  * Format:
  *