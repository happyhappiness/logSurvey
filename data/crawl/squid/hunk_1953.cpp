 
     assert(basic_auth != NULL);
 
-    if (reply && (strncasecmp(reply, "OK", 2) == 0))
+    if (reply.result == HelperReply::Okay)
         basic_auth->credentials(Auth::Ok);
     else {
         basic_auth->credentials(Auth::Failed);
 
-        if (t && *t)
-            r->auth_user_request->setDenyMessage(t);
+        if (reply.other().hasContent())
+            r->auth_user_request->setDenyMessage(reply.other().content());
     }
 
     basic_auth->expiretime = squid_curtime;
