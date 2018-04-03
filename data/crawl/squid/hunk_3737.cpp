 
     debugs(93, 5, HERE << "have " << readBuf.contentSize() << " body bytes after " <<
            "parse; parsed all: " << parsed);
+    replyBodySize += adapted.body_pipe->buf().contentSize();
 
     // TODO: expose BodyPipe::putSize() to make this check simpler and clearer
-    if (adapted.body_pipe->buf().contentSize() > 0) // parsed something sometime
+    // TODO: do we really need this if we disable when sending headers?
+    if (adapted.body_pipe->buf().contentSize() > 0) { // parsed something sometime
+        disableRepeats("sent adapted content");
         disableBypass("sent adapted content");
+    }
 
     if (parsed) {
         stopParsing();
