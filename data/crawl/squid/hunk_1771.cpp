 
 #if USE_AUTH
     char const *proxy_auth_msg = "<null>";
-    if (http->getConn() != NULL && http->getConn()->auth_user_request != NULL)
-        proxy_auth_msg = http->getConn()->auth_user_request->denyMessage("<null>");
+    if (http->getConn() != NULL && http->getConn()->getAuth() != NULL)
+        proxy_auth_msg = http->getConn()->getAuth()->denyMessage("<null>");
     else if (http->request->auth_user_request != NULL)
         proxy_auth_msg = http->request->auth_user_request->denyMessage("<null>");
 #endif
