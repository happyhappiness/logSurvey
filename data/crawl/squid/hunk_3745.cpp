     if (auth_user_request->denyMessage())
         str.Printf("Auth ErrMsg: %s\r\n", auth_user_request->denyMessage());
 
-    if (dnsserver_msg) {
-        str.Printf("DNS Server ErrMsg: %s\r\n", dnsserver_msg);
-    }
+    if (dnsError.size() > 0)
+        str.Printf("DNS ErrMsg: %s\r\n", dnsError.termedBuf());
 
     /* - TimeStamp */
     str.Printf("TimeStamp: %s\r\n\r\n", mkrfc1123(squid_curtime));
