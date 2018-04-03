         safe_free(lm_request->server_blob);
         lm_request->request->flags.mustKeepalive = 1;
         if (lm_request->request->flags.proxyKeepalive) {
-            Note::Pointer serverBlob = reply.responseKeys.findByName("token");
-            lm_request->server_blob = xstrdup(serverBlob->values[0]->value.termedBuf());
+            Note::Pointer serverBlob = reply.notes.find("token");
+            lm_request->server_blob = xstrdup(serverBlob->firstValue());
             auth_user_request->user()->credentials(Auth::Handshake);
             auth_user_request->denyMessage("Authentication in progress");
-            debugs(29, 4, HERE << "Need to challenge the client with a server token: '" << serverBlob->values[0]->value << "'");
+            debugs(29, 4, HERE << "Need to challenge the client with a server token: '" << serverBlob->firstValue() << "'");
         } else {
             auth_user_request->user()->credentials(Auth::Failed);
             auth_user_request->denyMessage("NTLM authentication requires a persistent connection");
