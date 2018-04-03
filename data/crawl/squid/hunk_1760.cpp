         digest_request->user()->credentials(Auth::Failed);
         digest_request->flags.invalid_password = true;
 
-        Note::Pointer msgNote = reply.notes.find("message");
+        const char *msgNote = reply.notes.find("message");
         if (msgNote != NULL) {
-            digest_request->setDenyMessage(msgNote->firstValue());
+            digest_request->setDenyMessage(msgNote);
         } else if (reply.other().hasContent()) {
             // old helpers did send ERR result but a bare message string instead of message= key name.
             digest_request->setDenyMessage(reply.other().content());
