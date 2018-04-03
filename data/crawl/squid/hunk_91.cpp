 
     case Helper::Error: {
         /* authentication failure (wrong password, etc.) */
-        const char *errNote = reply.notes.find("message");
-        if (errNote != NULL)
-            auth_user_request->denyMessage(errNote);
+        SBuf errNote;
+        if (reply.notes.find(errNote, "message"))
+            auth_user_request->denyMessage(errNote.c_str());
         else
             auth_user_request->denyMessage("NTLM Authentication denied with no reason given");
         auth_user_request->user()->credentials(Auth::Failed);
