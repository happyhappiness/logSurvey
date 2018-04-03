            (answer == ACCESS_ALLOWED ? "ALLOWED" : "DENIED") <<
            ", because it matched '" <<
            (AclMatchedName ? AclMatchedName : "NO ACL's") << "'" );
-    char const *proxy_auth_msg = "<null>";
 
+#if USE_AUTH
+    char const *proxy_auth_msg = "<null>";
     if (http->getConn() != NULL && http->getConn()->auth_user_request != NULL)
         proxy_auth_msg = http->getConn()->auth_user_request->denyMessage("<null>");
     else if (http->request->auth_user_request != NULL)
         proxy_auth_msg = http->request->auth_user_request->denyMessage("<null>");
+#endif
 
     if (answer != ACCESS_ALLOWED) {
         /* Send an error */
         int require_auth = (answer == ACCESS_REQ_PROXY_AUTH || aclIsProxyAuth(AclMatchedName));
         debugs(85, 5, "Access Denied: " << http->uri);
         debugs(85, 5, "AclMatchedName = " << (AclMatchedName ? AclMatchedName : "<null>"));
-
+#if USE_AUTH
         if (require_auth)
             debugs(33, 5, "Proxy Auth Message = " << (proxy_auth_msg ? proxy_auth_msg : "<null>"));
+#endif
 
         /*
          * NOTE: get page_id here, based on AclMatchedName because if
