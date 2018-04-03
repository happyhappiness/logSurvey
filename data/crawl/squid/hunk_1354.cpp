     bool concurrentRequestQueueFilled() const;
 
     /* PROXY protocol functionality */
-    void proxyProtocolValidateClient();
+    bool proxyProtocolValidateClient();
     bool parseProxyProtocolMagic();
     bool proxyProtocolError(bool isFatal);
 