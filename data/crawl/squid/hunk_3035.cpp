 HttpStateData::handleRequestBodyProducerAborted()
 {
     ServerStateData::handleRequestBodyProducerAborted();
-    // XXX: SendComplete(COMM_ERR_CLOSING) does little. Is it enough?
-    CommIoCbParams io(NULL);
-    io.fd=fd;
-    io.flag=COMM_ERR_CLOSING;
-    sendComplete(io);
+    abortTransaction("request body producer aborted");
 }
 
 // called when we wrote request headers(!) or a part of the body
