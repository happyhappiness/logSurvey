         }
     }
 
+    // add Warnings required by RFC 2616 if serving a stale hit
+    if (http->request->flags.stale_if_hit && logTypeIsATcpHit(http->logType)) {
+        hdr->putWarning(110, "Response is stale");
+        if (http->request->flags.need_validation)
+            hdr->putWarning(111, "Revalidation failed");
+    }
+
     /* Filter unproxyable authentication types */
 
     if (http->logType != LOG_TCP_DENIED &&
