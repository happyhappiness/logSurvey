 
     /// Sends "502 Bad Gateway" error response to the client,
     /// if it is waiting for Squid CONNECT response, closing connections.
-    void informUserOfPeerError(const char *errMsg);
+    void informUserOfPeerError(const char *errMsg, size_t);
 
     class Connection
     {
