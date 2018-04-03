         memBufPrintf(&str, "Err: [none]\r\n");
     }
 
-    if (authenticateAuthUserRequestMessage(err->auth_user_request)) {
-        memBufPrintf(&str, "extAuth ErrMsg: %s\r\n", authenticateAuthUserRequestMessage(err->auth_user_request));
-    }
+    if (err->auth_user_request->denyMessage())
+        memBufPrintf(&str, "Auth ErrMsg: %s\r\n", err->auth_user_request->denyMessage());
 
     if (err->dnsserver_msg) {
         memBufPrintf(&str, "DNS Server ErrMsg: %s\r\n", err->dnsserver_msg);
