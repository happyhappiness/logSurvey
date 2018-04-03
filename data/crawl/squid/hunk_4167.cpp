     /* Filter unproxyable authentication types */
 
     if (http->logType != LOG_TCP_DENIED &&
-	    (hdr->has(HDR_WWW_AUTHENTICATE) || hdr->has(HDR_PROXY_AUTHENTICATE))) {
+            hdr->has(HDR_WWW_AUTHENTICATE)) {
         HttpHeaderPos pos = HttpHeaderInitPos;
         HttpHeaderEntry *e;
 
-        int headers_deleted = 0;
+	int connection_auth_blocked = 0;
         while ((e = hdr->getEntry(&pos))) {
-            if (e->id == HDR_WWW_AUTHENTICATE || e->id == HDR_PROXY_AUTHENTICATE) {
+            if (e->id == HDR_WWW_AUTHENTICATE) {
                 const char *value = e->value.buf();
 
                 if ((strncasecmp(value, "NTLM", 4) == 0 &&
                         (value[4] == '\0' || value[4] == ' '))
                         ||
                         (strncasecmp(value, "Negotiate", 9) == 0 &&
-                         (value[9] == '\0' || value[9] == ' ')))
-                            hdr->delAt(pos, headers_deleted);
+                         (value[9] == '\0' || value[9] == ' '))
+		        ||
+		        (strncasecmp(value, "Kerberos", 8) == 0 &&
+                         (value[8] == '\0' || value[8] == ' ')))
+		{
+		    if (request->flags.connection_auth_disabled) {
+			hdr->delAt(pos, connection_auth_blocked);
+                        continue;
+                    }
+		    request->flags.must_keepalive = 1;
+		    if (!request->flags.accelerated && !request->flags.intercepted) {
+                        httpHeaderPutStrf(hdr, HDR_PROXY_SUPPORT, "Session-Based-Authentication");
+			/*
+			  We send "[Proxy-]Connection: Proxy-Support" header to mark
+			  Proxy-Support as a hop-by-hop header for intermediaries that do not
+			  understand the semantics of this header. The RFC should have included
+			  this recommendation.
+			*/
+                        httpHeaderPutStrf(hdr, HDR_CONNECTION, "Proxy-support");
+                    }
+                    break;
+		}
             }
         }
-        if (headers_deleted)
+
+        if (connection_auth_blocked)
             hdr->refreshMask();
     }
 
