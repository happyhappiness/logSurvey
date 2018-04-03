     assert(basic_auth != NULL);
 
     if (reply && (strncasecmp(reply, "OK", 2) == 0))
-        basic_auth->credentials(AuthUser::Ok);
+        basic_auth->credentials(Auth::Ok);
     else {
-        basic_auth->credentials(AuthUser::Failed);
+        basic_auth->credentials(Auth::Failed);
 
         if (t && *t)
             r->auth_user_request->setDenyMessage(t);
