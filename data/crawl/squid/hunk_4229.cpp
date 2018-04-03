     return 0;
 }
 
+static ssize_t
+htcpBuildClrOpData(char *buf, size_t buflen, htcpStuff * stuff)
+{
+    u_short reason;
+    
+    switch (stuff->rr) {
+    case RR_REQUEST:
+        debugs(31, 3, "htcpBuildClrOpData: RR_REQUEST");
+        reason = htons((u_short)stuff->reason);
+        xmemcpy(buf, &reason, 2);
+        return htcpBuildSpecifier(buf + 2, buflen - 2, stuff) + 2;
+    case RR_RESPONSE:
+        break;
+    default:
+        fatal_dump("htcpBuildClrOpData: bad RR value");
+    }
+    
+    return 0;
+}
+
 static ssize_t
 htcpBuildOpData(char *buf, size_t buflen, htcpStuff * stuff)
 {
