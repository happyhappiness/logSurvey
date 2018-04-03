     void packRange(StoreIOBuffer const &, MemBuf * mb);
     void deRegisterWithConn();
     void doClose();
-    void initiateClose();
+    void initiateClose(const char *reason);
     bool mayUseConnection_; /* This request may use the connection. Don't read anymore requests for now */
     bool connRegistered_;
 };
 
 
 /* A connection to a socket */
-class ConnStateData : public RefCountable
+class ConnStateData : public BodyProducer, public RefCountable
 {
 
 public:
