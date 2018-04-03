     /// remove no longer needed leading bytes from the input buffer
     void consumeInput(const size_t byteCount);
 
+    /* TODO: Make the methods below (at least) non-public when possible. */
+
+    /// stop parsing the request and create context for relaying error info
+    ClientSocketContext *abortRequestParsing(const char *const errUri);
+
 protected:
     void startDechunkingRequest();
     void finishDechunkingRequest(bool withSuccess);
