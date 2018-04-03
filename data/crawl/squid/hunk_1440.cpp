     void completed();
     void retryOrBail();
     ErrorState *makeConnectingError(const err_type type) const;
+#if USE_OPENSSL
+    void connectedToPeer(Ssl::PeerConnectorAnswer &answer);
+#endif
     static void RegisterWithCacheManager(void);
 
+    /// stops monitoring server connection for closure and updates pconn stats
+    void closeServerConnection(const char *reason);
+
 public:
     StoreEntry *entry;
     HttpRequest *request;
