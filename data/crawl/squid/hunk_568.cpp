     const bool parsed = rep.parse(connectRespBuf->content(), connectRespBuf->contentSize(), eof, &parseErr);
     if (!parsed) {
         if (parseErr > 0) { // unrecoverable parsing error
-            informUserOfPeerError("malformed CONNECT response from peer");
+            informUserOfPeerError("malformed CONNECT response from peer", 0);
             return;
         }
 
