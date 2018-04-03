                 }
             }
         } else {
-            auth_user->credentials(AuthUser::Failed);
+            auth_user->credentials(Auth::Failed);
             digest_request->flags.invalid_password = 1;
             digest_request->setDenyMessage("Incorrect password");
             return;
