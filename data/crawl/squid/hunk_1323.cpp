     char *old_reply;
 
 protected:
+    /* AsyncJob API */
     virtual void start();
 
-    void initReadBuf();
+    /* ServerStateData API */
     virtual void closeServer();
     virtual bool doneWithServer() const;
+    virtual const Comm::ConnectionPointer & dataConnection() const;
+    virtual void abortTransaction(const char *reason);
+
     virtual Http::StatusCode failedHttpStatus(err_type &error);
     void ctrlClosed(const CommCloseCbParams &io);
     void scheduleReadControlReply(int buffered_ok);
