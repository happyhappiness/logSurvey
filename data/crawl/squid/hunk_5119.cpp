         fatal ("request being destroyed with body connection intact\n");
 
     if (req->auth_user_request)
-        authenticateAuthUserRequestUnlock(req->auth_user_request);
+        req->auth_user_request->unlock();
 
     safe_free(req->canonical);
 
