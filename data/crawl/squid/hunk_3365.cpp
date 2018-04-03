     fatal ("AuthUserRequest child failed to override operator delete\n");
 }
 
-AuthUserRequest::AuthUserRequest():_auth_user(NULL), message(NULL),
-        lastReply (AUTH_ACL_CANNOT_AUTHENTICATE)
+AuthUserRequest::AuthUserRequest():
+        _auth_user(NULL),
+        message(NULL),
+        lastReply(AUTH_ACL_CANNOT_AUTHENTICATE)
 {
     debugs(29, 5, "AuthUserRequest::AuthUserRequest: initialised request " << this);
 }
