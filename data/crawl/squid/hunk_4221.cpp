 {
     switch(v)
     {
-    case 1:
-        storeAppendPrintf(e, "%s gre_hash\n", label);
+    case WCCP2_METHOD_GRE:
+        storeAppendPrintf(e, "%s gre\n", label);
         break;
-    case 2:
-        storeAppendPrintf(e, "%s l2_mask\n", label);
+    case WCCP2_METHOD_L2:
+        storeAppendPrintf(e, "%s l2\n", label);
         break;
     default:
         debugs(80, DBG_CRITICAL, "FATAL: WCCPv2 configured method (" << v << ") is not valid.");
