                                RequestMethodStr(METHOD_GET), digest_request->uri, HA2, Response);
 
             if (strcasecmp(digest_request->response, Response)) {
-                credentials(Failed);
+                auth_user->credentials(AuthUser::Failed);
                 digest_request->flags.invalid_password = 1;
                 digest_request->setDenyMessage("Incorrect password");
                 return;
