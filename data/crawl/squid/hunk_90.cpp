          * Authenticate Negotiate start.
          * If after a KK deny the user's request w/ 407 and mark the helper as
          * Needing YR. */
-        const char *errNote = reply.notes.find("message");
+        SBuf errNote;
         if (reply.result == Helper::Unknown)
             auth_user_request->denyMessage("Internal Error");
-        else if (errNote != NULL)
-            auth_user_request->denyMessage(errNote);
+        else if (reply.notes.find(errNote, "message"))
+            auth_user_request->denyMessage(errNote.c_str());
         else
             auth_user_request->denyMessage("Negotiate Authentication failed with no reason given");
         auth_user_request->user()->credentials(Auth::Failed);
