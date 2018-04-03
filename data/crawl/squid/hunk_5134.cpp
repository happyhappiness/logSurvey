     clientHttpRequest *http = context->http;
     err_type page_id;
     http_status status;
-    char const *proxy_auth_msg = NULL;
     debug(85, 2) ("The request %s %s is %s, because it matched '%s'\n",
                   RequestMethodStr[http->request->method], http->uri,
                   answer == ACCESS_ALLOWED ? "ALLOWED" : "DENIED",
                   AclMatchedName ? AclMatchedName : "NO ACL's");
-    proxy_auth_msg = authenticateAuthUserRequestMessage((http->getConn().getRaw() != NULL
-                     && http->getConn()->auth_user_request) ? http->getConn()->
-                     auth_user_request : http->request->auth_user_request);
+    char const *proxy_auth_msg = "<null>";
+
+    if (http->getConn().getRaw() != NULL && http->getConn()->auth_user_request != NULL)
+        proxy_auth_msg = http->getConn()->auth_user_request->denyMessage("<null>");
+    else if (http->request->auth_user_request != NULL)
+        proxy_auth_msg = http->request->auth_user_request->denyMessage("<null>");
 
     if (answer == ACCESS_ALLOWED) {
         safe_free(http->uri);
