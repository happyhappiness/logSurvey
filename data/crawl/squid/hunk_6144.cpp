 	storeAppendPrintf(s, "\n");
     }
 }
+
+int
+fwdReforwardableStatus(http_status s)
+{
+    switch (s) {
+    case HTTP_FORBIDDEN:
+    case HTTP_INTERNAL_SERVER_ERROR:
+    case HTTP_NOT_IMPLEMENTED:
+    case HTTP_BAD_GATEWAY:
+    case HTTP_SERVICE_UNAVAILABLE:
+    case HTTP_GATEWAY_TIMEOUT:
+	return 1;
+    default:
+	return 0;
+    }
+    /* NOTREACHED */
+}
