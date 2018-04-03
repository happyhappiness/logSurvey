     debugs(93, 5, HERE << "have " << readBuf.contentSize() << " body bytes after " <<
            "parse; parsed all: " << parsed);
 
+    // TODO: expose BodyPipe::putSize() to make this check simpler and clearer
+    if (adapted.body_pipe->buf().contentSize() > 0) // parsed something sometime
+        disableBypass("sent adapted content");
+
     if (parsed) {
         stopParsing();
         stopSending(true); // the parser succeeds only if all parsed data fits
