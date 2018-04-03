         assert(!parseErr);
 
         if (!connectRespBuf->hasSpace()) {
-            informUserOfPeerError("huge CONNECT response from peer");
+            informUserOfPeerError("huge CONNECT response from peer", 0);
             return;
         }
 
