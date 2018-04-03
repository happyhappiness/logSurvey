                  (request->flags.interceptTproxy || request->flags.intercepted));
     }
 
+    /// Sends "502 Bad Gateway" error response to the client,
+    /// if it is waiting for Squid CONNECT response, closing connections.
+    void informUserOfPeerError(const char *errMsg);
+
     class Connection
     {
 
