     void clientPinnedConnectionRead(const CommIoCbParams &io);
 
     /// parse input buffer prefix into a single transfer protocol request
+    /// return NULL to request more header bytes (after checking any limits)
+    /// use abortRequestParsing() to handle parsing errors w/o creating request
     virtual ClientSocketContext *parseOneRequest(Http::ProtocolVersion &ver) = 0;
 
     /// start processing a freshly parsed request
