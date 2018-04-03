     /// if it is waiting for Squid CONNECT response, closing connections.
     void informUserOfPeerError(const char *errMsg, size_t);
 
+    /// starts connecting to the next hop, either for the first time or while
+    /// recovering from the previous connect failure
+    void startConnecting();
+
     class Connection
     {
 
