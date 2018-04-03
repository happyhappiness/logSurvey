     virtual void handleRequestBodyProducerAborted();
     virtual bool mayReadVirginReplyBody() const;
     virtual void completeForwarding();
+    virtual bool abortOnData(const char *reason);
 
     /* AsyncJob API */
     virtual void start();
