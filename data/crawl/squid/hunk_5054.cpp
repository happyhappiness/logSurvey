                           digest_user->username());
             digest_request->flags.nonce_stale = 1;
             credentials(Failed);
+            digest_request->setDenyMessage("Stale nonce");
             return;
         }
     }
