         assert(!parseErr);
 
         if (!connectRespBuf->hasSpace()) {
-            server.logicError("huge CONNECT response from peer");
+            informUserOfPeerError("huge CONNECT response from peer");
             return;
         }
 
