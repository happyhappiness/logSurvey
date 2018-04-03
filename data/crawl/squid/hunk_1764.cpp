          * Authenticate Negotiate start.
          * If after a KK deny the user's request w/ 407 and mark the helper as
          * Needing YR. */
-        Note::Pointer errNote = reply.notes.find("message");
+        const char *errNote = reply.notes.find("message");
         if (reply.result == HelperReply::Unknown)
             auth_user_request->denyMessage("Internal Error");
         else if (errNote != NULL)
-            auth_user_request->denyMessage(errNote->firstValue());
+            auth_user_request->denyMessage(errNote);
         else
             auth_user_request->denyMessage("Negotiate Authentication failed with no reason given");
         auth_user_request->user()->credentials(Auth::Failed);
