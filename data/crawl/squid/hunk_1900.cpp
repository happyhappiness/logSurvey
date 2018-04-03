          * Authenticate NTLM start.
          * If after a KK deny the user's request w/ 407 and mark the helper as
          * Needing YR. */
-        Note::Pointer errNote = reply.responseKeys.findByName("message");
+        Note::Pointer errNote = reply.notes.find("message");
         if (reply.result == HelperReply::Unknown)
             auth_user_request->denyMessage("Internal Error");
         else if (errNote != NULL)
-            auth_user_request->denyMessage(errNote->values[0]->value.termedBuf());
+            auth_user_request->denyMessage(errNote->firstValue());
         else
             auth_user_request->denyMessage("NTLM Authentication failed with no reason given");
         auth_user_request->user()->credentials(Auth::Failed);
