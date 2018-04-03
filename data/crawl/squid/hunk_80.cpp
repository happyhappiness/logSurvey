     break;
 
     case Helper::Error: {
-        const char *tokenNote = reply.notes.findFirst("token");
-
-        SBuf messageNote;
         /* authentication failure (wrong password, etc.) */
-        if (reply.notes.find(messageNote, "message"))
-            auth_user_request->denyMessage(messageNote.c_str());
-        else
-            auth_user_request->denyMessage("Negotiate Authentication denied with no reason given");
+        auth_user_request->denyMessageFromHelper("Negotiate", reply);
         auth_user_request->user()->credentials(Auth::Failed);
         safe_free(lm_request->server_blob);
-        if (tokenNote != NULL)
+        if (const char *tokenNote = reply.notes.findFirst("token"))
             lm_request->server_blob = xstrdup(tokenNote);
         lm_request->releaseAuthServer();
         debugs(29, 4, "Failed validating user via Negotiate. Result: " << reply);
