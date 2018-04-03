                 }
             }
         } else {
-            credentials(Failed);
+            auth_user->credentials(AuthUser::Failed);
             digest_request->flags.invalid_password = 1;
             digest_request->setDenyMessage("Incorrect password");
             return;
