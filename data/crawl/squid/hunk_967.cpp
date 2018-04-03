 
     str.reset();
     /* email subject line */
-    str.Printf("CacheErrorInfo - %s", errorPageName(type));
-    mb->Printf("?subject=%s", rfc1738_escape_part(str.buf));
+    str.appendf("CacheErrorInfo - %s", errorPageName(type));
+    mb->appendf("?subject=%s", rfc1738_escape_part(str.buf));
     str.reset();
     /* email body */
-    str.Printf("CacheHost: %s\r\n", getMyHostname());
+    str.appendf("CacheHost: %s\r\n", getMyHostname());
     /* - Err Msgs */
-    str.Printf("ErrPage: %s\r\n", errorPageName(type));
+    str.appendf("ErrPage: %s\r\n", errorPageName(type));
 
     if (xerrno) {
-        str.Printf("Err: (%d) %s\r\n", xerrno, strerror(xerrno));
+        str.appendf("Err: (%d) %s\r\n", xerrno, strerror(xerrno));
     } else {
-        str.Printf("Err: [none]\r\n");
+        str.append("Err: [none]\r\n", 13);
     }
 #if USE_AUTH
     if (auth_user_request.getRaw() && auth_user_request->denyMessage())
-        str.Printf("Auth ErrMsg: %s\r\n", auth_user_request->denyMessage());
+        str.appendf("Auth ErrMsg: %s\r\n", auth_user_request->denyMessage());
 #endif
     if (dnsError.size() > 0)
-        str.Printf("DNS ErrMsg: %s\r\n", dnsError.termedBuf());
+        str.appendf("DNS ErrMsg: %s\r\n", dnsError.termedBuf());
 
     /* - TimeStamp */
-    str.Printf("TimeStamp: %s\r\n\r\n", mkrfc1123(squid_curtime));
+    str.appendf("TimeStamp: %s\r\n\r\n", mkrfc1123(squid_curtime));
 
     /* - IP stuff */
-    str.Printf("ClientIP: %s\r\n", src_addr.toStr(ntoabuf,MAX_IPSTRLEN));
+    str.appendf("ClientIP: %s\r\n", src_addr.toStr(ntoabuf,MAX_IPSTRLEN));
 
     if (request && request->hier.host[0] != '\0') {
-        str.Printf("ServerIP: %s\r\n", request->hier.host);
+        str.appendf("ServerIP: %s\r\n", request->hier.host);
     }
 
-    str.Printf("\r\n");
+    str.append("\r\n", 2);
     /* - HTTP stuff */
-    str.Printf("HTTP Request:\r\n");
+    str.append("HTTP Request:\r\n", 15);
 
     if (NULL != request) {
         String urlpath_or_slash;
