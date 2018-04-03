     strFwd = hdr_in->getList(HDR_X_FORWARDED_FOR);
 
     /** \pre Handle X-Forwarded-For */
-    if(strcmp(opt_forwarded_for, "delete") != 0) {
-        if(strcmp(opt_forwarded_for, "on") == 0) {
+    if (strcmp(opt_forwarded_for, "delete") != 0) {
+        if (strcmp(opt_forwarded_for, "on") == 0) {
             /** If set to ON - append client IP or 'unknown'. */
             strFwd = hdr_in->getList(HDR_X_FORWARDED_FOR);
-            if( orig_request->client_addr.IsNoAddr() )
+            if ( orig_request->client_addr.IsNoAddr() )
                 strListAdd(&strFwd, "unknown", ',');
             else
                 strListAdd(&strFwd, orig_request->client_addr.NtoA(ntoabuf, MAX_IPSTRLEN), ',');
-        } else if(strcmp(opt_forwarded_for, "off") == 0) {
+        } else if (strcmp(opt_forwarded_for, "off") == 0) {
             /** If set to OFF - append 'unknown'. */
             strFwd = hdr_in->getList(HDR_X_FORWARDED_FOR);
             strListAdd(&strFwd, "unknown", ',');
-        } else if(strcmp(opt_forwarded_for, "transparent") == 0) {
+        } else if (strcmp(opt_forwarded_for, "transparent") == 0) {
             /** If set to TRANSPARENT - pass through unchanged. */
             strFwd = hdr_in->getList(HDR_X_FORWARDED_FOR);
-        } else if(strcmp(opt_forwarded_for, "truncate") == 0) {
+        } else if (strcmp(opt_forwarded_for, "truncate") == 0) {
             /** If set to TRUNCATE - drop existing list and replace with client IP or 'unknown'. */
-            if( orig_request->client_addr.IsNoAddr() )
+            if ( orig_request->client_addr.IsNoAddr() )
                 strFwd = "unknown";
             else
                 strFwd = orig_request->client_addr.NtoA(ntoabuf, MAX_IPSTRLEN);
         }
-        if(strFwd.size() > 0)
+        if (strFwd.size() > 0)
             hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.buf());
     }
     /** If set to DELETE - do not copy through. */
