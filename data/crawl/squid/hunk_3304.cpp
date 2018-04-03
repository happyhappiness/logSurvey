 
     if (preview.enabled()) {
         buf.Printf("Preview: %d\r\n", (int)preview.ad());
-        if (virginBody.expected()) // there is a body to preview
-            virginBodySending.plan();
-        else
+        if (!virginBody.expected()) // there is no body to preview
             finishNullOrEmptyBodyPreview(httpBuf);
     }
 
-    if (shouldAllow204()) {
-        debugs(93,5, HERE << "will allow 204s outside of preview");
-        state.allowedPostview204 = true;
-        buf.Printf("Allow: 204\r\n");
-        if (virginBody.expected()) // there is a body to echo
-            virginBodySending.plan();
-    }
+    makeAllowHeader(buf);
 
     if (TheConfig.send_client_ip && request) {
         Ip::Address client_addr;
