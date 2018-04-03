         /* check for stale nonce */
         if (!authDigestNonceIsValid(digest_request->nonce, digest_request->nc)) {
             debugs(29, 3, "authenticateDigestAuthenticateuser: user '" << auth_user->username() << "' validated OK but nonce stale");
-            credentials(Failed);
+            auth_user->credentials(AuthUser::Failed);
             digest_request->setDenyMessage("Stale nonce");
             return;
         }
     }
 
-    credentials(Ok);
+    auth_user->credentials(AuthUser::Ok);
 
     /* password was checked and did match */
     debugs(29, 4, "authenticateDigestAuthenticateuser: user '" << auth_user->username() << "' validated OK");
